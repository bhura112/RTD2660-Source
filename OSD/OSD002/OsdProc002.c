

#define __OSDPROC002__

#include "Core\Header\Include.h"

#if(_OSD_TYPE == _OSD002)

//--------------------------------------------------
void COsdHandler(void)
{
    bit fPublicFunc = 1;
    bit fTest = 0;

    bOSDTimeOut = 1;

    COsdSystemFlowProc();
    
    COsdEventMsgProc();

    if (_PWOFF_STATE == ucCurrState)
        return;

    // Key Message -> Osd Message
    if(ucCurrState == _ACTIVE_STATE)
        CCoverKeyMsgToOsdEvent(CURRENT_MENU_ITEM.KeyMsgToOsdEvnet,CURRENT_MENU_ITEM.Option & _EN_PUB_KEYEVENT);
    else CCoverKeyMsgToOsdEvent(tKONoSignal, _EN_PUB_KEYEVENT);
    
    // debug info
    //if(ucKeyMessage != _NONE_KEY_MESSAGE)
	//	CUartPrintf("Osd Event:",ucOsdEventMsg);

    // ִ�е�ǰ�˵���˽�д�����
    if(CURRENT_MENU_ITEM.Proc != NULL)
    {
        fPublicFunc = CURRENT_MENU_ITEM.Proc();
    }

    // ִ�й��еĴ�����
    if(fPublicFunc && (CURRENT_MENU_ITEM.Option & _EN_PUB_PROCFUNC))
    {
         CMenuProc();
    }

    if(g_ucPageIndex)
    {
		CTimerActiveTimerEvent(SEC(0.4), CChangePalette);
    }

    if ((ucKeyMessage != _NONE_KEY_MESSAGE) && bOSDTimeOut)
//     && (g_ucPageIndex != _P_SHOW_MUTE))
    {
        if (GET_OSDTIMEOUT() < 5)
        	CTimerCancelTimerEvent(COsdDispOsdTimerEvent);
        else
            CTimerReactiveTimerEvent(SEC(GET_OSDTIMEOUT()), COsdDispOsdTimerEvent);
    }

	DbgShowOSDState();

#if(_SLEEP_FUNC)
    if (!g_ucPageIndex && !bOSDOnScreen)
    {
        if((0xff != ucAutoPowerDownTime) && (0 != _GET_POWER_DOWN_TIME()))
           CShowTimer();
    }
#endif

	if(fTest)
	{
 		CNotUse();
	}

}

//--------------------------------------------------
void DbgShowOSDState(void)
{
    static BYTE ucPageIndexBak = 0;
    static BYTE ucMenuItemIndexBak = 0;

	if(ucPageIndexBak != g_ucPageIndex)
	{
		ucPageIndexBak = g_ucPageIndex;
	}
	if(ucMenuItemIndexBak != g_ucMenuItemIndex)
	{
		ucMenuItemIndexBak = g_ucMenuItemIndex;
	}     
}
//--------------------------------------------------
void CNotUse(void)
{
	CAdjustMZHueSat(0);
	CEepromSaveHueSatData();
//	CIRKeyScan();
	CKeyScanReadyTimerEvent();
	CKeyRepeatEnableTimerEvent();
	CAutoDoAutoConfig();

	CAutoDoWhiteBalance();
//	CEepromGetTvColorSigMode(0,0);
//	CEepromGetTvAudioSigMode(0,0);
//	CEepromSetTvSequentiaCurrLastChn();
//	CEepromGetTvSequentiaCurrLastChn();
	CEepromSaveOsdUserData();
	CEepromSaveBriConData();
	CEepromSaveColorTempData();
	CEepromSaveTvData();
	CScalerWriteAmount(0,0,0,0);
//	CScalerLoadHardwareVLCFont(0,0);

	SetOsdMap(0);
	SetOSDRamAddress();
	DirectWOSDRam(0, 0, 0, 0);
	SetRowCmds();
	Gotoxy(0, 0, 0);
	OutputChar(0);

	COsdFxCloseWindow(0);
	ValueInRangeChange(0, 0, 0, 0);
	SetOSDDouble(0);
	Textout(0);
	StrLen(0);
	OSDPosition(0, 0, 0, 0, 0);
	OSDClear(0, 0, 0, 0, 0,0);
	COsdFxCodeWrite(0);
	COsdFxEnableOsd();
	COsdFxDisableOsd();
	COsdFxDrawWindow(0, 0, 0, 0, 0);
	COsdFxGetAdcClockRange(0);
	InitBurnIn();
	BurnInRun();
    CKeyScanReady();
    ChangeSourceHandler();

	//GetNextLanguage(0);
	//GetPrevLanguage(0);
	//CheckLanguage();
	//FirstLanguage();

    COsdDispOsdTimerEvent();
    CSetPWM(0, 0);
    CTextOutRightAlign(0,0,0);
    OSDSlider(0, 0, 0, 0, 0,0);

     
}
//--------------------------------------------------
void COsdSystemFlowProc(void)
{
    switch(ucCurrState)
    {         
        case _PWOFF_STATE:
            break;
            
        case _INITIAL_STATE:
            break;
            
        case _SEARCH_STATE:
            break;
            
        case _ACTIVE_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {            
             //   g_ucMenuItemIndex = _MENU_NONE;
            	CPowerLedOn();

                if (!bSourceVideo())
                    COsdDispOsdTimerEvent();

                CLR_OSD_READYFORDISPLAY();
                CAdjustBackgroundColor(0x00, 0x00, 0x00);
                
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
                if (_GET_INPUT_SOURCE() != _SOURCE_VIDEO_TV)
#endif
                   CSetVolume();

            }
            
#if(_IF_PLL_DE_CHIP == _IF_PLL_DE_1338)
            CAudioCtrl(); 
#endif
            break;
            
        case _NOSUPPORT_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
        		g_ucMenuItemIndex = _MENU_NOSIGNAL;
                
                //LED_NOSIGNAL();
                CLR_OSD_READYFORDISPLAY();
                if (GET_FIRST_SHOW_NOTE())
                   ucOsdEventMsg = _DO_SHOW_NOTE;
                
                CTimerReactiveTimerEvent(SEC(3), CModeNoSupportEvent);
            }
            
            break;
            
        case _NOSIGNAL_STATE:
            if(GET_OSD_READYFORDISPLAY() == _TRUE)
            {
                g_ucMenuItemIndex = _MENU_NOSIGNAL;

        		// ??? LED_NOSIGNAL();
    
                CLR_OSD_READYFORDISPLAY(); 
    
                if (bSourceVideo())
                   CAdjustBackgroundColor(0x00, 0x00, (bSourceVideo()) ? ((_GET_BLUE_BACKGROUND()) ? 0xFF : 0x00) : 0x00);

                if (GET_FIRST_SHOW_NOTE())
                {
                    ucOsdEventMsg = _DO_SHOW_NOTE;
                    CPowerPanelOn();
                    CPowerLightPowerOn();
                }
    
    			if (_GET_INPUT_SOURCE() == _SOURCE_YPBPR) 
    			{
    				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    				break;
    			}
    
    #if (_HDMI_SUPPORT == _ON)
    			if (_GET_INPUT_SOURCE() == _SOURCE_HDMI) 
    			{
    				CTimerReactiveTimerEvent(SEC(5), CModeNoSignalEvent);
    				break;
    			}		
		        
    #endif
    			// here comes for VGA, DVI input only
    #if(_TMDS_SUPPORT == _ON)
    			if (_GET_INPUT_SOURCE() == _SOURCE_DVI) 
    			{
                    if (bDVICONNECT)
        				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
                    else
    			    	CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    			}		
    #endif


    			if (_GET_INPUT_SOURCE() == _SOURCE_VGA) 
    			{
        			if (bVGACONNECT)
        				CTimerReactiveTimerEvent(SEC(1), CModeNoCableEvent);
        			else       
        				CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);
    	        }

                if (bSourceVideo())
        			CTimerReactiveTimerEvent(SEC(1), CModeNoSignalEvent);

    			CTimerReactiveTimerEvent(SEC(6), CModePowerSavingEvent);

            }
            
            break;
            
        case _SLEEP_STATE:
            break;
            
        default:
            break;
    }
}

//-----------------------------------------------------------
void COsdEventMsgProc(void)
{                  
    if(ucOsdEventMsg > _OE_USER_CMD)
    {
         ucOsdEventMsg = _NONE_MSG;
         return;
    }

    switch(ucOsdEventMsg)
    {
        case _SHOW_NOSIGNAL_MSG:
        case _SHOW_NOCABLE_MSG:
        case _SHOW_NOSUPPORT_MSG:
    		CShowNoSignal();
            break;
            
        case _SAVE_EE_MODEUSERDATA_MSG:
            CEepromSaveModeData(stModeInfo.ModeCurr);
            break;
            
        case _SAVE_EE_SYSTEMDATA_MSG:
            CEepromSaveSystemData();
            break;
            
        case _SAVE_EE_OSDUSERDATA_MSG:
            CEepromSaveOsdUserData();
            break;
            
        case _SAVE_EE_ADCDATA_MSG:
            CEepromSaveAdcData();
            break;
            
        case _SAVE_EE_COLORPROC0_MSG:
            CEepromSaveBriConData();
            break;
            
        case _SAVE_EE_COLORPROC1_MSG:
            CEepromSaveColorTempData();
            break;

        case _SAVE_EE_AUDIO_DATA_MSG:
            CEepromSaveAudioData();
            break;

        case _SAVE_EE_HUE_SAT_DATA_MSG:
            CEepromSaveHueSatData();
            break;

        case _SAVE_EE_TV_DATA_MSG:
            CEepromSaveTvData();
            break;

        case _ENTER_FACTORY_MODE_MSG:
            break;
            
        case _CHANGE_SOURCE_MSG:
            ucTVSyncFailCount = 250;
            CModeResetMode();
        	CLR_SOURCE_AUTOCHANGE();
        	CEepromSaveSystemData();
            CShowNote();
            CPowerPanelOn();
            CPowerLightPowerOn();
            ucCurrState = _SOURCE_CHANGE_STATE; 
            break;
            
        case _DO_AUTO_CONFIG:
            break;   
            
        case _DO_SHOW_NOTE:
            CLR_FIRST_SHOW_NOTE();
            CShowNote();
           // CPowerPanelOn();
         //   CPowerLightPowerOn();
            break;
                  /*
        case _OE_ADJ_BRIGHTNESS_MENU:
    		g_ucPageIndex = _P_SHORT_MENU;
    		g_ucMenuItemIndex = _MI_SMBRIGHT;
    		CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
        	break;  
        case _OE_SC_VOLUME:
    		g_ucPageIndex = _P_SHORT_MENU;
    		g_ucMenuItemIndex = _MI_SMVOLUME;
    		CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
        	break;  */ 
            
        default:
            break;
    }
    
    ucOsdEventMsg = _NONE_MSG;
}



//-----------------------------------------------------------
void COsdDispOsdTimerEvent(void)
{
    COsdFxDisableOsd();
    g_ucPageIndex = _P_MENU_NONE;
    g_ucMenuItemIndex = _MENU_NONE;

#if(_SLEEP_FUNC)
    bOSDOnScreen = 0;
#endif

#if(_SLEEP_FUNC)
    if((0xff == ucAutoPowerDownTime) || (0 == _GET_POWER_DOWN_TIME()))
#endif
    if (GET_AUDIO_MUTE()) // Mute on 
       CDrawMuteState();
}

//-----------------------------------------------------------
BYTE CFoundKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable)
{
     BYTE i;

     if(ucKeyMessage == _NONE_KEY_MESSAGE)
     {
          //ucOsdEventMsg = _NONE_MSG;
          return 0;
     }
                        
     i = 0;
     while(1)
     {
         if(tMsgTable[i].KeyMessage == _NONE_KEY_MESSAGE)
         {
              //ucOsdEventMsg = _NONE_MSG;
              // End flag
              return 1;
         }
         if(ucKeyMessage == tMsgTable[i].KeyMessage)
         {
              ucOsdEventMsg = tMsgTable[i].OsdEvent;
              return 0;
         }

         i++;
     }
     return 1;
}                                        
//---------------------------------------------------------------------------

void CCoverKeyMsgToOsdEvent(SKeyToOsdEvent *tMsgTable,BYTE bUserPublicKeyEvnet)
{
     bit bFoundPublic = 1;

     if(tMsgTable != NULL)
         bFoundPublic = CFoundKeyMsgToOsdEvent(tMsgTable);

     if(bFoundPublic && bUserPublicKeyEvnet)
     {
         CFoundKeyMsgToOsdEvent(tKOPublic);
     }
}
//---------------------------------------------------------------------------
bit CEnable(void)
{
     return 1;
}

/*
//---------------------------------------------------------------------------
bit CDisable(void)
{
     return 0;
}
*/

//---------------------------------------------------------------------------
void CDrawCurrentMenu(void) small
{
     BYTE n;

     //CUartPrintf("Page:",g_ucPageIndex);
	 //CUartPrintf("Menu Item Index:",g_ucMenuItemIndex);
	 //CUartPrintf("Menu Item Count:",CURRENT_MENU.MenuItemCount);

	 n = 0;
     while(1)
     {
          //CUartPrintf("Draw Item:",n);

          CURRENT_MENU.Menu[n].Draw(_DRAW_MENU_ITEM);

          //CUartPrintf("Draw Item:",n); 

          if(!CURRENT_MENU.Menu[n].Enable())
          {
              CURRENT_MENU.Menu[n].Draw(_DRAW_DISABLE);
          }         

          n++;
          
          if (n >= CURRENT_MENU.MenuItemCount)
              break;        
     }

//CURRENT_MENU_ITEM.Draw(_DRAW_SELECT);
}
//----------------------------------------------------------------------------------------------------
void CDrawSubMenu(void) small
{
     BYTE i = 0;
     BYTE ucPage = CURRENT_MENU_ITEM.SubMenuID;
     if(ucPage == 0)
         return;
     

     while(i < g_tMenu[ucPage].MenuItemCount)
     {
          g_tMenu[ucPage].Menu[i].Draw(_DRAW_MENU_ITEM);

          if(!g_tMenu[ucPage].Menu[i].Enable())
          {
              g_tMenu[ucPage].Menu[i].Draw(_DRAW_DISABLE);
          }
          i++;
     }

    ShowMode();
     //CURRENT_MENU_ITEM.Draw(_DRAW_SELECT);
}
//----------------------------------------------------------------------------------------------------

void CSCKeyIn(BYTE ucEvent)
{
    switch(ucEvent)
    {
    case _OE_SC_MUTE:
		g_ucPageIndex     = _P_SHORT_MENU;
		g_ucMenuItemIndex = _MI_SMMUTE;
		CMenuRun(_SET_MUTE);
        break;

    case _OE_SC_VOLUME:
		g_ucPageIndex     = _P_SHORT_MENU;
		g_ucMenuItemIndex = _MI_SMVOLUME;
        CLR_AUDIO_MUTE();
		CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
        break;

    case _OE_SC_BRIGHTNESS:
		g_ucPageIndex     = _P_SHORT_MENU;
		g_ucMenuItemIndex = _MI_SMBRIGHT;
		CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
        break; 

    case _OE_SC_CH_DEC:
    case _OE_SC_CH_INC:
        if (!CMITVEnable())
            return;
        CChangeChannel((ucEvent == _OE_SC_CH_DEC) ? 0 : 1);
        break;

    case _OE_SC_NUM0:
    case _OE_SC_NUM1:
    case _OE_SC_NUM2:
    case _OE_SC_NUM3:
    case _OE_SC_NUM4:
    case _OE_SC_NUM5:
    case _OE_SC_NUM6:
    case _OE_SC_NUM7:
    case _OE_SC_NUM8:
    case _OE_SC_NUM9:
        if (!CMITVEnable())
            return;
		g_ucPageIndex     = _P_SHORT_MENU;
		g_ucMenuItemIndex = _MI_SMINPUT_CH;
		CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
        CMenuRun(ucOsdEventMsg+(_OE_SC_INPUT_NUM0-_OE_SC_NUM0));
        break;

    case _OE_SC_INPUT_CH:
        if (!CMITVEnable())
            return;
		g_ucPageIndex     = _P_SHORT_MENU;
		g_ucMenuItemIndex = _MI_SMINPUT_CH;
		CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
        break;

    case _OE_SC_RETURN:
        pData[0]        = stTvInfo.CurChn;
        stTvInfo.CurChn = ucPrevChannel;
        ucPrevChannel   = pData[0];
        
        CMuteOn();
        CModeResetTVMode();
        CSetTVChannel(stTvInfo.CurChn);
    //    CShowTVNumber(stTvInfo.CurChn, _SHOW_CH_TV_NUMBER | _SHOW_CH_TV_TYPE);
        ucOsdEventMsg = _SAVE_EE_TV_DATA_MSG;
        break;
    }
}

//----------------------------------------------------------------------------------------------------
void CMenuProc(void)
{
    switch(ucOsdEventMsg)
    {
        case _OE_MENU_NEXT:         CChangeMenuItem(_INC);           break;
        case _OE_MENU_PREV:         CChangeMenuItem(_DEC);           break;
        case _OE_ENTER_SUBMENU:     CEnterSubMenu();                 break;
        case _OE_RETURN_UPMENU:     CReturnUpMenu();                 break;
        case _OE_ADJ_INC:           CMenuRun(_MENU_ADJ_INC);         break;
        case _OE_ADJ_DEC:           CMenuRun(_MENU_ADJ_DEC);         break;
        case _OE_RUN:               CMenuRun(_MENU_RUN);             break;
        
        // Shortcut key
        case _OE_SC_BRIGHTNESS:
        case _OE_SC_VOLUME:
        case _OE_SC_CH_DEC:
        case _OE_SC_CH_INC:
        case _OE_SC_NUM0:
        case _OE_SC_NUM1:
        case _OE_SC_NUM2:
        case _OE_SC_NUM3:
        case _OE_SC_NUM4:
        case _OE_SC_NUM5:
        case _OE_SC_NUM6:
        case _OE_SC_NUM7:
        case _OE_SC_NUM8:
        case _OE_SC_NUM9:
        case _OE_SC_INPUT_CH:
        case _OE_SC_RETURN:
        case _OE_SC_MUTE:            CSCKeyIn(ucOsdEventMsg);        break;

        case _OE_SC_INPUT_NUM0:
        case _OE_SC_INPUT_NUM1:
        case _OE_SC_INPUT_NUM2:
        case _OE_SC_INPUT_NUM3:
        case _OE_SC_INPUT_NUM4:
        case _OE_SC_INPUT_NUM5:
        case _OE_SC_INPUT_NUM6:
        case _OE_SC_INPUT_NUM7:
        case _OE_SC_INPUT_NUM8:
        case _OE_SC_INPUT_NUM9:
        case _OE_SC_INPUT_CHANGE_CH: CMenuRun(ucOsdEventMsg);        break;


        case _OE_CHANGE_SOURCE:      
            if(_SLEEP_STATE == ucCurrState)
            {
            	CModeSetFreeRun();
                CPowerLVDSOn();
                CModeResetMode();
            }
            ChangeSourceHandler();          
            break;
    }

}
//----------------------------------------------------------------------------------------------------
void CChangeMenuItem(BYTE ucMode)
{
     BYTE i;
     BYTE ucNewItem;

     CLR_KEYREPEATENABLE();

     //����˵�ֻ��һ��,ֱ�ӷ���
     if(CURRENT_MENU.MenuItemCount <= 1)
     {
          return;
     }

     // ������һ��˵���������һ�˵�
     i = 0;

     ucNewItem = ValueInRangeChange(0, CURRENT_MENU.MenuItemCount - 1, g_ucMenuItemIndex, ucMode | _LOOP);

     while(i < CURRENT_MENU.MenuItemCount)
     {
         if(CURRENT_MENU.Menu[ucNewItem].Enable())
         {
             break;
         }

         ucNewItem = ValueInRangeChange(0, CURRENT_MENU.MenuItemCount - 1, ucNewItem, ucMode | _LOOP);
         i++;
     }

     if(ucNewItem == g_ucMenuItemIndex)
     {
         return;
     }

     CURRENT_MENU_ITEM.Draw(_DRAW_NORMARL);
     CClearAdjustMenu();

     // Change menu item
     g_ucMenuItemIndex = ucNewItem;

     CURRENT_MENU_ITEM.Draw(_DRAW_SELECT);
}
//----------------------------------------------------------------------------------------------------
void CEnterSubMenu(void)
{
     if (g_ucPageIndex == _MI_EXIT)
     {
         CMIEXITRun(_MENU_RUN);
         return;
     }

     if(CURRENT_MENU_ITEM.SubMenuID == NULL)
     {
          return;
     }
     
     CURRENT_MENU.Draw(_DRAW_BEFORE_ENTER_SUBMENU);
     g_ucPageIndex = CURRENT_MENU_ITEM.SubMenuID;
     g_ucMenuItemIndex = 0;


     while(g_ucMenuItemIndex < CURRENT_MENU.MenuItemCount)
     {
         if(CURRENT_MENU.Menu[g_ucMenuItemIndex].Enable())
         {
             break;
         }

         g_ucMenuItemIndex++;
     }

     CClearAdjustMenu();
     CURRENT_MENU.Draw(_DRAW_ENTER_MENU);
}
//----------------------------------------------------------------------------------------------------
void CReturnUpMenu(void)
{
     //if(CURRENT_MENU.ParentMenuID == NULL)
     //{
     //    return;
     //}

    CURRENT_MENU.Draw(_DRAW_BEFORE_RETURN_PARENTMENU);
    
    g_ucMenuItemIndex = CURRENT_MENU.ParentMenuItemIndex;
    g_ucPageIndex = CURRENT_MENU.ParentMenuID;
    
    CURRENT_MENU.Draw(_DRAW_FROM_SUBMENU_RETURN);
     
    ShowMode();
}
//----------------------------------------------------------------------------------------------------
void CMenuRun(BYTE ucMode)
{
     if(CURRENT_MENU_ITEM.MenuRun != NULL)
     {
         CURRENT_MENU_ITEM.MenuRun(ucMode);
     }
}

//----------------------------------------------------------------------------------------------------
void InitOsdFrame(void)
{
    COsdFxDisableOsd();
    
    if (GET_OSD_SIZE())
        SetOSDDouble(0x03 | OSD_WINDOWCHAR_BLENDING);
    else
        SetOSDDouble(OSD_WINDOWCHAR_BLENDING);
    CScalerSetBit(_OVERLAY_CTRL_6C, 0x23, ((stOsdUserData.OsdBlending & 0x07) << 2));
    SetOsdMap(tUserMenuOsdMap);

    COsdFxCodeWrite(ucCloseAllWindow);
    OSDClear(0,_MAINMENU_HEIGHT, 0, 31, 0x8C, BYTE_ATTRIB);
    OSDClear(0,_MAINMENU_HEIGHT, 0, 31, 0x00, BYTE_DISPLAY);
    OSDClear(0,_MAINMENU_HEIGHT, 0, 31, 0x10, BYTE_COLOR);
    
}
//---------------------------------------------------------------------------

void OSDSlider(BYTE row, BYTE col, BYTE length, BYTE value, BYTE range,BYTE color)
{
    unsigned int bound;
    unsigned char i,c;
    OSDLine(row, col, length + 6, color, THE_BYTE2);   // Set Slider Attribute. 4 extra columns for space/numbers/space
    bound   = length * value;
    
    Gotoxy(col,row,THE_BYTE1);
    OutputChar(0x21);          // Left Border
    for (i = 1; i <= length; i++)
    {
        if (bound)
        {
            if(bound >= range)
            {
                c       = 0x28;
                bound   = bound - range;
            }
            else
            {
                color   = (bound << 4) / range;
                bound   = 0;
                if (4 > color)                    c = 0x23;
                else if (7 > color)               c = 0x24;
                else if (10 > color)              c = 0x25;
                else if (13 > color)              c = 0x26;
                else                              c = 0x27;
            }
        }
        else
        {
            c = 0x22;
        }
        OutputChar(c);
    }
    OutputChar(0x29);    // Right Border

    CShowNumber(col + length + 2, row,value);
}

//---------------------------------------------------------------------------
void CShowNoSignal(void)
{
	InitOsdFrame();

    COsdFxDrawWindow(8,0,											//WORD usXStart,WORD usYStart,  
    				 _DIALOG_WIDTH * 12 + 8,_DIALOG_HEIGHT * 18,	//WORD usXEnd,WORD usYEnd,  
    				 tMainWindowStyle);								//BYTE *pStyle)
	
    if (GET_OSD_SIZE())
        OSDPosition(_DIALOG_WIDTH * 12+680, _DIALOG_HEIGHT * 18+520, 50, 50, 0x03);
    else
        OSDPosition(_DIALOG_WIDTH * 12, _DIALOG_HEIGHT * 18, 50, 50, 0x03);
	CCenterTextout(sNoSignal[GET_LANGUAGE()],ROW(1),COL(0),_MAINMENU_WIDTH);
	COsdFxEnableOsd();
}


//---------------------------------------------------------------------------
void CShowNote(void)
{
    BYTE ucWindowWidth  = 0;

    COsdFxDisableOsd();
    SetOSDDouble(0x03);//SHOW_COLOR(5) | OSD_WINDOWCHAR_BLENDING);
    SetOsdMap(tUserMenuOsdMap);

    // Init OSD Ram
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x8C, BYTE_ATTRIB);
    OSDClear(0, GET_OSD_MAP_ROWCOUNT(), 0, 30, 0x00, BYTE_DISPLAY);
    OSDLine(0, 0, 30, 0x40, BYTE_COLOR);
    OSDClear(1, GET_OSD_MAP_ROWCOUNT() - 1, 0, 30, 0x60, BYTE_COLOR);
    
    COsdFxCodeWrite(ucCloseAllWindow); 

    OSDPosition(_MAINMENU_WIDTH * 12,_MAINMENU_HEIGHT * 18,1,1,0x03);

    switch(_GET_INPUT_SOURCE())
    {
    case _SOURCE_VGA:         
        ucWindowWidth  = 3;
        CTextOutEx(sSourceVGA, 0, 0);    
        break;

    case _SOURCE_DVI:         
        ucWindowWidth  = 3;
        CTextOutEx(sSourceDVI, 0, 0);    
        break;

    case _SOURCE_VIDEO_AV:    
        ucWindowWidth  = 2;
        CTextOutEx(sSourceAV, 0, 0);     
        break;

    case _SOURCE_VIDEO_SV:    
        ucWindowWidth  = 2;
        CTextOutEx(sSourceSV, 0, 0);     
        break;

    case _SOURCE_VIDEO_TV:    
        ucWindowWidth  = 2;
        CTextOutEx(sSourceTV, 0, 0);     
        break;

    case _SOURCE_HDMI:        
        ucWindowWidth  = 4;
        CTextOutEx(sSourceHDMI, 0, 0);  
        break;

    case _SOURCE_YPBPR:       
        ucWindowWidth  = 5;
        CTextOutEx(sSourceYPBPR, 0, 0);  
        break;
    }

    COsdFxDrawWindow(8, 0,											//WORD usXStart,WORD usYStart,  
    				 ucWindowWidth * 12 + 8, 14,	//WORD usXEnd,WORD usYEnd,  
    				 tNoteWindowStyle);								//BYTE *pStyle)

    COsdFxEnableOsd();
    CTimerReactiveTimerEvent(SEC(5), COsdDispOsdTimerEvent);
    bOSDTimeOut = 0;
#if(_SLEEP_FUNC)
    bOSDOnScreen = 1;
#endif
}





#endif			//#if(_OSD_TYPE == _OSD002)

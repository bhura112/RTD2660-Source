#define __OSDVGA007___

#include "Core\Header\include.h" 

#if(_OSD_TYPE == _OSD007)



#if(_TMDS_SUPPORT || _VGA_SUPPORT || _YPBPR_SUPPORT || _HDMI_SUPPORT)   
//------------------------------------------------------------
   
#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
void CDrawPicturePage(void)
{                                                              
    CTextOutEx(sAuto[GET_LANGUAGE()], 1, 4);           // "Auto"

#if(_YPBPR_SUPPORT)
    if (_SOURCE_YPBPR == _GET_INPUT_SOURCE())
    {
        CTextOutEx(sExit[GET_LANGUAGE()], 1, 5);       // "Exit" 
        return;
    }
#endif

#if(_VGA_SUPPORT)
    CTextOutEx(sAutoColor[GET_LANGUAGE()], 1, 5);      // "Auto Color"
    CTextOutEx(sHPos[GET_LANGUAGE()], 1, 6);           // "H Position"
    CTextOutEx(sVPos[GET_LANGUAGE()], 1, 7);           // "V Position"
    CTextOutEx(sPhase[GET_LANGUAGE()], 1, 8);          // "Phase"
    CTextOutEx(sClock[GET_LANGUAGE()], 1, 9);          // "Clock"
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 10);           // "Exit" 
#endif
}
#endif


//----------------------------------------------------------------------------------------------------
void MNoneProc(void)
{
    switch(ucKeyMessage)
    {
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MPublicNoneMenu(); break;

        case VK_LEFT:        MNoneLR(0);        break;

        case VK_RIGHT:       MNoneLR(1);        break;

        case VK_IR_MUTE:
            SSetMuteState();
            ucOsdEventMsg = _SAVE_EE_OSDUSERDATA_MSG;
            break;
            
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_IR_VOLDEC:
        case VK_IR_VOLINC:
            GotoAdjustVolume(); 
            break;

        case VK_IR_DISPLAY:
            CDisplayCurrentSourceMessage();
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MNoneLR(BYTE LR)
{
    if (LR) 
    {
     //  if (_GET_INPUT_SOURCE() == _SOURCE_VGA)
       //   DoAuto();
     //  else
#if(_VGA_COLOR_SUPPORT)
       CGotoAdjustVColor();
#else
       GotoAdjustVolume();
#endif
    }
    else  
       GotoAdjustVolume();
}

#if(_VGA_SUPPORT || _YPBPR_SUPPORT)
//----------------------------------------------------------------------------------------------------
void MPictureSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MPictureSubItemMenu();               break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MPictureSubItemLR(1);                break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MPictureSubItemLR(0);                break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       CExitToMainItem(MENU_MAIN_PICTURE);  break;
#endif
            
        // Other key
        default:             COthterKeyAction();                  break;
    }
}

//----------------------------------------------------------------------------------------------------
//   Picture Sub item
void MPictureSubItemMenu(void)
{
    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    switch(ucOsdState)
    {
        case MENU_ITEM_AUTO:
            if (_SOURCE_VGA == _GET_INPUT_SOURCE())
               CAutoDoAutoConfig();
            CSetItemWindowState(_SELECT_SUB_WINDOW, _MOVE_STATE);
            ShowMode();
            break;

#if(_VGA_SUPPORT)
        case MENU_ITEM_AUTO_COLOR:
            if (_SOURCE_VGA == _GET_INPUT_SOURCE())
                CAutoDoWhiteBalance();
            CSetItemWindowState(_SELECT_SUB_WINDOW, _MOVE_STATE);
            ShowMode();                           
            break;

        case MENU_ITEM_HPOS:
            SLIDER1(COsdCtrlGetHPosition());
            ucOsdState = MENU_SUB_HPOS_ADJ;
            break;

        case MENU_ITEM_VPOS:
            SLIDER1(COsdCtrlGetVPosition());
            ucOsdState = MENU_SUB_VPOS_ADJ;
            break;

        case MENU_ITEM_PHASE:
            SLIDER1(COsdCtrlGetPhase());
            ucOsdState = MENU_SUB_PHASE_ADJ;
            break;

        case MENU_ITEM_CLOCK:
            SLIDER1(COsdCtrlGetClock());
            ucOsdState = MENU_SUB_CLOCK_ADJ;
            break;
#endif

        case MENU_SUB_PICTURE_CLOSE:
            CExitToMainItem(MENU_MAIN_PICTURE);
            break;
    }
}


//----------------------------------------------------------------------------------------------------
void MPictureSubItemLR(BYTE LR)
{
#if(_YPBPR_SUPPORT)

    if (_SOURCE_YPBPR == _GET_INPUT_SOURCE())
    {
        if (ucOsdState == MENU_ITEM_AUTO)
        {
           ucOsdState = MENU_SUB_PICTURE_CLOSE;
           LR = 1;
        }
        else
        {
           ucOsdState = MENU_ITEM_AUTO;
           LR = 0;
        }

        CGotoNextSubItem(LR);
        return;
    }
#endif

#if(_VGA_SUPPORT)
    ucOsdState = ValueInRangeChange(MENU_ITEM_AUTO, MENU_SUB_PICTURE_CLOSE, ucOsdState, _LOOP | LR);
    
    CGotoNextSubItem(ucOsdState - MENU_ITEM_AUTO);
#endif
}

#endif
//----------------------------------------------------------------------------------------------------

#if(_COLOR_TEMP)
//----------------------------------------------------------------------------------------------------
void CDrawColorTempSubItem(void)
{
    CTextOutEx(sColorTemp9300, 1, 4);                            // "9300"
    CTextOutEx(sColorTemp6500, 1, 5);                            // "6500"
    CTextOutEx(sColorTemp5800, 1, 6);                            // "5800"
    CTextOutEx(sColorTempSRGB, 1, 7);                            // "SRGB"
    CTextOutEx(sColorTempUser[GET_LANGUAGE()], 1, 8); // "Color Temp"
    CTextOutEx(sExit[GET_LANGUAGE()], 1, 9);          // "Exit"
}

//   Color temp Sub item
void MColorTempSubItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Select item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
        case VK_F_RIGHT:
#endif
        case VK_MENU:        MColorTempSubItemMenu();        break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
#endif
        case VK_LEFT:        MColorTempSubItemLR(1);         break;

        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_DOWN:
#endif
        case VK_RIGHT:       MColorTempSubItemLR(0);         break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:       
        CExitToMainItem(MENU_ITEM_COLOR_TEMP);
        CClearSubItem();
        CDrawColorPage();
        CShowSubItemWindow(2);
        break;
#endif
            
        // Other key
        default:             COthterKeyAction();             break;
    }
}

//----------------------------------------------------------------------------------------------------
void MColorTempSubItemMenu(void)
{
    bit bExitSubItem = 0;

    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    switch(ucOsdState)
    {
        case MENU_SUB_CT_9300:
        case MENU_SUB_CT_6500:
        case MENU_SUB_CT_5800:
        case MENU_SUB_CT_SRGB:
            bExitSubItem = 1;
            break;

        case MENU_SUB_CT_USER:
            ucOsdState = MENU_SUB_CT_R;    
            OSDSlider(_MESSAGE_V_POSITION, 6, 10, stColorTempData.ColorTemp[_RED], 255, 0x20, _SHOW_PERCENT);
            break;

        case MENU_SUB_CT_CLOSE:
            bExitSubItem = 1;
            break;
    }

    if (bExitSubItem)
    {
        CExitToMainItem(MENU_ITEM_COLOR_TEMP);
        CClearSubItem();
        CDrawColorPage();
        CShowSubItemWindow(2);
    }

    ucOsdEventMsg = _SAVE_EE_SYSTEMDATA_MSG;
}

//----------------------------------------------------------------------------------------------------
void MColorTempSubItemLR(BYTE LR)
{
    BYTE ucTemp = 0;

    ucOsdState = ValueInRangeChange(MENU_SUB_CT_9300, MENU_SUB_CT_CLOSE, ucOsdState, _LOOP | LR);

    switch(ucOsdState)
    {      
        case MENU_SUB_CT_9300:
            ucTemp = _CT_9300;
            break;

        case MENU_SUB_CT_6500:
            ucTemp = _CT_6500;
            break;

        case MENU_SUB_CT_5800:
            ucTemp = _CT_5800;
            break;

        case MENU_SUB_CT_SRGB:
            ucTemp = _CT_SRGB;
            break;

        case MENU_SUB_CT_USER:
            ucTemp = _CT_USER;
            break;

        case MENU_SUB_CT_CLOSE:
            ucTemp = 255;
            break;
    }   
    
    if (ucTemp != 255)
    {
        SET_COLOR_TEMP_TYPE(ucTemp);
        CEepromLoadColorTempData();
    
        CAdjustContrast();
    }

    CGotoNextSubItem(ucOsdState - MENU_SUB_CT_9300);
}

//----------------------------------------------------------------------------------------------------
//   Color temp user Sub item
void MColorTempUserItemProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
#endif
        case VK_MENU:        MColorTempUserItemMenu();        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MColorTempUserItemLR(1);         break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MColorTempUserItemLR(0);         break;

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER:
            ucOsdState = MENU_SUB_CT_USER; 
            CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
            OSDClear(11, 4, 1, 25, 0x40, BYTE_COLOR);  // Clear message color
            break;
#endif
            
        // Other key
        default:             COthterKeyAction();              break;
    }
}

//----------------------------------------------------------------------------------------------------
void MColorTempUserItemMenu(void)
{
    bit bExitSubItem = 0;

    CClearMsg(_CLEAR_AND_SELECT_SUB_ITEM);

    switch(ucOsdState)
    {
        case MENU_SUB_CT_R:
            ucOsdState = MENU_SUB_CT_G;     
            OSDSlider(_MESSAGE_V_POSITION, 6, 10, stColorTempData.ColorTemp[_GREEN], 255, 0xc0, _SHOW_PERCENT);
            break;

        case MENU_SUB_CT_G:
            ucOsdState = MENU_SUB_CT_B;     
            OSDSlider(_MESSAGE_V_POSITION, 6, 10, stColorTempData.ColorTemp[_BLUE], 255, 0x30, _SHOW_PERCENT);
            break;

        case MENU_SUB_CT_B:
            ucOsdState = MENU_SUB_CT_USER; 
            CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
            OSDClear(11, 4, 1, 25, 0x40, BYTE_COLOR);  // Clear message color
            break;
    }
}

//----------------------------------------------------------------------------------------------------
void MColorTempUserItemLR(BYTE LR)
{
    switch(ucOsdState)
    {      
        case MENU_SUB_CT_R:   
            stColorTempData.ColorTemp[_RED] = ValueInRangeChange(0, 255, stColorTempData.ColorTemp[_RED], _NON_LOOP | LR);
            OSDSlider(_MESSAGE_V_POSITION, 6, 10, stColorTempData.ColorTemp[_RED], 255, 0x20, _SHOW_PERCENT);
            break;

        case MENU_SUB_CT_G:
            stColorTempData.ColorTemp[_GREEN] = ValueInRangeChange(0, 255, stColorTempData.ColorTemp[_GREEN], _NON_LOOP | LR);
            OSDSlider(_MESSAGE_V_POSITION, 6, 10, stColorTempData.ColorTemp[_GREEN], 255, 0xc0, _SHOW_PERCENT);
            break;

        case MENU_SUB_CT_B:
            stColorTempData.ColorTemp[_BLUE] = ValueInRangeChange(0, 255, stColorTempData.ColorTemp[_BLUE], _NON_LOOP | LR);
            OSDSlider(_MESSAGE_V_POSITION, 6, 10, stColorTempData.ColorTemp[_BLUE], 255, 0x30, _SHOW_PERCENT);
            break;

    }   
    
    CAdjustContrast();

    ucOsdEventMsg = _SAVE_EE_COLORPROC1_MSG;
}


#endif

#if(_VGA_SUPPORT)
//--------- PHASE ADJUST PROC ----------------------------------
void MPhaseAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MPhaseAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MPhaseAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MPhaseAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MPhaseAdjLR(0);        break;
           
        // Other key
        default:             COthterKeyAction();    break;
    }
}

//----------------------------------------------------------------------------------------------------
void MPhaseAdjMenu(void)
{
    ucOsdState = MENU_ITEM_PHASE;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MPhaseAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stModeUserData.Phase = ValueInRangeChange(0,63,stModeUserData.Phase,_NON_LOOP | LR);
    SLIDER1(COsdCtrlGetPhase());
    CAdjustPhase(stModeUserData.Phase);
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
}

//--------- CLOCK ADJUST PROC ----------------------------------
void MClockAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MClockAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MClockAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MClockAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MClockAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();    break;
    }
}

//----------------------------------------------------------------------------------------------------
void MClockAdjMenu(void)
{
    ucOsdState = MENU_ITEM_CLOCK;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MClockAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stModeUserData.Clock = ValueInRangeChange(COsdFxGetAdcClockRange(_GET_CLOCKRANGE_MIN),COsdFxGetAdcClockRange(_GET_CLOCKRANGE_MAX),stModeUserData.Clock,_NON_LOOP | LR);
    SLIDER1(COsdCtrlGetClock());
    CAdjustAdcClock(stModeUserData.Clock, 2);
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
}

//--------- H POSITION ADJUST PROC ----------------------------------
void MHPosAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MHPosAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MHPosAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MHPosAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MHPosAdjLR(0);        break;
           
        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MHPosAdjMenu(void)
{
    ucOsdState = MENU_ITEM_HPOS;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MHPosAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stModeUserData.HPosition = ValueInRangeChange(stModeUserCenterData.CenterHPos - _HPOSITION_BIAS,
                                                   stModeUserCenterData.CenterHPos + _HPOSITION_BIAS,
                                                   stModeUserData.HPosition,_NON_LOOP | LR);
    SLIDER1(COsdCtrlGetHPosition());
    CAdjustHPosition();
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
}


//--------- V position adjust proc ----------------------------------
void MVPosAdjProc(void)
{
    switch(ucKeyMessage)
    {
        // Move item
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_UP:
        case VK_F_DOWN:
            MVPosAdjMenu();
            COsdProc();
            break;
#endif

        // Exit item
#if(_MENU_FUNC == _MENU_EXIT_ITEM)
        case VK_ENTER: 
#endif
        case VK_MENU:        MVPosAdjMenu();       break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_LEFT:
#endif
        case VK_LEFT:        MVPosAdjLR(1);        break;

        // Adjust
#if(_USE_UD_LR_KEY_MSG)
        case VK_F_RIGHT:
#endif
        case VK_RIGHT:       MVPosAdjLR(0);        break;

        // Other key
        default:             COthterKeyAction();   break;
    }
}

//----------------------------------------------------------------------------------------------------
void MVPosAdjMenu(void)
{
    ucOsdState = MENU_ITEM_VPOS;
    CClearMsg(_CLEAR_AND_EXIT_SUB_ITEM);
}

//----------------------------------------------------------------------------------------------------
void MVPosAdjLR(BYTE  LR)
{
    SET_KEYREPEATENABLE();
    stModeUserData.VPosition = ValueInRangeChange(stModeUserCenterData.CenterVPos - _VPOSITION_BIAS,stModeUserCenterData.CenterVPos + _VPOSITION_BIAS,stModeUserData.VPosition,_NON_LOOP | LR);
    SLIDER1(COsdCtrlGetVPosition());
    CAdjustVPosition();
    ucOsdEventMsg = _SAVE_EE_MODEUSERDATA_MSG;
}

#endif

//----------------------------------------------------------------------------------------------------
#if(_VGA_SUPPORT)                   
void DoAuto(void)
{ 
    CInitOSDMainFrame();
    SetOSDDouble((GET_OSD_SIZE() ? 0x03 : 0x00)  | OSD_WINDOWCHAR_BLENDING);   
#if(_OSD_DISPLAY_SIZE_ADJ)
    if (GET_OSD_SIZE())
        OSDPosition(_VOLUME_OSD_DOUBLE_WIDTH, _VOLUME_OSD_DOUBLE_HEIGHT, 50, 50, 0x03);
    else
#endif
        OSDPosition(_HINT_WINDOW_H_END, _HINT_WINDOW_V_END, 50, 50, 0x03);

#if(!_OSD_DISPLAY_SIZE_ADJ && !_ALPHA_BLENDING_ADJ)
    pData[0] = 0x40;
    pData[1] = 0x03;
    pData[2] = 0xa0;
    CScalerWrite(_OSD_ADDR_MSB_90,3,pData,_AUTOINC);
#endif

    COsdFxDrawWindow(XSTART(_HINT_WINDOW_H_POS), YSTART(_HINT_WINDOW_V_POS), 
                     XEND(_HINT_WINDOW_H_END), YEND(_HINT_WINDOW_V_END), 
                     tOSD_MINI_WINDOW_STYLE);

	CCenterTextout(sAuto[GET_LANGUAGE()],ROW(2),COL(0),30);
    COsdFxEnableOsd(); 
    CAutoDoWhiteBalance();
    CAutoDoAutoConfig();
    COsdFxDisableOsd();
}
#endif
//----------------------------------------------------------------------------------------------------
#endif  //#if(_TMDS_SUPPORT || _VGA_SUPPORT || YPBPR_SUPPORT || _HDMI_SUPPORT)
#endif  //#if(OSD_TYPE == OSD007)


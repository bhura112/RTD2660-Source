

#define __OSDTABLE001__


#include "Core\Header\Include.h"


#if(_OSD_TYPE == _OSD001)

//------------------------------------------------------------




// Menu item's define


//------------------------------------------------------------
code SMenuItem tMenuNoneItem[] =
{
    {   // Active
        _EN_PUB_PROCFUNC,        					// BYTE Option;
        tKOMenuNone,    							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        _P_MAIN_MENU,      							// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CDrawNull,      							// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIMenuNoneRun,    							// funcpMenuRun MenuRun
    },/*
    {   // No signel / not support / no cable
        _EN_PUB_PROCFUNC,  							// BYTE Option;
        tKONoSignal,    							// SKeyToOsdEvent *KeyMsgToOsdEvnet;        // ����ΪNULL
        _P_MAIN_MENU,      							// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CDrawNull,      							// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIMenuNoneRun,    							// funcpMenuRun MenuRun
    },*/

};
//------------------------------------------------------------
/*
enum
{
    _MI_BRIGHTNESS = 0,
    _MI_CONTRAST,
    _MI_HUE,
    _MI_SATURATION,
    _MI_PHASE,
    _MI_CLOCK,
    _MI_DISPLAY_MODE,		// 
Full  4:3
    _MI_AUTO_ADJUST,
    //_MI_AUTO_SEARCH,
    _MI_EXIT,
};
*/


code SMenuItem tMainMenuItem[] =
{
    {   // _MI_BRIGHTNESS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,     	//BYTE Option;
        NULL,    				//SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,           		// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           		// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        		// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawBrightness,      	// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIBrightnessRun, 		// funcpMenuRun MenuRun
    },
    {   // _MI_CONTRAST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,     	// BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,           	  	// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           		// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        		// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawContrast,  		// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIContrastRun, 		// funcpMenuRun MenuRun
    },
    {   // _MI_HUE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMIVedio8Enable,       	// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawHue,          	// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIHueRun,         		// funcpMenuRun MenuRun
    },
    {   // _MI_SATURATION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMIVedio8Enable,    	// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSaturation,     	// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMISaturationRun,       // funcpMenuRun MenuRun
    },
    {   // _MI_PHASE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMIVGAEnable,        	// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawPhase,      		// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIPhaseRun,       		// funcpMenuRun MenuRun
    },
    {   // _MI_CLOCK
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,    				// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMIVGAEnable,        	// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawClock,      		// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIClockRun,       		// funcpMenuRun MenuRun
    },
    {   // _MI_DISPLAY_MODE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        tKOMenuRun,    			// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CEnable,           		// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawDisplayMode,     // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIDisplayModeRun,      // funcpMenuRun MenuRun
    },
    {   // _MI_AUTO_ADJUST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        tKOMenuRun,             // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMIVGAEnable,           // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawAutoAdjust,      // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIAutoAdjustRun,       // funcpMenuRun MenuRun
    },
                
#if(_VIDEO_TV_SUPPORT)
    //--------------------------------- TV item ------------------------------------
    {   // _MI_TV_SYSTEM
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawTVSystem,        // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMITVSystemRun,         // funcpMenuRun MenuRun
    },
    {   // _MI_AUTO_SEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawAutoSearch,      // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIAutoSearchRun,       // funcpMenuRun MenuRun
    },              
    {   // _MI_MANUAL_SEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawManualSearch,    // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIManualSearchRun,     // funcpMenuRun MenuRun
    },              
    {   // _MI_TUNNING
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawTunning,         // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMITunningRun,          // funcpMenuRun MenuRun
    },              
    {   // _MI_SWAP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSwap,            // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMISwapRun,             // funcpMenuRun MenuRun
    },              
    {   // _MI_CHANNEL
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawChannel,         // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIChannelRun,          // funcpMenuRun MenuRun
    },              
    {   // _MI_SKIP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,            // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSkip,            // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMISkipRun,             // funcpMenuRun MenuRun
    },              
    //-------------------------------- TV item end ----------------------------------
#endif // #if(_VIDEO_TV_SUPPORT)

    {   // _MI_LANGUAGE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CEnable,                // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawLanguage,        // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMILanguageRun,         // funcpMenuRun MenuRun
    },              
    {   // _MI_BLUE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CEnable,                // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawBlue,            // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIBlueRun,             // funcpMenuRun MenuRun
    },              
    {   // _MI_VOLUME
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        NULL,                   // SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CEnable,                // bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawVolume,          // void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIVolumeRun,           // funcpMenuRun MenuRun
    },              
    
    {   // _MI_EXIT
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,       // BYTE Option;
        tKOMenuRun,    			// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,                   // SMenu *SubMenu,                         // ����ΪNULL
        NULL,                   // void (*Proc)(void);                     // ����ΪNULL
        CEnable,           		// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawExit,      		// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CMIExitRun,       		// funcpMenuRun MenuRun
    },
    
    
};
//------------------------------------------------------------


code SMenuItem tSCMenuItem[] =
{
    {   // _SC_MUTE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,     	//BYTE Option;
        tKOMenuRun,				//SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        NULL,           		// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           		// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        		// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CDrawSCMute,          	// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        CSCMuteRun,     		// funcpMenuRun MenuRun
    },
};
//------------------------------------------------------------


// Menu's define



//------------------------------------------------------------

code SMenu g_tMenu[] = 
{
	{	//_P_MENU_NONE
	    NULL,                                                       //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMenuNoneItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMenuNoneItem,                                              //TMenuItem *Menu;
	    CDrawNull,                                           		//void (*Draw)(BYTE ucDrawID);
	},
	{	//_P_MAIN_MENU
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMainMenuItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMainMenuItem,                                              //TMenuItem *Menu;
	    CPDrawMainMenu,                                             //void (*Draw)(BYTE ucDrawID);
	},
	{	//_P_SC_MENU
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tSCMenuItem)/sizeof(SMenuItem),                      //BYTE MenuItemCount;
	    tSCMenuItem,                                                //TMenuItem *Menu;
	    CPDrawSCMenu,                                               //void (*Draw)(BYTE ucDrawID);
	},

    /*
    {   //_P_SHOW_MUTE
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMenuNoneItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMenuNoneItem,                                              //TMenuItem *Menu;
	    CDrawMuteState,                                             //void (*Draw)(BYTE ucDrawID);
    } */
};
//------------------------------------------------------------

#endif 	//#if(_OSD_TYPE == _OSD001)




#define __OSDTABLE002__


#include "Core\Header\Include.h"


#if(_OSD_TYPE == _OSD002)

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
        NULL,           							// funcpMenuRun MenuRun
    },
};
//------------------------------------------------------------

code SMenuItem tMenuExitItem[] =
{
    {   // Active
        _EN_PUB_PROCFUNC,        					// BYTE Option;
        tKOMenuNone,    							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        _P_MAIN_MENU,      							// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CDrawNull,      							// void (*Draw)(BYTE ucDrawID);            // ����ΪNULL,ԭ��ͬ��
        NULL,           							// funcpMenuRun MenuRun
    },
};
//------------------------------------------------------------

code SMenuItem tMainMenuItem[] =
{
    {   // _MI_COLOR
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        _P_COLOR_MENU,                              // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawCOLOR,                               // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMICOLORRun,                                // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_ADJUST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        _P_ADJUST_MENU,                             // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                         		// funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawADJUST,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIADJUSTRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_OSD
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        _P_OSD_MENU,                                // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawOSD,                                 // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIOSDRun,                                  // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_TV
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        _P_TV_MENU,                                 // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVEnable,                               	// funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawTV,                                  // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMITVRun,                                   // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_FUNCTION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        _P_FUNC_MENU,                               // int SubMenuID                           // ����ΪNULL
        NULL,                                		// SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawFUNCTION,                            // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIFUNCTIONRun,                             // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_EXIT
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMainMenu,                            			// SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        _P_MENU_EXIT,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawEXIT,                                // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIEXITRun,                                 // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
};
//------------------------------------------------------------
code SMenuItem tColorMenuItem[] =
{
    {   // _MI_BRIGHTNESS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawBrightness,                          // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIBrightnessRun,                           // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_CONTRAST
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawContrast,                            // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIContrastRun,                             // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_HUE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVedioEnable,                             // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawHue,                                 // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIHueRun,                                  // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_SATURATION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVedioEnable,                             // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawSaturation,                          // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISaturationRun,                           // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_COLORTEMP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                               // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawColorTemp,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIColorTempRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_COLORRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        //BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawColorReturn,                         // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIColorReturnRun,                          // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
};
//------------------------------------------------------------
code SMenuItem tAdjustMenuItem[] =
{
    {   // _MI_AUTOCONFIG
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                               // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawAutoConfig,                          // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIAutoConfigRun,                           // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_HPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                               // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawHPosition,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIHPositionRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_VPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                               // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawVPosition,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIVPositionRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_PHASE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                               // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawPhase,                               // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIPhaseRun,                                // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_CLOCK
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMIVGAEnable,                               // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawClock,                               // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIClockRun,                                // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_ADJUSTRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                               	    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawAdjustReturn,                        // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIAdjustReturnRun,                         // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
};
//------------------------------------------------------------
code SMenuItem tOsdMenuItem[] =
{
    {   // _MI_LANGUAGE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawLanguage,                            // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMILanguageRun,                             // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_HPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawOSDHPosition,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIOSDHPositionRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_VPOSITION
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawOSDVPosition,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIOSDVPositionRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_TIMER
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawTimer,                               // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMITimerRun,                                // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_DOUBLE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawDouble,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIDoubleRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_TRANSPARENT
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawTransparent,                         // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMITransparentRun,                          // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_OSDRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawOsdReturn,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIOsdReturnRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    
};
//------------------------------------------------------------
code SMenuItem tTVMenuItem[] =
{
    {   // _MI_SYSTEM
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVFMEnable,                              // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawSystem,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISystemRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_CHANNEL
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVEnable,                                // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawChannel,                             // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIChannelRun,                              // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_AUTOSEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVEnable,                                // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawAutoSearch,                          // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIAutoSearchRun,                           // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_MANUALSEARCH
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVFMEnable,                              // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawManualSearch,                        // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIManualSearchRun,                         // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_TUNING
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVEnable,                                // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawTuning,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMITuningRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_SKIP
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVEnable,                                // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawSkip,                                // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISkipRun,                                 // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
#if(_SLEEP_FUNC)
    {   // _MI_AUTOPOWERDOWN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVFMEnable,                              // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawAutoPowerDown,                       // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIAutoPowerDownRun,                        // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
#endif
    {   // _MI_BLUESCREEN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CMITVFMEnable,                              // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawBlueScreen,                          // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIBlueScreenRun,                           // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_TVRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawTVReturn,                            // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMITVReturnRun,                             // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
};
//------------------------------------------------------------
code SMenuItem tFuncMenuItem[] =
{
    {   // _MI_RESET
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawReset,                               // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIResetRun,                                // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
#if(_DISPLAY_RATIO)
    {   // _MI_DISPLAYRATIO
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawDisplayRatio,                        // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIDisplayRatioRun,                         // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
#endif
    {   // _MI_VOLUME
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawVolume,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIVolumeRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_MUTE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawMute,                                // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIMuteRun,                                 // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    }, 
#if (_SOUND_PROCESSOR)
    {   // _MI_BALANCE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawBalance,                             // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIBalanceRun,                              // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_BASS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawBass,                                // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIBassRun,                                 // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_TREBLE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawTreble,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMITrebleRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
   #if(AUDIO_TYPE != _AUDIO_SC7313)
    {   // _MI_SRS
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawSRS,                                 // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISRSRun,                                  // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_BBE
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawBBE,                                 // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIBBERun,                                  // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
   #endif
#endif
#if(_FM_DEVICE)
    {   // _MI_FM
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawFM,                                  // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIFMRun,                                   // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
#endif
    {   // _MI_FUNCRETURN
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option
        tKOMenuItem,                                // SKeyToOsdEvent *KeyMsgToOsdEvnet        // ����ΪNULL
        NULL,                                       // int SubMenuID                           // ����ΪNULL
        NULL,                                       // funcpProc Proc                          // ����ΪNULL
        CEnable,                                    // funcpEnable Enable                      // ����ΪNULL,��Ϊ���õĵط���
        CMIDrawFuncReturn,                          // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMIFuncReturnRun,                           // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
};
//------------------------------------------------------------


code SMenuItem tShortMenuItem[] =
{
    {   // _MI_SMBRIGHT,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortBriMenu,   							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        0,      									// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSMBright,                            // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISMBrightRun,                             // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_SMVOLUME,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortVolMenu,   							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        0,      									// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSMVolume,                            // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISMVolumeRun,                             // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_SMMUTE,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortMute,      							// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        0,      									// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CEnable,        							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSMMute,                              // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISMMuteRun,                               // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
    {   // _MI_SMINPUT_CH,
        _EN_PUB_KEYEVENT | _EN_PUB_PROCFUNC,        // BYTE Option;
        tKOShortInputCHMenu,						// SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
        0,      									// SMenu *SubMenu,                         // ����ΪNULL
        NULL,           							// void (*Proc)(void);                     // ����ΪNULL
        CMITVEnable,       							// bit (*Enable)(void);                    // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ�����
        CMIDrawSMInputCh,                           // funcpDraw Draw                          // ����ΪNULL,ԭ��ͬ��
        CMISMInputChRun,                            // funcpMenuRun MenuRun                    // ����ΪNULL,ԭ��ͬ��
    },
};
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
	{	//_P_MENU_EXIT
	    _P_MENU_EXIT,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMenuExitItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMenuExitItem,                                              //TMenuItem *Menu;
	    CCloseOSD,                                                  //void (*Draw)(BYTE ucDrawID);
	},
	// ���˵�
	{	//_P_MAIN_MENU
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
	    sizeof(tMainMenuItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
	    tMainMenuItem,                                              //TMenuItem *Menu;
	    CPDrawMainMenu,                                              //void (*Draw)(BYTE ucDrawID);
	},
	// �Ӳ˵�
	{	//_P_COLOR_MENU
	    _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
	    _MI_COLOR,                                                  //BYTE ParentMenuItemIndex;
	    sizeof(tColorMenuItem)/sizeof(SMenuItem),                  	//BYTE MenuItemCount;
	    tColorMenuItem,                                             //TMenuItem *Menu;
	    CPDrawColorMenu,                                            //void (*Draw)(BYTE ucDrawID);
	},
    {   //_P_ADJUST_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_ADJUST,                                                 //BYTE ParentMenuItemIndex;
        sizeof(tAdjustMenuItem)/sizeof(SMenuItem),                  //BYTE MenuItemCount;
        tAdjustMenuItem,                                            //TMenuItem *Menu;
        CPDrawAdjustMenu,                                           //void (*Draw)(BYTE ucDrawID);
    },
    {   //_P_OSD_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_OSD,                                                    //BYTE ParentMenuItemIndex;
        sizeof(tOsdMenuItem)/sizeof(SMenuItem),                     //BYTE MenuItemCount;
        tOsdMenuItem,                                               //TMenuItem *Menu;
        CPDrawOsdMenu,                                              //void (*Draw)(BYTE ucDrawID);
    },
    {   //_P_TV_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_TV,                                                     //BYTE ParentMenuItemIndex;
        sizeof(tTVMenuItem)/sizeof(SMenuItem),                      //BYTE MenuItemCount;
        tTVMenuItem,                                                //TMenuItem *Menu;
        CPDrawTVMenu,                                               //void (*Draw)(BYTE ucDrawID);
    },
    {   //_P_FUNC_MENU
        _P_MAIN_MENU,                                               //TMenuItem *ParentMenu;
        _MI_FUNCTION,                                               //BYTE ParentMenuItemIndex;
        sizeof(tFuncMenuItem)/sizeof(SMenuItem),                    //BYTE MenuItemCount;
        tFuncMenuItem,                                              //TMenuItem *Menu;
        CPDrawFuncMenu,                                             //void (*Draw)(BYTE ucDrawID);
    }, 

    //��ݲ˵�
    {   //_P_SHORT_MENU   
	    _P_MENU_NONE,                                               //TMenuItem *ParentMenu;
	    0,                                                          //BYTE ParentMenuItemIndex;
        sizeof(tShortMenuItem)/sizeof(SMenuItem),                   //BYTE MenuItemCount;
        tShortMenuItem,                                             //TMenuItem *Menu;
        CPDrawShowMenu,                                             //void (*Draw)(BYTE ucDrawID);
    }, 
	
};
//------------------------------------------------------------



#endif 	//#if(_OSD_TYPE == _OSD002)


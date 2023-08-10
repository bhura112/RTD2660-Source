#if(_OSD_TYPE == _OSD002)


//------------------------------------------------------
typedef bit (*funcpProc)(void);
typedef bit (*funcpEnable)(void);
typedef void (*funcpDraw)(BYTE ucDrawID);
typedef void (*funcpMenuRun)(BYTE ucMode);



typedef enum 
{
    _NONE_MSG,
    
    // system osd event begin
    _SHOW_NOSIGNAL_MSG,
    _SHOW_NOCABLE_MSG,
    _SHOW_NOSUPPORT_MSG,
    _SAVE_EE_MODEUSERDATA_MSG,
    _SAVE_EE_SYSTEMDATA_MSG,
    _SAVE_EE_OSDUSERDATA_MSG,
    _SAVE_EE_ADCDATA_MSG,
    _SAVE_EE_COLORPROC0_MSG,
    _SAVE_EE_COLORPROC1_MSG,
    _SAVE_EE_TV_DATA_MSG,
    _SAVE_EE_AUDIO_DATA_MSG,
    _SAVE_EE_HUE_SAT_DATA_MSG,
    _ENTER_FACTORY_MODE_MSG,
    _DO_AUTO_CONFIG,
    _DO_SHOW_NOTE,
    _CHANGE_SOURCE_MSG,



    // system osd event end
    
    
    _OE_USER_CMD,
    // user osd event begin
    _OE_MENU_NEXT,
    _OE_MENU_PREV,
    _OE_ENTER_SUBMENU,
    _OE_RETURN_UPMENU,
    _OE_ADJ_INC,
    _OE_ADJ_DEC,
    _OE_RUN,

    // Factory event
    _OE_FAC_OPEN,

    // Shortcut key event
    _OE_CHANGE_SOURCE,
    _OE_SC_BRIGHTNESS,
    _OE_SC_VOLUME,
    _OE_SC_MUTE,
    _OE_DISPLAY,
    _OE_SC_CH_DEC,
    _OE_SC_CH_INC,
    _OE_SC_NUM0,
    _OE_SC_NUM1,
    _OE_SC_NUM2,
    _OE_SC_NUM3,
    _OE_SC_NUM4,
    _OE_SC_NUM5,
    _OE_SC_NUM6,
    _OE_SC_NUM7,
    _OE_SC_NUM8,
    _OE_SC_NUM9,
    _OE_SC_INPUT_CH,
    _OE_SC_INPUT_NUM0,
    _OE_SC_INPUT_NUM1,
    _OE_SC_INPUT_NUM2,
    _OE_SC_INPUT_NUM3,
    _OE_SC_INPUT_NUM4,
    _OE_SC_INPUT_NUM5,
    _OE_SC_INPUT_NUM6,
    _OE_SC_INPUT_NUM7,
    _OE_SC_INPUT_NUM8,
    _OE_SC_INPUT_NUM9,
    _OE_SC_INPUT_CHANGE_CH,
    _OE_SC_RETURN

}EOsdEvent;
//------------------------------------------------------
typedef enum 
{
    // Menu item draw ID
    _DRAW_MENU_ITEM,        //���˵���
    _DRAW_NORMARL,          //��׼״̬
    _DRAW_SELECT,           //ѡ��״̬
    _DRAW_DISABLE,          //����״̬

    // Menu Draw ID
    _DRAW_ENTER_MENU,              //���뵱ǰ�Ĳ˵�ʱ����
    _DRAW_BEFORE_RETURN_PARENTMENU,//���ص���һ���˵�֮ǰ...
    _DRAW_BEFORE_ENTER_SUBMENU,    //�����Ӳ˵�֮ǰ...
    _DRAW_FROM_SUBMENU_RETURN,     //���Ӳ˵�����


    // �Զ�����
    // ...
}EMenuDraw;
//------------------------------------------------------

// Option bit define's
#define _EN_PUB_KEYEVENT                _BIT0
#define _EN_PUB_PROCFUNC                _BIT1


typedef struct 
{
    BYTE Option;                            
    SKeyToOsdEvent *KeyMsgToOsdEvnet;       // ����ΪNULL
    BYTE SubMenuID;                          // ����ΪNULL
    funcpProc Proc;                         // ����ΪNULL
    funcpEnable Enable;                     // ����ΪNULL,��Ϊ���õĵط���.���Ϊ��Ҫ���Ӻܶ����
    funcpDraw Draw;                         // ����ΪNULL,ԭ��ͬ��
    funcpMenuRun MenuRun;                   // ����ΪNULL
    
}SMenuItem;
//------------------------------------------------------
typedef struct 
{
    BYTE ParentMenuID;
    BYTE ParentMenuItemIndex;
    BYTE MenuItemCount;
    SMenuItem *Menu;

    funcpDraw Draw;
}SMenu;
//------------------------------------------------------

#endif		//#if(_OSD_TYPE == _OSD002)


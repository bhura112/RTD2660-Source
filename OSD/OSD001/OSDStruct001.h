#if(_OSD_TYPE == _OSD001)


//------------------------------------------------------
typedef bit (*funcpProc)(void);
typedef bit (*funcpEnable)(void);
typedef void  (*funcpDraw)(BYTE ucDrawID);
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
    _CHANGE_SOURCE_MSG,
    _DO_AUTO_CONFIG,
    _DO_SHOW_NOTE,


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
    _OE_CHANGE_SOURCE,
    //---------------------------------------------------------
    //��ݲ˵� 
    _OE_SET_MUTE_STATE,
    _OE_ADJ_VOLUME_MENU,                // �������������ݲ˵�
    _OE_ADJ_BRIGHTNESS_MENU,            // ����������ȿ�ݲ˵�
    _OE_CHANNEL_INC,
    _OE_CHANNEL_DEC,
    //---------------------------------------------------------
    _OE_0,
    _OE_1,
    _OE_2,
    _OE_3,
    _OE_4,
    _OE_5,
    _OE_6,
    _OE_7,
    _OE_8,
    _OE_9,
    
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

#endif		//#if(_OSD_TYPE == _OSD001)


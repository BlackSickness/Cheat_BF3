#ifndef _Snowroller_H
#define _Snowroller_H
#include "FB SDK/MessageListener.h"
namespace fb
{
	class Snowroller : public fb::MessageListener
    {
    public:
      //  fb::PipeServer* m_server; //0x0004  
      //  fb::CommandHandler m_cmdHandler; //0x0008  
        bool m_windowHasFocus; //0x003C  
        bool m_hwndSet; //0x003D  
        bool m_shutdownInProgress; //0x003E  
        BYTE _Snowroller_pad_0; //0x003F  
        float m_timeAsOrphan; //0x0040  
        float m_snowrollerOrphanTimeout; //0x0044  
        float m_timeSinceLastCheck; //0x0048  
        void* m_stateMachine; //0x004C  
    };//Size=0x0050(80)

};

#endif
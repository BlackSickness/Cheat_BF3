#ifndef _Keyboard_H
#define _Keyboard_H

#include "Frostbite_Classes.h"
#include "CriticalSection.h"
namespace fb
{
	class Keyboard : public IDevice
    {
    public:
        PAD(0x4);
        CriticalSection    m_section;
        eastl::deque<void*, 8>    m_bufferedActions;
        HWND__*    m_hWnd;
        void*    m_prevWindowProc;
        unsigned char    m_current[0x100];
        unsigned char    m_buffer[0x100];
        bool    m_typingMode;
        bool    m_hasOverflowed;
        PAD(0x2);
        unsigned int    m_codePage;
    };

	class IKeyboard
	{
	public:
		virtual void init();	// V: 0x0
		virtual void release();	// V: 0x4
		virtual void preFrameUpdate(float);	// V: 0x8
		virtual void update(float);	// V: 0xC
		virtual bool isDown(InputDeviceKeys);	// V: 0x10
		virtual bool wentDown(InputDeviceKeys);	// V: 0x14
		virtual bool wentUp(InputDeviceKeys);	// V: 0x18
		virtual void enableTypingMode(bool);	// V: 0x1C
		virtual bool getBufferedAction(struct fb::DeviceAction &);	// V: 0x20
	};


};

#endif
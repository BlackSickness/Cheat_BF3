#ifndef _Mouse_H
#define _Mouse_H

//#include "../Frostbite_classes.h"

namespace fb
{

	
	class Mouse : 
		public IDevice,
        public MessageListener
    {
    public:
        class State
        {
			public:
            int xMove;
            int yMove;
            int zMove;
            unsigned char buttonState[0x8];
        };
        CriticalSection m_section;
        eastl::deque<void*, 8>    m_bufferedActions;
        PAD(0x4);
        HWND__*    m_hWnd;
        void*    m_prevWindowProc;
        HICON__*    m_cursor;
        HICON__*    m_cursorImage;
        HICON__*    m_cursorImage2;
        bool    m_cursorMode;
        bool    m_uiOwnsInput;
        bool    m_showCursor;
        bool    m_cursorConfined;
        bool    m_hasOverflowed;
        bool    m_useRawMouseInput;
        PAD(0x2);
        tagRECT m_cursorConfinement;
        Mouse::State m_state;
        Mouse::State m_buffer;
    };

	/*
	class Mouse //fb::MessageListener // Inherited class at offset 0x4
	{		
		//bool m_cursorMode;                     // this+0x68
		PAD(0x70);
		bool m_uiOwnsInput;                     // this+0x69
		bool m_showCursor;                     // this+0x6A
		bool m_cursorConfined;                     // this+0x6B
		bool m_hasOverflowed;                     // this+0x6C
		bool m_useRawMouseInput;                     // this+0x6D
		struct tagRECT m_cursorConfinement;                     // this+0x70
		class State
		{

			long xMove;                     // this+0x0
			long yMove;                     // this+0x4
			long zMove;                     // this+0x8
			unsigned char buttonState[0x8]; // this+0xC

		}; // State

		struct fb::Mouse::State m_state;                     // this+0x80
		struct fb::Mouse::State m_buffer;                     // this+0x94
	}; // fb::Mouse
	*/
	class IMouse
	{
	public:
		virtual void init();	// V: 0x0
		virtual void release();	// V: 0x4
		virtual void preFrameUpdate(float);	// V: 0x8
		virtual void update(float);	// V: 0xC
		virtual void updateBetweenFrames(float);	// V: 0x10
		virtual bool isDown(void*, bool);	// V: 0x14
		virtual bool wentDown(void*);	// V: 0x18
		virtual bool wentUp(void*);	// V: 0x1C
		virtual float getLevel(void*, bool);	// V: 0x20
		virtual float getLevel(void*);	// V: 0x24
		virtual bool getBufferedAction(void*);	// V: 0x28
		virtual void enableCursorMode(bool, int);	// V: 0x2C
		virtual void setCursorPosition(int, int);	// V: 0x30
		virtual void setCursorRect(bool, unsigned int, unsigned int, unsigned int, unsigned int);	// V: 0x34
		virtual void setMouseSensitivity(float);	// V: 0x38
		virtual void setUIOwnsInput(bool);	// V: 0x3C
	};


};

#endif
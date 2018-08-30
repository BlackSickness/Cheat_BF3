#ifndef _System_H
#define _System_H

namespace fb
{

	

	class ISystem
    {
    public:
        virtual void * __vecDelDtor(unsigned int);    // V: 0x0
        virtual unsigned int deviceCount();    // V: 0x4
        virtual class IDevice * getDevice(unsigned int);    // V: 0x8
    };

    class System : public ISystem
    {
    public:
        eastl::vector<IDevice>    m_devices;
        /*IDirectInput8A* */ DWORD  m_dinput;
        Keyboard*    m_keyboard;
        Mouse*    m_mouse;
        HWND__*    m_hWnd;
        unsigned int    m_xinputCounter;	
	
		static System* Singleton()
		{
			return (System*)SYSTEM;//*(System**)SYSTEM;//0x02385AD4;
		}

    };


};

#endif
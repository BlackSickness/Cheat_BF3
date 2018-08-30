#ifndef _Device_H
#define _Device_H

//#include "../Frostbite_classes.h"

namespace fb
{


	class DeviceAction
	{

		enum Action
		{

			Action_Pressed,                     // constant 0x1
			Action_Released,                     // constant 0x2
			Action_PressedSystem,                     // constant 0x3
			Action_ReleasedSystem,                     // constant 0x4
			Action_Typed,                     // constant 0x5
			Action_KeyDown,                     // constant 0x6
			Action_KeyUp,                     // constant 0x7
			Action_Scroll,                     // constant 0x8
			Action_Moved,                     // constant 0x9
			Action_Reset                    // constant 0xA

		}; // Action

		int x;                     // 0x0
		int y;                     // 0x4
		int z;                     // 0x8
		wchar_t key;                     // 0xC
		Action action;                     // 0x10
		unsigned char scanCode;                     // 0x14

	}; // fb::DeviceAction

	class IDevice // Inherited class at offset 0x0
	{
		 public:
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void read(float, bool);	// V: 0x4
		virtual const char * name(unsigned int);	// V: 0x8
		virtual const char * name();	// V: 0xC
		virtual unsigned int controlCount();	// V: 0x10
		virtual bool isConnected();	// V: 0x14
		virtual bool isAnalogue(unsigned int);	// V: 0x18
		virtual float getValue(unsigned int);	// V: 0x1C
		virtual void function0();
        virtual void initialize(long dwNewLong, HWND hWnd);

	}; // fb::IDevice

};

#endif
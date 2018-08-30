#ifndef _LockingController_H
#define _LockingController_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class LockingController
	{
	public:
		enum LockState
		{
			Idle,
			Locking,
			Locked,
		};
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void activate();	// V: 0x4
		virtual void deactivate();	// V: 0x8
		//LPVOID vftable;					// 0x00
		LockingControllerData* m_data;	// 0x04
		FLOAT m_currLockAmount;			// 0x08
		LockState m_lockState;			// 0x0C
		CHAR m_active;					// 0x10
		CHAR m_lastLockSuccessful;		// 0x11
		PAD(0x2);						// 0x12
		DWORD m_zoomLevel;				// 0x14
		LockType m_currentLockType;		// 0x18
	}; // 0x1C
};

#endif
#ifndef _LockingControllerState_H
#define _LockingControllerState_H
#include "Frostbite_Classes.h"
namespace fb
{
		class LockingControllerState
	{

		Vec3 pos;                     // this+0x0
		float currLockAmount;                     // this+0x10
		unsigned short targetGhostId;                     // this+0x14
		unsigned int lockState;                     // this+0x18, len(0x8)
		unsigned int targetValid;                     // this+0x20, len(0x1)
		unsigned int active;                     // this+0x21, len(0x1)
		unsigned int lastLockSuccessful;                     // this+0x22, len(0x1)

	}; // fb::LockingControllerState

};

#endif
#ifndef _ClientWeaponComponentState_H
#define _ClientWeaponComponentState_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ClientWeaponComponentState
	{

		ClientWeaponFiringReplicationState weaponFiring;                     // this+0x0
		LockingControllerState lockingController;                     // this+0x60
		LockingControllerState secondaryLockingController;                     // this+0x80
		WeaponComponent::WeaponState weaponState;                     // this+0xA0
		unsigned int maskWeaponFiringFlag;                     // this+0xA4, len(0x1)
		unsigned int maskLockingControllerFlag;                     // this+0xA5, len(0x1)
		unsigned int maskSecondaryLockingControllerFlag;                     // this+0xA6, len(0x1)
		unsigned int maskWeaponStateFlag;                     // this+0xA7, len(0x1)

	}; // fb::ClientWeaponComponentState

};

#endif
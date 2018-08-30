#ifndef _ClientWeaponFiringReplicationState_H
#define _ClientWeaponFiringReplicationState_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ClientWeaponFiringReplicationState
	{

		LinearTransform aiShootSpace;                     // this+0x0
		unsigned int weaponState;                     // this+0x40, len(0x10)
		unsigned int firedCount;                     // this+0x50, len(0x1)
		unsigned int ticks;                     // this+0x44
		float heat;                     // this+0x48
		FireLogicType fireLogicType;                     // this+0x4C
		unsigned int weaponFiringFlag;                     // this+0x50, len(0x1)
		unsigned int weaponFiringRareFlag;                     // this+0x51, len(0x1)
		unsigned int detonatorActive;                     // this+0x52, len(0x1)
		unsigned int useAiShootSpace;                     // this+0x53, len(0x1)

	}; // fb::ClientWeaponFiringReplicationState

};

#endif
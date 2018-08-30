#ifndef _WeaponFiringState_H
#define _WeaponFiringState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class WeaponFiringState
	{

		enum WeaponNetworkState
		{

			 WeaponIdle,                     // constant 0x0
			 WeaponSingleFiring,                     // constant 0x1
			 WeaponAutomaticFiring,                     // constant 0x2
			 WeaponReloading,                     // constant 0x3
			 WeaponBoltAction                     // constant 0x4

		}; // WeaponNetworkState

		/*enum fb::WeaponFiring::WeaponState*/ int weaponState;                     // this+0x0
		/*enum fb::WeaponFiring::WeaponState*/ int nextWeaponState;                     // this+0x4
		float timeToWait;                     // this+0x8
		float switchCooldownTimer;                     // this+0xC
		float stateData;                     // this+0x10
		float minDelay;                     // this+0x14
		int primaryProjectilesLoaded;                     // this+0x18
		int primaryProjectilesInMagazines;                     // this+0x1C
		int primaryNumberOfProjectilesToFire;                     // this+0x20
		float primaryHeat;                     // this+0x24
		float primaryOverheatTimer;                     // this+0x28
		int primaryExternalMagazineCapacity;                     // this+0x2C
		unsigned int ticks;                     // this+0x30
		enum fb::FireLogicType fireLogicType;                     // this+0x34
		unsigned int impulseDelay;                     // this+0x38, len(0x10)
		unsigned int firedCount;                     // this+0x48, len(0x1)
		unsigned int currentFireModeIndex;                     // this+0x3C
		bool primaryIsOverheated;                     // this+0x40, len(0x1)
		bool isDetonatorActive;                     // this+0x41, len(0x1)
		bool hasStoppedFiring;                     // this+0x42, len(0x1)
		bool primaryFireTriggeredLastFrame;                     // this+0x43, len(0x1)
		bool waitForFireRelease;                     // this+0x44, len(0x1)
		bool waitForZoomRelease;                     // this+0x45, len(0x1)

	}; // fb::WeaponFiringState

	

};

#endif
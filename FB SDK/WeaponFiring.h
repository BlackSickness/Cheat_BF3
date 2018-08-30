#ifndef _WeaponFiring_H
#define _WeaponFiring_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponFiringCallbackHandler.h"
#include "FB SDK/RefillableAmmunitionDepot.h"
#include "FB SDK/FiringFunctionData.h"
namespace fb
{
	
	class WeaponFiring
		: public WeaponFiringCallbackHandler,			// 0x00
		public RefillableAmmunitionDepot				// 0x8C
	{
	public:
		enum WeaponState
		{
			Deploy,
			AltDeploy,
			TriggerReleaseWait,
			NoTrigger,
			PreFireDelay,
			PrimarySingleDelay,
			PrimarySingle,
			BoltActionDelay,
			BoltAction,
			PrimaryAutomaticFire,
			ReloadDelay,
			Reload,
			PostReload,
			PrimaryHoldAndRelease_Hold,
			PrimaryHoldAndRelease_ReleaseDelay,
			PrimaryHoldAndRelease_Release,
			NumWeaponStates,
			WeaponStateSizeInBits,
		};

		class Function
		{
		public:
			PAD(0x4);
			INT projectilesLoaded; 						// 0x00 
			INT projectilesInMagazines; 				// 0x04 
			INT numberOfProjectilesToFire; 				// 0x08 
			CHAR hasStoppedFiring; 						// 0x0C 
			CHAR primaryFireTriggeredLastFrame; 		// 0x0D 
			CHAR isOverheated; 							// 0x0E 
			PAD(0x1);									// 0x0F
			FLOAT heat; 								// 0x10 
			FLOAT overheatTimer; 						// 0x14 
			DWORD ticks; 								// 0x18 
			DWORD currentFireModeIndex; 				// 0x1C 
			INT externalMagazineCapacity; 				// 0x20 
			GameObjectData* m_firingHolderData; 		// 0x24
			eastl::vector<FireLogicType> m_fireModes; 	// 0x28 
		};


		MemoryArena* m_arena;							// 0x90
		WeaponFiringData* m_data;						// 0x94
		AmmoConfigData* m_ammoData;						// 0x98
		GameObjectData* m_firingHolderData;				// 0x9C
		WeaponSway* m_weaponSway;						// 0xA0
		WeaponState m_weaponState;						// 0xA4
		WeaponState m_lastWeaponState;					// 0xA8
		WeaponState m_nextWeaponState;					// 0xAC
		FLOAT m_switchCooldownTimer;					// 0xB0
		FLOAT m_autoReplenishTime;						// 0xB4
		FLOAT m_timeToWait;								// 0xB8
		FLOAT m_stateData;								// 0xBC
		FLOAT m_holdReleaseMinDelay;					// 0xC0
		FLOAT m_recoilTimer;							// 0xC4
		FLOAT m_recoilAngleX;							// 0xC8
		FLOAT m_recoilAngleY;							// 0xCC
		FLOAT m_recoilAngleZ;							// 0xD0
		FLOAT m_recoilFovAngle;							// 0xD4
		FLOAT m_primaryAmmoReplenishDelay;				// 0xD8
		FLOAT m_reloadTimeMultiplier;					// 0xDC
		FLOAT m_overheatDropMultiplier;					// 0xE0
		INT m_primaryAmmoToFill;						// 0xE4
		WeakPtr<Entity> m_characterMeleeEntity;			// 0xE8
		INT m_externalPrimaryMagazineCapacity;			// 0xEC
		Function m_primaryFire;							// 0xF0
		WeaponModifier* m_weaponModifier;				// 0x128
		DWORD m_activeContext;							// 0x12C
		DWORD m_additionMagazines;						// 0x130
		DWORD m_impulseDelay;							// 0x134
	}; // 0x138

};

#endif
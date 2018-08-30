#ifndef _ClientSoldierWeapon_H
#define _ClientSoldierWeapon_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ClientGameEntity.h"
#include "FB SDK/WeaponLagEffect.h"
#include "FB SDK/WeaponModifier.h"
#include "FB SDK/WeaponFiringCallbacks.h"

namespace fb
{
	
	class ClientSoldierWeapon
		: public ClientGameEntity								// 0x00
	{
	public:
		class WeaponState
		{
		public:
			AnimatedSoldierWeapon* m_animation;				// 0x00
			eastl::vector<BoneFakePhysics*> m_fakePhysics;				// 0x04 <BoneFakePhysics*>
			DWORD m_meshVariationSet;						// 0x14 MeshVariationSet*
			DWORD m_meshZoomVariationSet;					// 0x18 MeshVariationSet*
			DWORD m_mesh;									// 0x1C ResourceProxy<MeshSet>
			DWORD m_meshZoom;								// 0x20 ResourceProxy<MeshSet>
			WORD m_meshInstanceHandle;						// 0x24
			WORD m_meshZoomInstanceHandle;					// 0x28
			DWORD m_projectileBoneIndex;					// 0x2C
		}; // 0x30

		class CorrectionCallbackHandler
			: public WeaponFiringCallbacks	// 0x00
		{
		public:
			AmmunitionDepot* m_ammoDepot;	// 0x04
		}; // 0x08

		
		PAD(0x8);												// 0x20
		eastl::vector<WeaponState> m_weaponStates1p;			// 0x28
		eastl::vector<WeaponState> m_weaponStates3p;			// 0x38
		eastl::vector<DWORD> m_socketPointers;					// 0x48 AttachableSocket (Size 0xA4)
		WeaponModifier m_weaponModifier;						// 0x58
		PAD(0x10);												// 0x130 //PADDED 4 BYTES, so everything below +4
		WeaponLagEffect* m_cameraLagEffect;								// 0x13C  WeaponLagEffect*
		ClientSoldierAimingSimulation* m_authorativeAiming;		// 0x140
		ClientAimingReplication* m_replicatedAiming;			// 0x144
		ClientLockingController* m_lockingController;			// 0x148
		ClientLockingController* m_secondaryLockingController;	// 0x14C
		ClientWeapon* m_weapon;									// 0x150
		ClientWeaponFiringReplication* m_replicatedFiring;		// 0x154
		CorrectionCallbackHandler* m_correctionCallbackHandler;	// 0x158
		WeaponFiring* m_predictedFiring;						// 0x15C
		WeaponFiring* m_correctedFiring;						// 0x160
		ResourceCompartment m_compartment;						// 0x164
		WORD m_weaponInstanceId;								// 0x168
		PAD(0x2);												// 0x16A
		INT m_projectileBoneIndex;								// 0x16C
		DWORD m_1pResourceCompartment;							// 0x170 SoldierWeaponResourceCompartment*
		//new
		BYTE m_hasAttachedEntities;                                                             // 0x174
        BYTE m_willAlwaysBe3p;  
	};

};

#endif
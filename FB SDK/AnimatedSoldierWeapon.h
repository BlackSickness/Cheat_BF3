#ifndef _AnimatedSoldierWeapon_H
#define _AnimatedSoldierWeapon_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ReplicatedBoolSignal.h"
#include "FB SDK/AnimatedSoldierWeaponSpeedModule.h"
#include "FB SDK/AnimatedSoldierWeaponOffsetModule.h"
#include "FB SDK/AnimatedSoldierWeaponZoomModule.h"
#include "FB SDK/AnimatedSoldierWeaponSprintModule.h"
#include "FB SDK/AnimatedSoldierWeaponShootModule.h"
namespace fb
{
	class AnimatedSoldierWeapon
		: WeaponFiringCallbacks								// 0x00
	{	
	public:
		DWORD m_weapon;										// 0x04
		WeaponFiringData* m_weaponFiringData;				// 0x08
		WeaponModifier* m_weaponModifier;					// 0x0C
		DWORD m_weaponStateData;							// 0x10
		SoldierAimingSimulationData* m_aimingData;			// 0x14
		INT m_weaponType;									// 0x18
		AnimatedSoldierWeaponSprintModule m_sprintModule;	// 0x1C
		AnimatedSoldierWeaponShootModule m_shootModule;		// 0x20
		AnimatedSoldierWeaponZoomModule m_zoomModule;		// 0x28
		AnimatedSoldierWeaponOffsetModule m_offsetModule;	// 0x38
		AnimatedSoldierWeaponSpeedModule m_speedModule;		// 0x40
		PAD(0xC);											// 0x44
		Vec3 m_eyePosition;									// 0x50
		Vec3 m_aimAtPosition;								// 0x60
		FLOAT m_reloadTimer;								// 0x70
		FLOAT m_zoomTimer;									// 0x74
		FLOAT m_aimTimer;									// 0x78
		FLOAT m_aimBlendTimer;								// 0x7C
		FLOAT m_aimYaw;										// 0x80
		FLOAT m_aimPitch;									// 0x84
		FLOAT m_aimBodyBlendTime;							// 0x88
		FLOAT m_dispersion;									// 0x8C
		FLOAT m_disableZoomToggleWeight;					// 0x90
		FLOAT m_cameraLockWeight;							// 0x94
		INT m_bulletsLeftInGun;								// 0x98
		INT m_quickThrowType;								// 0x9C
		INT m_weaponAnimType;								// 0xA0
		INT m_animatedFireType;								// 0xA4
		INT m_fireLogicType;								// 0xA8
		//CHAR m_isFiring;									// 0xAC
		//PAD(0x3);
		// new
		ReplicatedBoolSignal m_isFiring;                     // 0xAC
		byte m_firstShotSpawned;                     // 0xAE, len(0x1)
		byte m_boltAction;                     // 0xAF, len(0x1)
		byte m_isMeleeAttacking;                     // 0xB0, len(0x1)
		byte m_isReloading;                     // 0xB1, len(0x1)
		byte m_isAltDeploying;                     // 0xB2, len(0x1)
		byte m_quickSwitch;                     // 0xB3, len(0x1)
		byte m_fireModeChanged;                     // 0xB4, len(0x1)
		byte m_isActive;                     // 0xB5, len(0x1)
		byte m_isDeployed;                     // 0xAF, len(0x1)
		byte m_isUndeployed;                     // 0xB0, len(0x1)
		byte m_isZooming;                     // 0xB1, len(0x1)
		byte m_isOneHanded;                     // 0xB2, len(0x1)
		byte m_isOneHandedAiming;                     // 0xB3, len(0x1)
		byte m_isGunLowered;                     // 0xB4, len(0x1)
		byte m_aimingEnabled;                     // 0xB5, len(0x1)
		byte m_wasAiming;                     // 0xB6, len(0x1)
		byte m_keepAiming;                     // 0xB0, len(0x1)
		byte m_useAimTimer;                     // 0xB1, len(0x1)
		byte m_breathControl;                     // 0xB2, len(0x1)
		byte m_undeployFinished;                     // 0xB3, len(0x1)
		byte m_weaponLightEnabled;                     // 0xB4, len(0x1)
		byte m_quickThrow;                     // 0xB5, len(0x1)
	
	}; // 0xD0

};

#endif
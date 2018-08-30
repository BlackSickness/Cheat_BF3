#ifndef _FiringFunctionData_H
#define _FiringFunctionData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/CtrRefBase.h"
#include "FB SDK/GameDataContainer.h"
#include "FB SDK/FiringDispersionData.h"
namespace fb
{

	class FireEffectData
	{
	public:
		Vec3 m_rotation;				// 0x00
		Vec3 m_offset;					// 0x10
		Vec3 m_zoomRotation;			// 0x20
		Vec3 m_zoomOffset;				// 0x30
		DataContainer* m_effect;		// 0x40
		CHAR m_useZoomOffset;			// 0x44
		CHAR m_useZoomRotation;			// 0x45
		CHAR m_disableDuringZoom;		// 0x46
		CHAR m_updateTransform;			// 0x47
		CHAR m_stopLoopingEffects;		// 0x48
		PAD(0x3);						// 0x49
	}; // 0x4C


	class WeaponFiringData
		: public GameDataContainer				// 0x00
	{
	public:
		FiringFunctionData* m_primaryFire;		// 0x08
		FLOAT m_deployTime;						// 0x0C
		FLOAT m_reactivateCooldownTime;			// 0x10
		FLOAT m_altDeployTime;					// 0x14
		PAD(0x4);								// 0x18
		INT m_shotLimit;						// 0x1C
		DataContainer* m_weaponSway;			// 0x20
		FLOAT m_supportDelayProne;				// 0x24
	}; // 0x28

	

	class SoldierWeaponDispersion
	{
	public:
		FiringDispersionData m_standDispersion;		// 0x00
		FiringDispersionData m_crouchDispersion;	// 0x10
		FiringDispersionData m_proneDispersion;		// 0x20
		FLOAT m_jumpDispersionAngle;				// 0x30
		FLOAT m_proneTransitionDispersionAngle;		// 0x34
		FLOAT m_moveDispersionAngle;				// 0x38
		FLOAT m_moveZoomedDispersionAngle;			// 0x3C
		FLOAT m_decreasePerSecond;					// 0x40
	}; // 0x44

	class ShotConfigData
	{
	public:
		Vec3 m_initialPosition; 							// 0x00 
		Vec3 m_initialDirection; 							// 0x10 
		Vec3 m_initialSpeed; 								// 0x20 
		FLOAT m_inheritWeaponSpeedAmount; 					// 0x30 
		DWORD m_muzzleExplosion; 							// 0x34 
		BulletEntityData* m_projectileData; 			// 0x38 
		BulletEntityData* m_secondaryProjectileData; 	// 0x3C 
		CtrRefBase m_projectile; 								// 0x40 
		CtrRefBase m_secondaryProjectile; 						// 0x44 
		FLOAT m_spawnDelay; 								// 0x48 
		DWORD m_numberOfBulletsPerShell;				 	// 0x4C 
		DWORD m_numberOfBulletsPerShot;						// 0x50 
		DWORD m_numberOfBulletsPerBurst;					// 0x54 
		CHAR m_relativeTargetAiming; 						// 0x58 
		CHAR m_forceSpawnToCamera; 							// 0x59 
		CHAR m_spawnVisualAtWeaponBone;						// 0x5A 
		CHAR m_activeForceSpawnToCamera;				 	// 0x5B 
	}; // 0x5C

	class WeaponSuppressionData
		: public DataContainer		// 0x00
	{
	public:
		FLOAT m_maxMultiplier;		// 0x08
		FLOAT m_minMultiplier;		// 0x0C
		FLOAT m_minDistance;		// 0x10
		FLOAT m_maxDistance;		// 0x14
	}; // 0x18

	class HoldAndReleaseData
	{
	public:
		FLOAT m_maxHoldTime;					// 0x00
		FLOAT m_minPowerModifier;				// 0x04
		FLOAT m_maxPowerModifier;				// 0x08
		FLOAT m_powerIncreasePerSecond;			// 0x0C
		FLOAT m_delay;							// 0x10
		FLOAT m_killedHoldingPowerModifier;		// 0x14
		INT m_forceFireWhenKilledHolding;		// 0x18
	}; // 0x1C

	class BoltActionData
	{
	public:
		FLOAT m_boltActionDelay;				// 0x00
		FLOAT m_boltActionTime;					// 0x04
		CHAR m_holdBoltActionUntilFireRelease;	// 0x08
		CHAR m_holdBoltActionUntilZoomRelease;	// 0x09
		CHAR m_forceBoltActionOnFireTrigger;	// 0x0A
		CHAR m_unZoomOnBoltAction;				// 0x0B
		CHAR m_returnToZoomAfterBoltAction;		// 0x0C
		PAD(3);									// 0x0D
	}; // 0x10

	class RecoilData
	{
	public:
		FLOAT m_maxRecoilAngleX;			// 0x00
		FLOAT m_minRecoilAngleX;			// 0x04
		FLOAT m_maxRecoilAngleY;			// 0x08
		FLOAT m_minRecoilAngleY;			// 0x0C
		FLOAT m_maxRecoilAngleZ;			// 0x10
		FLOAT m_minRecoilAngleZ;			// 0x14
		FLOAT m_maxRecoilFov;				// 0x18
		FLOAT m_minRecoilFov;				// 0x1C
		INT m_recoilFollowsDispersion;		// 0x20
	}; // 0x24

	class FireLogicData
	{
	public:
		HoldAndReleaseData m_holdAndRelease;				// 0x00
		BoltActionData m_boltAction;						// 0x1C
		RecoilData m_recoil;								// 0x2C
		EntryInputActionEnum m_fireInputAction; 			// 0x50
		EntryInputActionEnum m_reloadInputAction; 			// 0x54
		EntryInputActionEnum m_cycleFireModeInputAction; 	// 0x58
		FLOAT m_triggerPullWeight; 							// 0x5C 
		FLOAT m_rateOfFire; 								// 0x60
		FLOAT m_rateOfFireForBurst; 						// 0x64 
		FLOAT m_clientFireRateMultiplier; 					// 0x68 
		FLOAT m_reloadDelay; 								// 0x6C 
		Array<FireLogicType> m_fireLogicTypeArray; 			// 0x70
		FLOAT m_reloadThreshold; 							// 0x74 
		FLOAT m_preFireDelay; 								// 0x78 
		FLOAT m_reloadTime; 								// 0x7C 
		FLOAT m_reloadTimeBulletsLeft; 						// 0x80
		FireLogicType m_fireLogicType; 						// 0x84 
		ReloadLogic m_reloadLogic; 							// 0x88 
		FLOAT m_automaticDelay; 							// 0x8C 
		ReloadType m_reloadType; 							// 0x90 
		CHAR m_holdOffReloadUntilZoomRelease; 				// 0x94 
		CHAR m_forceReloadActionOnFireTrigger; 				// 0x95 
		CHAR m_holdOffReloadUntilFireRelease; 				// 0x96 
		CHAR m_alwaysAutoReload; 							// 0x97 
	}; // 0x98

	class AmmoConfigData
	{
	public:
		INT m_magazineCapacity; 				// 0x00 
		INT m_numberOfMagazines; 				// 0x04 
		DWORD m_traceFrequency; 				// 0x08 
		DWORD m_ammoPickupMinAmount; 			// 0x0C 
		DWORD m_ammoPickupMaxAmount; 			// 0x10 
		FLOAT m_autoReplenishDelay; 			// 0x14 
		INT m_ammoBagPickupAmount; 				// 0x18 
		FLOAT m_ammoBagPickupDelayMultiplier; 	// 0x1C 
		INT m_autoReplenishMagazine; 			// 0x20 
	}; // 0x24

	class OverHeatData
	{
	public:
		FLOAT m_heatPerBullet;				// 0x00
		FLOAT m_heatDropPerSecond;			// 0x04
		FLOAT m_overHeatPenaltyTime;		// 0x08
		FLOAT m_overHeatThreshold;			// 0x0C
		FireEffectData m_overHeatEffect;	// 0x10
	}; // 0x5C
		class FiringFunctionData
		: public DataContainer						// 0x00
	{
	public:
		Array<FiringDispersionData> m_dispersion;	// 0x08
		SoldierWeaponDispersion m_weaponDispersion;	// 0x0C
		Array<FireEffectData> m_fireEffects1p;		// 0x50
		Array<FireEffectData> m_fireEffects3p;		// 0x54
		DataContainer* m_sound;						// 0x58
		PAD(0x4);									// 0x5C
		ShotConfigData m_shot;						// 0x60
		PAD(0x4);									// 0xBC
		FireLogicData m_fireLogic;					// 0xC0
		AmmoConfigData m_ammo;						// 0x158
		PAD(0x4);									// 0x17C
		OverHeatData m_overHeat;					// 0x180
		PAD(0x4);									// 0x1DC
		FLOAT m_selfHealTimeWhenDeployed;			// 0x1E0
		FLOAT m_ammoCrateReloadDelay;				// 0x1E4
		CHAR m_unlimitedAmmoForAI;					// 0x1E8
		CHAR m_usePrimaryAmmo;						// 0x1E9
		PAD(0x2);									// 0x1EA
	}; // 0x1EC
};

#endif
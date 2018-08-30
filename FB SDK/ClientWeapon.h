#ifndef _ClientWeapon_H
#define _ClientWeapon_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/Weapon.h"
#include "FB SDK/WeaponFiringCallbackHandler.h"
#include "FB SDK/ControllableFinder.h"
namespace fb
{
	
	class ClientWeapon
		: public Weapon,														// 0x00
		public WeaponFiringCallbacks,											// 0x120
		public WeaponFiringCallbackHandler										// 0x124
	{
	public:
		// new class
		class FireFxEffectHandle
		{
			DWORD fireEffect;
			int handle;
		};

		class ProjectileSyncInfo
		{
		public:
			ProjectileBlueprint* projectile;		// 0x00
			BulletEntityData* projectileData;	// 0x04
			INT localPlayer;						// 0x08
			WeaponFiringShooter* shooterArg;		// 0x0C
			LinearTransform shootSpace;				// 0x10
			LinearTransform visualShootSpace;		// 0x50
			Vec3 initialSpeed;						// 0x90
			DWORD randomSeed;						// 0xA0
			INT trace;								// 0xA4
			Vec3* targetPosition;					// 0xA8
			ClientPhysicsEntity* targetObject;		// 0xAC
			FLOAT damageMultiplier;					// 0xB0
			FLOAT explosionDamageMultiplier;		// 0xB4
			DWORD weaponUnlockAsset;				// 0xB8
		}; // 0xBC

		EntityBus* m_entityBus;													// 0x1B0
		AmmunitionDepot* m_ammoDepot;											// 0x1B4
		FLOAT m_cameraFov;														// 0x1B8
		FLOAT m_weaponFov;														// 0x1BC
		FLOAT m_fovScaleFactor;													// 0x1C0
		DataContainer* m_primaryWeaponSound;									// 0x1C4
		DWORD m_zoomLevel;														// 0x1C8
		CHAR m_zoomLevelLocked;													// 0x1CC
		CHAR m_playFire;														// 0x1CD
		CHAR m_stopFire;														// 0x1CE
		PAD(0x1);																// 0x1CF
		ControllableFinder m_controllableFinder;								// 0x1D0
		DWORD m_overheatEffectHandle;											// 0x6B0
		eastl::pair<UINT, FireEffectData*> m_fireFxHandles[8];					// 0x6B4
		DWORD m_fireFxEffectHandleSz;											// 0x6F4
		CHAR m_callbackCalledThisFrame[2];										// 0x6F8
		PAD(0x2);																// 0x6FA
		WeakPtr<WeaponFiringShooter> m_shooter;									// 0x6FC
		WeakPtr<ClientGameEntity> m_targetEntity;								// 0x700
		FLOAT m_lockTime;														// 0x704
		FLOAT m_aimUpdateTimer;													// 0x708
		FLOAT m_fireRateCount;													// 0x70C
		CHAR m_hasFriendlyTarget;												// 0x710
		CHAR m_hasEnemyTarget;													// 0x711
		CHAR m_hasVehicleTarget;												// 0x712
		CHAR m_hasSoldierTarget;												// 0x713
		DWORD m_weakTokenHolder;												// 0x714
		eastl::vector<ProjectileSyncInfo> m_bulletsToSpawnOnSyncUpdate;			// 0x718
		WeakPtr<ClientControllableEntity> m_owner;						// 0x728
	}; // 0x728

};

#endif
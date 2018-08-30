#ifndef _ClientVehicleEntity_H
#define _ClientVehicleEntity_H
#include "Frostbite_Classes.h"
#include "ClientControllableEntity.h"
#include "VehicleEntity.h"
namespace fb
{
	
	class ClientVehicleEntity
		: public ClientControllableEntity,								// 0x00
		public network::Interpolator<LPVOID>,							// 0xB4
		public VehicleEntity											// 0xF4
	{
	public:
		class LockableCallback
		{
		public:
			//LPVOID vftable;		// 0x00
			virtual float isLockable(LockType, bool &);
		}; // 0x04

		PAD(0x4);														// 0x108
		AxisAlignedBox m_childrenAabb;									// 0x110
		Vec3 m_dirtColor;												// 0x130
		Vec3 m_prevSpeed;												// 0x140
		Vec3 m_prev2Speed;												// 0x150
		FLOAT m_prevDeltaTime;											// 0x160
		network::ClientNetworkableGroup m_networkableGroup;				// 0x164
		ClientChassisComponent* m_chassis;								// 0x1FC
		ClientVehicleEntityHealth* m_vehicleHealth;						// 0x200
		WeakPtr<ClientPlayer> m_remoteControlledDamageGiverPlayer;		// 0x204
		DWORD m_meshModel;												// 0x208 MeshModel*
		DWORD m_cockpitMeshModel;										// 0x20C MeshModel*
		DWORD m_vehicleSound;											// 0x210 VehicleSound*
		LockableCallback* m_lockableCallback;							// 0x214
		DWORD m_upgradableCallback;										// 0x218
		
		int m_decalSet;                     // this+0x260
		short m_lightProbeHandle;                     // this+0x264
		float m_dirtFactor;                     // this+0x268
		float m_effectVolumeAccumulated;                     // this+0x26C
		 int m_preExplosionEffectHandle;                     // this+0x270
		 int m_criticallyDamagedEffectHandle;                     // this+0x274
		class fb::Entity * * m_ownedEntities;                     // this+0x278
		 char m_ownedEntityCount;                     // this+0x27C
		 char m_childrenAabbIsDirty;                     // this+0x27D, len(0x1)
		 char m_soundPlaying;                     // this+0x27E, len(0x1)
		 char m_lockAmountId;                     // this+0x27F, len(0x5)
		 char m_healthId;                     // this+0x27E, len(0x5)
		 char m_playingCutscene;                     // this+0x283, len(0x1)
		PropertyWriter m_frontShieldActive;                     // this+0x280
		PropertyWriter m_rearShieldActive;                     // this+0x284
		PropertyWriter m_leftShieldActive;                     // this+0x288
		PropertyWriter m_rightShieldActive;                     // this+0x28C
		PropertyWriter m_currentVelocity;                     // this+0x290
		bool m_isCustomizationVehicle;                     // this+0x294
		VehicleEntity::DamageState m_damageState;      

	};

};

#endif
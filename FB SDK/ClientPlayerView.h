#ifndef _ClientPlayerView_H
#define _ClientPlayerView_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ClientPlayerView
		: public network::ClientGhost,									// 0x00
		public network::Interpolator<LPVOID>,							// 0x40
		public network::IClientNetworkable								// 0x80
	{
	public:
		eastl::fixed_vector<ClientSubView*, 4, 2> m_subViews;			// 0x88
		ClientPlayer* m_owner;											// 0xAC
		eastl::fixed_vector<WeakPtr<ClientPlayer>, 8, 2> m_spectators;	// 0xB0
		FLOAT m_giveDamageTime;											// 0xE4
		FLOAT m_damageGivenToDamageEntity;								// 0xE8
		WeakPtr<ClientVehicleEntity> m_vehicleInteractionEntity;		// 0xEC
		DWORD m_lastWeaponPickupTick;									// 0xF0
		DWORD m_lastAmmoPickupTick;										// 0xF4
		PAD(0x8);														// 0xF8
		Vec3 m_soldierHitPosition;										// 0x100 Ignore Z
		Vec3 m_soldierHitDirection;										// 0x110 Ignore Z
		Vec3 m_soldierHitGiverOrigin;									// 0x120 Ignore Z
		Vec3 m_vehicleHitDirection;										// 0x130 Ignore Z
		FLOAT m_soldierHitDamage;										// 0x140
		CHAR m_isBulletDamage;											// 0x144
		CHAR m_hasSuppressedEnemy;										// 0x145
		PAD(0x2);														// 0x146
		FLOAT m_lockAmount;												// 0x148
		CHAR m_vehicleHitDirectionUpdated;								// 0x14C
		CHAR m_squadSpawnAllowed;										// 0x14D
		PAD(0x2);														// 0x14E
		FLOAT m_spawnIsAllowedTimer;									// 0x150
		FLOAT m_warmUpTimer;											// 0x154
		FLOAT m_timeToRespawn;											// 0x158
		FLOAT m_lastRespawnTime;										// 0x15C
		ClientCameraContext* m_cameraContext;							// 0x160
	}; // 0x164


};

#endif
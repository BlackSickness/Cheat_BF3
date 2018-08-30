#ifndef _Server_H
#define _Server_H

//#include "../Frostbite_classes.h"

namespace fb
{

		class ServerPlayerView
		:public network::ServerGhost, network::IServerNetworkable ,MessageListener
	{
	public:
		PAD(12);
		
		/*class eastl::fixed_vector<fb::ServerSubView *,4,1,fb::eastl_arena_allocator> */ void* m_subViews;                     // 0x74
		ServerPlayer * m_owner;                     // 0x98
	/*	class eastl::fixed_vector<fb::ServerPlayer *,8,1,fb::eastl_arena_allocator>*/void* m_spectators;                     // 0x9C
		/*WeakPtr<fb::ServerCameraContext>*/ void*  m_cameraContext;                     // 0xD0
		Vec3 m_cameraPosition;                     // 0xE0
		Vec3 m_soldierHitDirection;                     // 0xF0
		Vec3 m_soldierHitPosition;                     // 0x100
		Vec3 m_soldierHitGiverOrigin;                     // 0x110
		float m_soldierHitDamage;                     // 0x120
		Vec3 m_vehicleHitDirection;                     // 0x130
		float m_lockAmount;                     // 0x140
	/*	ServerControllableEntity * */void*m_inputTarget;                     // 0x144
		unsigned int m_inputTargetEntryId;                     // 0x148
		float m_damageGivenToLastGiveDamageEntity;                     // 0x14C
		/*WeakPtr<fb::ServerVehicleEntity> */void*m_vehicleInteractionEntity;                     // 0x150
		bool m_hasSuppressedEnemy;                     // 0x154
		float m_spawnIsAllowedTimer;                     // 0x158
		float m_warmUpTimer;                     // 0x15C
		float m_timeToRespawn;                     // 0x160
		bool m_squadSpawnIsAllowed;                     // 0x164
		bool m_bulletDamage;                     // 0x165

		//virtual void * __vecDelDtor(unsigned int);	// V: 0x0
	}; // fb::ServerPlayerView

	/*
	class SoldierWeaponUnlockAsset
		:public UnlockAssetBase // Inherited class at offset 0x0
	{

		virtual void * __vecDelDtor(unsigned int);	// V: 0x4
		CtrRefBase m_weapon;                     // this+0x64
		CtrRefBase m_extra;                     // this+0x68
			

	}; // fb::SoldierWeaponUnlockAsset*/

	class ServerPlayer//public: Player
		:	public Player,	// Inherited class at offset 0x0
			public network::ServerGhost, // Inherited class at offset 0x328
			public network::IServerNetworkable, // Inherited class at offset 0x384
			public MessageListener // Inherited class at offset 0x394
	{
	public:
																																																														/*class fb::Player // Inherited class at offset 0x0
		PAD(4);
		BitArray m_unlocksBitArray;                     // 0x39C
		/*class fb::ScopedPtr<fb::ServerPlayerView>*/ void* m_ownPlayerView;                     // 0x3B0
		ServerPlayerView *m_playerView;                     // 0x3B4
		PAD(4);
		unsigned int m_id;                     // 0x3B8
		unsigned char m_connectionId;                     // 0x3BC
		EntryInput * m_entryInput;                     // 0x3C0
	/*	class fb::ServerSoldierEntity **/ void * m_soldier;                     // 0x3C4
	/*	class fb::ServerCharacterEntity * */ void *m_character;                     // 0x3C8
	/*	class fb::WeakPtr<fb::ServerSoldierEntity> */ void *m_soldierCorpse;                     // 0x3CC
	/*	class fb::ServerSoldierEntity * */ void *m_customizationSoldier;                     // 0x3D0
		unsigned int m_attachedPartId;                     // 0x3D4
		unsigned int m_attachedEntryId;                     // 0x3D8
	/*	class fb::ServerControllableEntity * */ void *m_attachedControllable;                     // 0x3DC
		unsigned int m_oldAttachedPartId;                     // 0x3E0
		unsigned int m_oldAttachedEntryId;                     // 0x3E4
	/*	class fb::WeakPtr<fb::ServerControllableEntity>*/ void * m_oldAttachedControllable;                     // 0x3E8
		unsigned int m_controlledEntryId;                     // 0x3EC
	/*	class fb::ServerControllableEntity **/ void * m_controlledControllable;                     // 0x3F0
		bool m_isIngame;                     // 0x3F4
		float m_timeAlive;                     // 0x3F8
	/*	class fb::WeakPtr<fb::ServerVehicleEntity>*/ void * m_currentVehicleInteractionEntity;                     // 0x3FC
	/*	class fb::WeakPtr<fb::ServerVehicleEntity>*/ void * m_oldVehicleInteractionEntity;                     // 0x400
		bool m_voicePluggedIn;                     // 0x404
		bool m_voiceThroughSpeakers;                     // 0x405
		bool m_isTalking;                     // 0x406
		bool m_isTalkingOnTheRadio;                     // 0x407
		
		class ViewGhostFilter 
			:public network::ServerGhostFilter // Inherited class at offset 0x0
		{
		public:
	/*	class fb::ServerPlayerView * */void *m_view;       // 0x4
		}; // ViewGhostFilter
		/*WeakPtr<ServerPlayer::ViewGhostFilter>*/void* m_viewGhostFilter;                     // 0x408
	/*	class WeakPtr<fb::ServerGameView> */ void *m_gameView;                     // 0x40C
		bool m_clientControlledCamera;                     // 0x410
		LinearTransform m_clientCameraTransform;                     // 0x420
		Vec3 m_deathPosition;                     // 0x460
	/*	class fb::SmartRef<fb::SoldierBlueprint const >*/void* m_selectedKit;                     // 0x470
		float m_ammoCrateTimer;                     // 0x474
		float m_ammoPickupTimer;                     // 0x478
		float m_vehicleInteractTimer;                     // 0x47C
		float m_switchTeamTimer;                     // 0x480
		float m_forcedSwitchTeamTimer;                     // 0x484
		float m_joinedTeamTimer;                     // 0x488
		bool m_isLevelLoaded;                     // 0x48C
		bool m_isLevelLinked;                     // 0x48D
		bool m_hasEnteredLevel;                     // 0x48E
		bool m_isAllowedToSpawn;                     // 0x48F
		bool m_isLoadingFromSave;                     // 0x490
		float m_ghostCreationWaitingTime;                     // 0x494
		int m_ghostCreationCount;                     // 0x498
		float m_interactionTimer;                     // 0x49C
		bool m_gotChangeVehicleAction;                     // 0x4A0
	/*	class fb::WeakTokenHolder*/ DWORD m_weakTokenHolder;                  // 0x4A4
		TeamId m_lastKilledByTeamId;                     // 0x4A8
		class PlayerWeaponSelection
		{

		/*	const class fb::SoldierWeaponUnlockAsset * */ void * m_weapon;                     // 0x0
			const class fb::UnlockAssetBase * m_unlocks;     //[0x5]                // 0x4
			unsigned int m_unlockCount;                     // 0x18

		}; // PlayerWeaponSelection

		class SoldierCustomization
		{

		/*	class eastl::fixed_vector<fb::UnlockAsset const *,16,1,fb::eastl_arena_allocator> */ void * visual;                     // 0x0
		/*		class eastl::fixed_vector<fb::ServerPlayer::PlayerWeaponSelection,10,1,fb::eastl_arena_allocator> */ void * weapons;                     // 0x54
						
		}; // <unnamed-type-m_soldierCustomization>

		SoldierCustomization m_soldierCustomization;                     // 0x4AC
	//	virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::ServerPlayer


	class ServerGameEntity :public GameEntity // Inherited class at offset 0x0
	{
		enum 
		{
			kVersion =0x1                     // constant 0x1

		}; // <unnamed-tag>
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x24
	}; 




	class ServerControllableEntity  //class fb::ServerGhostAndNetworkableGameEntity<fb::ServerPhysicsEntity,fb::ControllableEntityData> // Inherited class at offset 0x0
		:public ControllableEntity
	{
	public:
		PAD(204);
		
		int	kVersion;            // constant 0x1
		

		virtual void writeServerState(unsigned int, /*class fb::IBitStreamWrite **/void*, /*class fb::ControlObjectState **/void*, /*const class fb::ControlObjectState **/void*);	// V: 0x14C
		/*class eastl::fixed_vector<fb::EntryInput *,2,1,fb::eastl_arena_allocator>*/ void* m_externalInput;                     // 0xE0
		/*class eastl::vector<fb::ServerEntryComponent *,fb::eastl_arena_allocator>*/void* m_entries;                     // 0xFC
	/*	class fb::ServerSpawnEntity */void * m_owner;                     // 0x10C
		/*enum fb::EntryEnterRestriction */int m_enterRestriction;                     // 0x110
		String m_blueprintName;                     // 0x114
		String m_blueprintBundleName;                     // 0x118
		/*class fb::PropertyWriter<float> */ void* m_currentVelocityNormalizedOut;                     // 0x11C
		/*class fb::PropertyWriter<float> */ void* m_currentHealthNormalizedOut;                     // 0x120
		float m_oldVelocity;                     // 0x124
		float m_currentHealth;                     // 0x128
		virtual void * __vecDelDtor(unsigned int);	// V: 0x24

	}; // fb::ServerControllableEntity




	class ServerCharacterEntity 
		: public	ServerControllableEntity, // Inherited class at offset 0x0
					CharacterEntity // Inherited class at offset 0x130
	{
			enum 
			{
				kVersion                // constant 0x1
			}; // <unnamed-tag>

			ServerPlayer * m_player;                     // 0x134
			/*class fb::ServerAntAnimatableComponent */void* m_animatableComponent;                     // 0x138
			/*class fb::ServerCharacterHealthComponent */ void* m_healthComponent;                     // 0x13C
			Entity * * m_ownedEntities;                     // 0x140
			unsigned char m_ownedEntityCount;                     // 0x144
			virtual void * __vecDelDtor(unsigned int);	// V: 0x24

		}; // fb::ServerCharacterEntity



};

#endif
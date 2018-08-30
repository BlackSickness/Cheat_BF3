#ifndef _ClientPlayer_H
#define _ClientPlayer_H
#include "Player.h"
#include "WeaponFiringShooter.h"
namespace fb
{
	class ClientPlayer
		: public Player,										// 0x00
		public network::ClientGhost,							// 0x320
		public network::IClientNetworkable,						// 0x360
		public network::Interpolator<LPVOID>					// 0x368
	{
	public:
		class ClientPlayerShooter
			: public WeaponFiringShooter		// 0x00
		{
		public:
			ClientPlayer* m_player;				// 0x08
		}; // 0x0C
		/*
		virtual unsigned char fb::ClientPlayer::getNetClassId();
		virtual void fb::ClientPlayer::ghostRead();
		virtual void fb::ClientPlayer::readNetInit();
		virtual const char* fb::ClientPlayer::getNetClassName();
		virtual const char* fb::ClientPlayer::getNetName();
		virtual void fb::ClientPlayer::interpolate();
		virtual void fb::ClientPlayer::extrapolate();
		virtual void fb::ClientPlayer::applyState();
		virtual void fb::ClientPlayer::applyState(bool a2);
		virtual unsigned int fb::ClientPlayer::getId();
		virtual bool fb::ClientPlayer::isInVehicle();
		virtual bool fb::ClientPlayer::hasUnlockAsset();
		virtual bool fb::ClientPlayer::isUnlocked();
		virtual EntryComponent* fb::ClientPlayer::getEntry();
		virtual SoldierEntity* fb::ClientPlayer::getSoldier();
		virtual   fb::ClientPlayer::~ClientPlayer( );
	*/
		BitArray m_unlocksBitArray;								// 0x3A8
		INT m_refCount;											// 0x3BC
		WeakPtr<ClientSoldierEntity> m_soldier;					// 0x3C0
		WeakPtr<ClientSoldierEntity> m_corpse;					// 0x3C4
		WeakPtr<ClientCharacterEntity> m_character;				// 0x3C8
		WeakTokenHolder m_weakTokenHolder;						// 0x3CC
		ClientControllableEntity* m_attachedControllable;		// 0x3D0
		DWORD m_attachedEntryId;								// 0x3D4
		ClientControllableEntity* m_controlledControllable;		// 0x3D8
		DWORD m_controlledEntryId;								// 0x3DC
		EntryInput* m_input;									// 0x3E0
		EntryInputState* m_inputState;							// 0x3E4
		EntryInputState* m_externalInputState;					// 0x3E8
		DWORD m_id;												// 0x3EC
		DWORD m_connectionId;									// 0x3F0
		INT m_lastTeamHit;										// 0x3F4
		INT m_inputNetworkId;									// 0x3F8
		ClientEntryComponent* m_oldEntry;						// 0x3FC
		ClientPlayerShooter* m_shooter;							// 0x400
		ClientPlayerManager* m_playerManager;					// 0x404
		ClientPlayerView* m_ownPlayerView;						// 0x408
		ClientPlayerView* m_playerView;							// 0x40C
		PAD(0x4);												// 0x410
		EntryInputActionMap* m_inputActionMap;					// 0x414
		EntryInputTranslator* m_inputTranslator;				// 0x418
		short m_finalScore;										// 0x41C
		byte m_finalScoreSet;									// 0x41E
		byte m_visible;											// 0x41f len(0x1)
		byte m_hasInput;										// this+0x420, len(0x1)
		byte m_isDeleted;										// this+0x421, len(0x1)
		byte m_isLocal;											// this+0x422, len(0x1)
		byte m_flipY;											// this+0x423, len(0x1)
		byte m_flipCameraY;										// this+0x424, len(0x1)
		byte m_externalInputStateValid;							// this+0x425, len(0x1)
		byte m_externalInputStateOverride;                      // this+0x426, len(0x1)
		PAD(0x45);												// 0x427
		int		m_squadId;										// 0x46C
        byte    m_isSquadLeader;								// 0x470
        byte    m_isSquadPrivate;								// 0x471
        byte    m_isAllowedToSpawnOn;							// 0x472
        byte    m_isAdmin;										// 0x473
		float m_blinkNametagTimer;								// 0x474
		float m_antiSpamBlockedTime;							// 0x478
		float m_antiSpamBlockedMaxTime;							// 0x47C
		PAD(0x10);												// 0x480
        char    am_name[64];									// 0x490 size 0x10
		PAD(0xc8);												// 0x4A0
		char m_playerTag[0x5];									// this+0x13C
		unsigned int m_currentWeaponTotalKills;   				// 0x568
	public:
		ClientSoldierEntity* getSoldierEnt()
		{
			if(m_attachedControllable)
				return m_soldier.GetData();
	
			return (ClientSoldierEntity*)m_controlledControllable;
		}

		ClientSoldierEntity* getClientSoldierEntity()
		{
			DWORD dwSoldier = ( DWORD )this->getSoldier();

			if( dwSoldier )
				return ( fb::ClientSoldierEntity* )( dwSoldier - 0xF0 + 0x10);
            
			return NULL;
		}  

		ClientControllableEntity* getControllable()
		{
			if (m_attachedControllable)
			return (ClientControllableEntity*)m_attachedControllable; // vehicles
			return (ClientControllableEntity*)m_controlledControllable; // soldiers
		}

		ClientControllableEntity* getVehicle()
		{
			if (m_attachedControllable)
				return (ClientControllableEntity*)m_attachedControllable;
			return (ClientControllableEntity*)m_attachedControllable;
		}
		/*
		fb::vehicle::Input* getVehicleInput()
		{
			if (m_attachedControllable)
				return fb::vehicle::Input::Singleton();
			return NULL;
		}*/
	}; // 0x420

};

#endif
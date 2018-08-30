#ifndef _Player_H
#define _Player_H

#include "Frostbite_Classes.h"

namespace fb
{

	class Player 
	{
	public:
		//virtual void * __vecDelDtor(unsigned int);  // 

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
		virtual void function0(); 
		virtual SoldierEntity* getSoldier();// 
		virtual EntryComponent * getEntry();  //
		virtual bool isInVehicle(); //
		virtual unsigned int getId(); //
		virtual bool isUnlocked(const class UnlockAssetBase *);  //

		//char unknown4[4]; // 0x0004
		PlayerData* m_data;						// 0x08
		MemoryArena* m_arena;					// 0x0C
		eastl::basic_string<char,eastl_arena_allocator> m_name;		// 0x10
		OnlineId m_onlineId; // 0x20 
		OnlineId m_groupId; // 0x40
		OnlineId m_clubId; // 0x60
		int m_teamPreference; // 0x80
		//new
		//unsigned int m_lastVehicleCameraIndex;                     // 0x84
		//unsigned int m_analogInputEnableMask;                     // 0x88
		//unsigned __int64 m_digitalInputEnableMask;                     // 0x90
		BYTE pad_094[0x298]; // 0x94   //original 298 till teamid
		//bool m_isAIPlayer;                     // 0x320
		//bool m_isSpectator;                     // 0x321
		int m_teamId; // 0x31C
	}; // 0x320
};

#endif
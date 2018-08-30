#ifndef _SpawnReferenceObjectData_H
#define _SpawnReferenceObjectData_H
#include "Frostbite_Classes.h"
#include "ReferenceObjectData.h"
namespace fb
{
	class SpawnReferenceObjectData
		: public ReferenceObjectData
	{
	public:
		LinearTransform m_controllableInput;			// 0x60 
		LinearTransform m_controllableTransform;		// 0xA0 
		FLOAT m_spawnProtectionRadius;					// 0xE0 
		String m_locationNameSid;						// 0xE4 
		String m_locationTextSid;						// 0xE8 
		INT m_teamId;									// 0xEC 
		FLOAT m_rotationRoll;							// 0xF0 
		DWORD m_spawnProtectionFriendlyKilledCount;		// 0xF4 
		FLOAT m_throttle;								// 0xF8 
		FLOAT m_rotationPitch;							// 0xFC 
		FLOAT m_initialSpawnDelay;						// 0x100 
		FLOAT m_spawnDelay;								// 0x104 
		INT m_maxCount;									// 0x108 
		INT m_maxCountSimultaneously;					// 0x10C 
		INT m_totalCountSimultaneousOfType;				// 0x110 
		FLOAT m_spawnAreaRadius;						// 0x114 
		FLOAT m_rotationYaw;							// 0x118 
		FLOAT m_spawnProtectionFriendlyKilledTime;		// 0x11C 
		INT m_takeControlEntryIndex;					// 0x120 
		CHAR m_lockedTeam;								// 0x124 
		CHAR m_autoSpawn;								// 0x125 
		CHAR m_onlySendEventForHumanPlayers;			// 0x126 
		CHAR m_clearBangersOnSpawn;						// 0x127 
		CHAR m_tryToSpawnOutOfSight;					// 0x128 
		CHAR m_sendWeaponEvents;						// 0x129 
		CHAR m_takeControlOnTransformChange;			// 0x12A 
		CHAR m_returnControlOnIdle;						// 0x12B 
		CHAR m_useAsSpawnPoint;							// 0x12C 
		CHAR m_initialAutoSpawn;						// 0x12D 
		CHAR m_enabled;									// 0x12E 
		CHAR m_spawnProtectionCheckAllTeams;			// 0x12F 
	};

};

#endif
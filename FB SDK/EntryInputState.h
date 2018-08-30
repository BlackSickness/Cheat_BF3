#ifndef _EntryInputState_H
#define _EntryInputState_H
#include "Frostbite_Classes.h"
namespace fb
{
	class EntryInputState
	{
	public:
		class CharacterMeleeIdentifier
		{
		public:
			WeakPtr<Entity> entity;				// 0x00
			network::ClientGhost* clientGhost;	// 0x04
		}; // 0x08

		class CharacterCollisionPos
		{
		public:
			WeakPtr<Entity> entity;					// 0x00
			network::ClientGhost* clientGhost;		// 0x04
			PAD(0x8);								// 0x08
			Vec3 pos;								// 0x10
		}; // 0x20

		LPVOID vftable;									// 0x00
		PAD(0xC);										// 0x04
		FLOAT m_analogInput[10];						// 0x10
		FLOAT m_downTimes[100];							// 0x38
		PAD(0x24);										// 0x1C8
		FLOAT m_deltaTime;								// 0x1EC
		FLOAT m_timeBehind;								// 0x1F0
		FLOAT m_authorativeAimingYaw;					// 0x1F4
		FLOAT m_authorativeAimingPitch;					// 0x1F8
		FLOAT m_authorativeMovementPenalty;				// 0x1FC
		Vec3 m_authoritativeCameraPosition;				// 0x200
		Vec3 m_authoritativeMovementPosition;			// 0x210
		Vec3 m_authoritativeMovementVelocity;			// 0x220
		CharacterMeleeIdentifier m_meleeIdentifier;		// 0x230
		PAD(0x4);										// 0x238
		DWORD m_characterCollisionCount;				// 0x23C
		CharacterCollisionPos m_collisionPos[4];		// 0x240
		DWORD m_zoomLevel;								// 0x2C0
		DWORD m_ticks;									// 0x2C4
		DWORD m_controllableId;							// 0x2C8
		DWORD m_entryId;								// 0x2CC
		DWORD m_networkSequenceNumber;					// 0x2D0
	}; // 0x2D4


};

#endif
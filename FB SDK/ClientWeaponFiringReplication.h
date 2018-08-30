#ifndef _ClientWeaponFiringReplication_H
#define _ClientWeaponFiringReplication_H
#include "Frostbite_Classes.h"
#include "WeaponFiringCallbackHandler.h"
namespace fb
{
	class ClientWeaponFiringReplication
		: public WeaponFiringCallbackHandler	// 0x00
	{
	public:
		class AIWeaponData
		{
		public:
			INT fireCount;					// 0x00
			INT releaseCount;				// 0x04
			INT autoFireCount;				// 0x08
			FLOAT timeSinceFiring;			// 0x0C
			FLOAT powerModifier;			// 0x10
			eastl::vector<UINT> tickBuffer;	// 0x14
			CHAR wasAutomaticing;			// 0x24
			CHAR isHolding;					// 0x25
			CHAR hasSpawnedShot;			// 0x26
			PAD(0x1);						// 0x27
		}; // 0x28

		WeaponFiringData* m_data;				// 0x8C
		WeaponModifier* m_weaponModifier;		// 0x90
		CHAR m_networkFlagIsSingleFiring;		// 0x94
		CHAR m_networkFlagIsAutomaticFiring;	// 0x95
		CHAR m_networkFlagIsReloading;			// 0x96
		CHAR m_networkFlagBoltAction;			// 0x97
		AIWeaponData m_primary;					// 0x98
		FLOAT m_timeUntilNextAutomaticShot;		// 0xC0
		INT m_reloadCount;						// 0xC4
		INT m_boltActionCount;					// 0xC8
		DWORD m_firedBullets;					// 0xCC
		FLOAT m_heat;							// 0xD0
		FLOAT m_timeToWait;						// 0xD4
		eastl::vector<Event> m_events;			// 0xD8
		WeaponSway* m_weaponSway;				// 0xE8
		bool m_activated;						// 0xEC
		bool m_detonatorActive;					// 0xED
		bool m_oldDetonatorState;				// 0xEE
		bool m_firedCount;						// 0xEF
		bool m_firstApply;						// 0xF0
		bool m_useAIShootSpace;					// 0xF1
		PAD(0x3E);								// 0xF2
		LinearTransform m_aiShootSpace;			// 0x130
		INT m_fireLogicType;					// 0x170
		FLOAT m_simulatedTime;					// 0x174
		FLOAT m_predictedTime;					// 0x178
	}; // 0x17C


};

#endif
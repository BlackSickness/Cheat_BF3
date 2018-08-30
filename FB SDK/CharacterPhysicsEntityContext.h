#ifndef _CharacterPhysicsEntityContext_H
#define _CharacterPhysicsEntityContext_H
#include "Frostbite_Classes.h"
//#include "Havok.h"
namespace fb
{
	class CharacterPhysicsEntityContext
		: public hkpCharacterContext							// 0x00
	{
	public:
		class ParachuteContext
		{
		public:
			LinearTransform m_transformWS;		// 0x00
			LinearTransform m_unknown;			// 0x40
			Vec3 m_parachuteOffset;				// 0x80
			FLOAT m_time;						// 0x90
			INT m_initialized;					// 0x94
		}; // 0x98

		PAD(0xC);												// 0x24
		ParachuteContext m_parachuteContext;					// 0x30
		PAD(0x8);												// 0xC8
		Vec3 m_ladderNorm;										// 0xD0
		CharacterPhysicsEntityCallbacks* m_callbackHandler;		// 0xE0
		CharacterPhysicsEntity* m_entity;						// 0xE4
		DWORD m_ladder;											// 0xE8
		FLOAT m_timeToJump;										// 0xEC
		FLOAT m_jumpDelay;										// 0xF0
		FLOAT m_stamina;										// 0xF4
		FLOAT m_jumpPenaltyFactor;								// 0xF8
		FLOAT m_forceToGroundTimer;								// 0xFC
		DWORD m_jumpCount;										// 0x100
		CHAR m_applyLandingPenalty;								// 0x104
		CHAR m_sprinting;										// 0x105
		CHAR m_sprintHold;										// 0x106
		CHAR m_jumpInProgress;									// 0x107
	};

};

#endif
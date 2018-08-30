#ifndef _CharacterPhysicsEntityState_H
#define _CharacterPhysicsEntityState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class CharacterPhysicsEntityState
	{
	public:
		Vec3 m_parachuteRotation;				// 0x00
		FLOAT m_parachuteDeployTime;			// 0x10
		PAD(0xC);								// 0x14
		Vec3 m_position;						// 0x20
		Vec3 m_surfaceVelocity;					// 0x30
		Vec3 m_linearVelocity;					// 0x40
		Vec3 m_groundNormal;					// 0x50
		DWORD m_pose;							// 0x60
		DWORD m_changingToPose;					// 0x64
		FLOAT m_transitionTimer;				// 0x68
		DWORD m_currentState;					// 0x6C
		BYTE m_enabled;							// 0x70
		PAD(0xF);								// 0x71
		Vec3 m_localEyePosition;				// 0x80
		DWORD m_groundSupported;				// 0x90
		FLOAT m_groundHeight;					// 0x94
		FLOAT m_timeToJump;						// 0x98
		FLOAT m_stamina;						// 0x9C
		FLOAT m_ladderHeightClimbed;			// 0xA0
		FLOAT m_ladderTransitionProgress;		// 0xA4
		PAD(0x44);								// 0xA8
		DWORD m_contactMaterialIndex;			// 0xEC
		FLOAT m_jumpPenaltyFactor;				// 0xF0
		DWORD m_jumpCounter;					// 0xF4
		FLOAT m_forceToGroundTimer;				// 0xF8
		CHAR m_jumpInProgress;					// 0xFC
		CHAR m_applyLandingPenalty;				// 0xFD
		CHAR m_sprinting;						// 0xFE
		CHAR m_sprintHold;						// 0xFF
	}; // 0x100



};

#endif
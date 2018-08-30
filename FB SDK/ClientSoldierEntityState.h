#ifndef _ClientSoldierEntityState_H
#define _ClientSoldierEntityState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class ClientSoldierEntityState
	{

		float aimingYaw;                     // 0x0
		float aimingPitch;                     // 0x4
		bool aimingEnabled;                     // 0x8
		bool overrideLookAt;                     // 0x9
		Vec3 lookTarget;                     // 0x10
		float headRotationSpeed;                     // 0x20
		bool allowedToMoveEyes;                     // 0x24
		int teamId;                     // 0x28
		int localAnimation;                     // 0x2C
		int movementAnimation;                     // 0x30
/*		class fb::AIStateAnimation::State*/void* aiAnim;                     // 0x34
		float m_lastVerticalImpactVelocity;                     // 0x3C
		enum fb::SoldierEntity::SoldierInteractedStatus m_soldierInteractedStatus;                     // 0x40
		unsigned int maskStateFlag;                     // 0x44, len(0x1)
		unsigned int maskAuthoratativeAimingFlag;                     // 0x45, len(0x1)
		unsigned int maskLookAtFlag;                     // 0x46, len(0x1)
		unsigned int maskTeamFlag;                     // 0x47, len(0x1)
		unsigned int maskPlayLocalAnimation;                     // 0x48, len(0x1)
		unsigned int maskAIAnimation;                     // 0x49, len(0x1)
		unsigned int maskOnImpact;                     // 0x4A, len(0x1)
		unsigned int maskBeingInteracted;                     // 0x4B, len(0x1)
		unsigned int stateForceInvisible;                     // 0x4C, len(0x1)
		unsigned int stateCollision;                     // 0x4D, len(0x1)
		eastl::vector<unsigned int> forbiddenListeners;                     // 0x48
	
	}; // fb::ClientSoldierEntityState

};

#endif
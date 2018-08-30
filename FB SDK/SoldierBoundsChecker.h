#ifndef _SoldierBoundsChecker_H
#define _SoldierBoundsChecker_H
#include "Frostbite_Classes.h"
namespace fb
{
	class SoldierBoundsChecker
	{

		enum RayIdentifier
		{
			 RIBoundLeftForward, // constant 0x0
			 RIBoundRightForward,// constant 0x1
			 RIBoundRightBack,   // constant 0x2
			 RIBoundLeftBack,    // constant 0x3
			 RIIdentifierCount,  // constant 0x4
		}; // RayIdentifier

		class ReplicatedBound
		{

			float fraction;     // 0x0
			byte hasHit;        // 0x4, len(0x1) bool

		}; // ReplicatedBound

		eastl::fixed_vector<SoldierBoundsChecker::ReplicatedBound,4,1> m_replicatedRayLengths;                     // 0x0
		eastl::fixed_vector<ProximityHookImpl::RayCast,4,1>* m_rayCasts;                     // 0x40
		Vec3 m_lastUpdatePosition;                     // 0x220
		Vec3 m_lastUpdateForward;                     // 0x230
		float m_updateDelay;                     // 0x240
		float m_minUpdateDelayTime;                     // 0x244
		CharacterPoseType m_pose;                     // 0x248
	}; // fb::SoldierBoundsChecker

};

#endif
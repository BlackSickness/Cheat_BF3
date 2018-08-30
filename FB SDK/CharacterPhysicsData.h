#ifndef _CharacterPhysicsData_H
#define _CharacterPhysicsData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class CharacterPhysicsData
		: public Asset								// 0x00
	{
	public:
		RefArray<CharacterPoseData> m_poses;		// 0x0C
		RefArray<CharacterStateData> m_states;		// 0x10
		CharacterStateType m_defaultState;			// 0x14
		DataContainer* m_sprint;					// 0x18
		DataContainer* m_materialPair;				// 0x1C
		INT m_pushableObjectWeight;					// 0x20
		FLOAT m_mass;								// 0x24
		FLOAT m_maxAscendAngle;						// 0x28
		FLOAT m_physicalRadius;						// 0x2C
		FLOAT m_waterDepthLimit;					// 0x30
		FLOAT m_inputAcceleration;					// 0x34
		FLOAT m_ladderAcceptAngle;					// 0x38
		FLOAT m_ladderAcceptAnglePitch;				// 0x3C
		FLOAT m_jumpPenaltyTime;					// 0x40
		FLOAT m_jumpPenaltyFactor;					// 0x44
		FLOAT m_speedPenaltyOnDamage;				// 0x48
	}; // 0x4C

};

#endif
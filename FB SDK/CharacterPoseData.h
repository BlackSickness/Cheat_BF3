#ifndef _CharacterPoseData_H
#define _CharacterPoseData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class CharacterPoseData
		: public DataContainer							// 0x00
	{
	public:
		PAD(0x8);										// 0x08
		Vec3 m_eyePosition;								// 0x10
		Vec3 m_collisionBoxMaxExpand;					// 0x20
		Vec3 m_collisionBoxMinExpand;					// 0x30
		FLOAT m_height;									// 0x40
		FLOAT m_stepHeight;								// 0x44
		Array<Vec2> m_throttleModifierCurve;			// 0x48
		CharacterPoseType m_poseType;					// 0x4C
		CharacterPoseCollisionType m_collisionType;		// 0x50
		LookConstraintsData m_lookConstraints;			// 0x54
	}; // 0x64

};

#endif
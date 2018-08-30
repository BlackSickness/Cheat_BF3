#ifndef _BoneCollisionData_H
#define _BoneCollisionData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class PitchModifier
	{
	public:
		Vec3 m_offset;			// 0x00
		FLOAT m_pitchVal;		// 0x10
		FLOAT m_pitchAngle;		// 0x14
	}; // 0x18

	class BoneCollisionData
	{
	public:
		Vec3 m_debugDrawColor;							// 0x00
		Vec3 m_capsuleOffset;							// 0x10
		String m_boneName;								// 0x20
		HitReactionType m_animationHitReactionType;		// 0x24
		MaterialContainerPair* m_materialPair;			// 0x28
		INT m_boneAxis;									// 0x2C
		FLOAT m_capsuleLength;							// 0x30
		FLOAT m_capsuleRadius;							// 0x34
		PAD(0x8);										// 0x38
		PitchModifier m_minPitch;						// 0x40
		PAD(0x8);										// 0x58
		PitchModifier m_maxPitch;						// 0x60
		PAD(0x8);										// 0x78
		CHAR m_validInHiLod;							// 0x80
		CHAR m_validInLowLod;							// 0x81
		CHAR m_usePhysicsRotation;						// 0x82
		CHAR m_deactiveIfBehindWall;					// 0x83
		PAD(0xC);										// 0x84
	}; // 0x90

};

#endif
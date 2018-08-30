#ifndef _CharacterStatePoseInfo_H
#define _CharacterStatePoseInfo_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/DataContainer.h"
namespace fb
{
	class CharacterStatePoseInfo
		: public DataContainer				// 0x00
	{
	public:
		CharacterPoseType m_poseType;		// 0x08
		FLOAT m_velocity;					// 0x0C
		FLOAT m_accelerationGain;			// 0x10
		FLOAT m_decelerationGain;			// 0x14
		FLOAT m_sprintGain;					// 0x18
		FLOAT m_sprintMultiplier;			// 0x1C
		SpeedModifierData m_speedModifier;	// 0x20
	};	// 0x30



};

#endif
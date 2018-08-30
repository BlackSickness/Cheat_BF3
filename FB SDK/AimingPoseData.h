#ifndef _AimingPoseData_H
#define _AimingPoseData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class AimingPoseData
	{
	public:
		FLOAT m_minimumPitch;		// 0x00
		FLOAT m_maximumPitch;		// 0x04
		FLOAT m_targetingFov;		// 0x08
		FLOAT m_aimSteadiness;		// 0x0C
		FLOAT m_speedMultiplier;	// 0x10
		FLOAT m_recoilMultiplier;	// 0x14
	}; // 0x18

};

#endif
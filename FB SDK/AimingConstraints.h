#ifndef _AimingConstraints_H
#define _AimingConstraints_H
#include "Frostbite_Classes.h"
namespace fb
{
	class AimingConstraints
	{
	public:
		FLOAT m_minYaw;				// 0x00
		FLOAT m_maxYaw;				// 0x04
		FLOAT m_minPitch;			// 0x08
		FLOAT m_maxPitch;			// 0x0C
		FLOAT m_pitchOffset;		// 0x10
		FLOAT m_yawOffset;			// 0x14
		FLOAT m_minYawDefault;		// 0x18
		FLOAT m_maxYawDefault;		// 0x20
	}; // 0x24

};

#endif
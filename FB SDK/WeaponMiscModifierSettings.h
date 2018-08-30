#ifndef _WeaponMiscModifierSettings_H
#define _WeaponMiscModifierSettings_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class WeaponMiscModifierSettings
	{
	public:
		CHAR m_enableBreathControl;					// 0x00
		CHAR m_canBeInSupportedShooting;			// 0x01
		CHAR m_unZoomOnBoltAction;					// 0x02
		CHAR m_holdBoltActionUntilZoomRelease;		// 0x03
	}; // 0x04

};

#endif
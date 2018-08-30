#ifndef _AnimatedSoldierWeaponSprintModule_H
#define _AnimatedSoldierWeaponSprintModule_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class AnimatedSoldierWeaponSprintModule
	{
	public:
		CHAR m_wasSprinting;		// 0x00
		CHAR m_isSprinting;			// 0x01
		CHAR m_nearBashable;		// 0x02
		CHAR m_wasNearBashable;		// 0x03
	}; // 0x0408

};

#endif
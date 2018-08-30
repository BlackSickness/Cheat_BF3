#ifndef _AnimatedSoldierWeaponShootModule_H
#define _AnimatedSoldierWeaponShootModule_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class AnimatedSoldierWeaponShootModule
	{
	public:
		AnimationConfigurationShootModuleData* m_data;	// 0x00
		INT m_zooming;									// 0x04
	}; // 0x08

};

#endif
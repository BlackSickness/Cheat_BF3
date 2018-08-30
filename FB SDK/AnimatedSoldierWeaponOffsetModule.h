#ifndef _AnimatedSoldierWeaponOffsetModule_H
#define _AnimatedSoldierWeaponOffsetModule_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponOffsetData.h"
namespace fb
{
	class AnimatedSoldierWeaponOffsetModule
	{
	public:
		WeaponOffsetData* m_data;		// 0x00
		INT m_zooming;					// 0x04
	}; // 0x08

};

#endif
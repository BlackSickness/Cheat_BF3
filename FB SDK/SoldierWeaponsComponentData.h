#ifndef _SoldierWeaponsComponentData_H
#define _SoldierWeaponsComponentData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class SoldierWeaponsComponentData
		:public ComponentData
	{
		LinearTransform m_aimDir;                     // this+0x80
		/*struct fb::Animated3pOnlyWeaponBinding */void* m_animated3pOnlyWeaponBinding;                     // this+0xC0
		int m_primaryWeaponId;                     // this+0x130
		/*struct fb::AnimatedWeaponBinding */void*m_animatedWeaponBinding;                     // this+0x134
		/*struct fb::Animated1pOnlyWeaponBinding*/void* m_animated1pOnlyWeaponBinding;                     // this+0xEC4
		int m_explosiveIncrease;                     // this+0xFA4
		CtrRefBase m_weaponSkeleton;                     // this+0xFA8
		float m_ammoClipIncreaseMultiplier;                     // this+0xFAC
		int m_grenadeIncrease;                     // this+0xFB0
		bool m_useExternalAimDir;                     // this+0xFB4
		bool m_unlimitedMags;                     // this+0xFB5
		bool m_unlimitedAmmo;                     // this+0xFB6
			virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::SoldierWeaponsComponentData

};

#endif
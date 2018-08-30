#ifndef _WeaponMagazineModifier_H
#define _WeaponMagazineModifier_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponModifierBase.h"
namespace fb
{
	class WeaponMagazineModifier
		: public WeaponModifierBase		// 0x00
	{
	public:
		INT m_magazineCapacity;			// 0x08
		INT m_numberOfMagazines;		// 0x0C
	}; // 0x10
};

#endif
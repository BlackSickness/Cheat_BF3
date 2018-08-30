#ifndef _WeaponAnimTypeModifier_H
#define _WeaponAnimTypeModifier_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponModifierBase.h"
namespace fb
{
		class WeaponAnimTypeModifier
		: public WeaponModifierBase			// 0x00
	{
	public:
		WeaponAnimType m_weaponAnimType;	// 0x08
	}; // 0x0C
};

#endif
#ifndef _WeaponSoundModifier_H
#define _WeaponSoundModifier_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponModifierBase.h"
namespace fb
{
		class WeaponSoundModifier
		: public WeaponModifierBase	// 0x00
	{
	public:
		DataContainer* m_sound;		// 0x08
	}; // 0x0C
};

#endif
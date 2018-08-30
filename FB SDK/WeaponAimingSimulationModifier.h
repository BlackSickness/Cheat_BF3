#ifndef _WeaponAimingSimulationModifier_H
#define _WeaponAimingSimulationModifier_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponModifierBase.h"
namespace fb
{
	class WeaponAimingSimulationModifier
		: public WeaponModifierBase				// 0x00
	{
	public:
		DataContainer* m_aimingController;		// 0x08
	}; // 0x0C
};

#endif
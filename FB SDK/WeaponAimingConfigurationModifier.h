#ifndef _WeaponAimingConfigurationModifier_H
#define _WeaponAimingConfigurationModifier_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponModifierBase.h"
namespace fb
{
	class WeaponAimingConfigurationModifier
		: public WeaponModifierBase						// 0x00
	{
	public:
		Array<FLOAT> m_zoomInOutMeshTransitionFactors;	// 0x08
		FLOAT m_zoomedKickBackFactor;					// 0x0C
		DataContainer* m_weaponOffsetModuleData;		// 0x10
		DataContainer* m_weaponSpeedModuleData;			// 0x14
	}; // 0x18
};

#endif
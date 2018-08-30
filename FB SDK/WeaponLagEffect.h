#ifndef _WeaponLagEffect_H
#define _WeaponLagEffect_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	//new class
	class WeaponLagEffect
	{
	public:
		DWORD m_data;				// 0x00 FirstPersonCameraData*
		BYTE pad_004[0xC];			// 0x04
		Vec3 m_weaponOffsetMod;		// 0x10
		Vec3 m_weaponRotationMod;	// 0x20
		Vec3 m_weaponLagOffset;		// 0x30
		Vec3 m_weaponLagRotation;	// 0x40
		Vec3 m_cameraOffsetMod;		// 0x50
		Vec3 m_cameraRotationMod;	// 0x60
		DWORD m_weaponSpringEffect;	// 0x70 WeaponLagEffect::SpringEffect*
		DWORD m_cameraSpringEffect;	// 0x74 WeaponLagEffect::SpringEffect*
		float m_timeOfLastStateChange;	// 0x78
		int m_wasZooming;			// 0x7C
	};

};

#endif
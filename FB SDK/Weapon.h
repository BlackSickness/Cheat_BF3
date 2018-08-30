#ifndef _Weapon_H
#define _Weapon_H
#include "Frostbite_Classes.h"
#include "Tool.h"
#include "FiringDispersion.h"
namespace fb
{
	class Weapon
		: public Tool												// 0x00
	{
	public:
		WeaponFiringData* m_firingData;								// 0x0C
		WeaponModifier* m_modifier;									// 0x10
		PAD(0xC);													// 0x14
		Vec3 m_moveSpeed;											// 0x20
		LinearTransform m_shootSpace;								// 0x30
		LinearTransform m_shootSpaceDelta;							// 0x70
		eastl::fixed_vector<FiringDispersion, 3, 2> m_dispersion;	// 0xB0
		FLOAT m_externalDispersionAngle;							// 0x118
		CHAR m_currPose;											// 0x11C
		CHAR m_useSecondaryProjectile;								// 0x11D
		PAD(0x2);													// 0x11E
	}; // 0x120

};

#endif
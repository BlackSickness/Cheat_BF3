#ifndef _WeaponSwayCallbackImpl_H
#define _WeaponSwayCallbackImpl_H
#include "Frostbite_Classes.h"
#include "WeaponSway.h"
namespace fb
{
	class WeaponSwayCallbackImpl
		: public WeaponSway::SoldierAttributesCallback					// 0x00
	{	
	public:
		FLOAT m_yawInputLevel;											// 0x04
		FLOAT m_pitchInputLevel;										// 0x08
		FLOAT m_strafeInputLevel;										// 0x0C
		FLOAT m_throttleInputLevel;										// 0x10
		DWORD m_seed;													// 0x14
		PAD(0x8);														// 0x18
		Vec3 m_soldierSpeed;											// 0x20
		FLOAT m_soldierMaxSpeed;										// 0x30
		WeaponSway::AbilityCallback* m_abilityCallback;					// 0x34
		WeaponSway::SuppressionCallback* m_suppressionCallback;			// 0x38
		FLOAT m_currentSupressionLevel;									// 0x3C
		CharacterPoseType m_soldierPose;								// 0x40
		CharacterPoseType m_soldierChangingToPose;						// 0x44
		SoldierEntityActionState m_soldierActionState;					// 0x48
		byte m_isSupported;												// 0x4C
		byte m_isSprinting;												// 0x4D
		byte m_isWeaponLightEnabled;									// 0x4E
		byte m_isZooming;												// 0x4F
	}; // 0x50


};

#endif
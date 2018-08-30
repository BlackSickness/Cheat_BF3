#ifndef _WeaponSwitchingState_H
#define _WeaponSwitchingState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class WeaponSwitchingState
	{
	public:
		INT m_weaponCount;										// 0x00
		INT m_currentWeaponId;									// 0x04
		INT m_previousWeaponId;									// 0x08
		INT m_lastPrimary;										// 0x0C
		FLOAT m_weaponSwitchTimer;								// 0x10
		FLOAT m_switchBackToPrevMaxTimePressed;					// 0x14
		EntryInputActionEnum m_fireAndSwitchBackToPrevAction;	// 0x18
		CHAR m_automaticFire;									// 0x1C
		CHAR m_playerSwitchedWeapons;							// 0x1D
		CHAR m_quickSwitch;										// 0x1E
		PAD(0x1);												// 0x1F
	}; // 0x20

};

#endif
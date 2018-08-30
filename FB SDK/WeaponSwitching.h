#ifndef _WeaponSwitching_H
#define _WeaponSwitching_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class WeaponSwitching
	{
	public:
		//LPVOID vftable;											// 0x00
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual int cycleWeaponId(int);	// V: 0x4
		virtual int cyclePrimaryWeaponId(int, bool, bool);	// V: 0x8
		virtual int cycleSecondaryWeaponId(int);	// V: 0xC

		INT m_currentWeaponId;									// 0x04
		INT m_previousWeaponId;									// 0x08
		INT m_lastPrimary;										// 0x0C
		INT m_weaponCount;										// 0x10
		EntryInputActionEnum m_fireAndSwitchBackToPrevAction;	// 0x14
		FLOAT m_weaponSwitchTimer;								// 0x18
		FLOAT m_switchBackToPrevMaxTimePressed;					// 0x1C
		CHAR m_playerSwitchedWeapons;							// 0x20
		CHAR m_quickSwitch;										// 0x21
		CHAR m_automaticFire;									// 0x22
		PAD(0x1);												// 0x23
		WeaponSwitchingCallbacks* m_callbackHandler;			// 0x24
	}; // 0x28

};

#endif
#ifndef _ClientAnimatedSoldierWeaponHandler_H
#define _ClientAnimatedSoldierWeaponHandler_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ClientAnimatedSoldierWeaponHandler
	{
	public:
		LPVOID vftable;									// 0x00
		CHAR m_weaponDeployRequested;					// 0x04
		CHAR m_altDeploy;								// 0x05
		CHAR m_quickSwitch;								// 0x06
		PAD(0x1);										// 0x07
		FLOAT m_weaponUndeployTimer;					// 0x08
		FLOAT m_spamDetectTimer;						// 0x0C
		PAD(0x4);										// 0x10
		ClientSoldierWeapon* m_currentAnimatedWeapon;	// 0x14
		INT m_deleteCurrentAnimationWeapon;				// 0x18
		INT m_currentAnimatedWeaponIndex;				// 0x1C
		INT m_currentAnimatedWeaponState;				// 0x20
		ClientSoldierWeapon* m_wantedAnimatedWeapon;	// 0x24
		INT m_wantedAnimatedWeaponIndex;				// 0x28
		ClientSoldierEntity* m_soldier;					// 0x2C
		INT m_lastPredicted;							// 0x30
	}; // 0x34

};

#endif
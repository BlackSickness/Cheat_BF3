#ifndef _WeaponSwitchingCallbacks_H
#define _WeaponSwitchingCallbacks_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class WeaponSwitchingCallbacks
	{
	public:
		virtual void changeWeaponEvent(INT, INT, BOOL, BOOL, BOOL); // V:0x00
        virtual bool isSelectedWeaponIdValid(INT);     // V:0x04
        virtual bool isFiring();       // V:0x08
		//LPVOID vftable; // 0x00
	}; // 0x04

};

#endif
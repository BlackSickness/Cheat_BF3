#ifndef _WeaponsState_H
#define _WeaponsState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class WeaponsState
	{
	public:
		//DWORD m_weaponResourceIds[10];		// 0x00
		//WORD m_weaponInstanceIds[10];		// 0x28
		//DWORD m_weaponUnlockIds[28];		// 0x3C
		//BYTE pad_0AC[0xC];
		PAD(0xC4);		// 0x00
	}; // 0xC4

};

#endif
#ifndef _WeaponFiringShooter_H
#define _WeaponFiringShooter_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class WeaponFiringShooter
		:public SupportsWeakPtr // Inherited class at offset 0x4
	{
	public:
		//LPVOID vftable;				// 0x00
		virtual ClientPlayer * player();	// V: 0x0
		WeakTokenHolder m_weakTokenHolder;          // this+0x4
			
		//DWORD m_weakTokenHolder;	// 0x04
	}; // 0x08

};

#endif
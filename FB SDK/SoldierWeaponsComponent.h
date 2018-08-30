#ifndef _SoldierWeaponsComponent_H
#define _SoldierWeaponsComponent_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/SoldierWeaponsComponentData.h"
namespace fb
{
	
	class SoldierWeaponsComponent
	{
	public:
		//LPVOID vftable;				// 0x00
			virtual bool isZooming();	// V: 0x0
			virtual  const SoldierWeaponsComponentData & weaponComponentData();	// V: 0x4
		FLOAT m_weaponDispersion;	// 0x04
	}; // 0x08

};

#endif
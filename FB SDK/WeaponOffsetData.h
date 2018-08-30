#ifndef _WeaponOffsetData_H
#define _WeaponOffsetData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/DataContainer.h"
namespace fb
{
	class WeaponOffsetData
		: public DataContainer			// 0x00
	{
	public:
		FLOAT m_weaponOffsetX;			// 0x08
		FLOAT m_weaponOffsetY;			// 0x0C
		FLOAT m_weaponOffsetZ;			// 0x10
		FLOAT m_weaponZoomedOffsetX;	// 0x14
		FLOAT m_weaponZoomedOffsetY;	// 0x18
		FLOAT m_weaponZoomedOffsetZ;	// 0x1C
	}; // 0x20

};

#endif
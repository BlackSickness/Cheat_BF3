#ifndef WeaponData
#define _WeaponData_H
#include "Frostbite_Classes.h"
#include "ToolData.h"
namespace fb
{
	class WeaponData
		: public ToolData					// 0x00
	{
	public:
		INT m_showLaserPaintedVehicles;		// 0x0C
	}; // 0x10

};

#endif
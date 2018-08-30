#ifndef _AnimatedSoldierWeaponZoomModule_H
#define _AnimatedSoldierWeaponZoomModule_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class AnimatedSoldierWeaponZoomModule
	{
	public:
		FLOAT m_zoomTimer;							// 0x00
		FLOAT m_oldZoomTimer;						// 0x04
		FLOAT m_isZooming;							// 0x08
		SoldierAimingSimulationData* m_aimingData;	// 0x0C
	}; // 0x10

};

#endif
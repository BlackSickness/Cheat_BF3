#ifndef _SpottingComponentData_H
#define _SpottingComponentData_H
#include "Frostbite_Classes.h"
#include "ComponentData.h"
namespace fb
{
	class SpottingComponentData
		:public ComponentData // Inherited class at offset 0x0
	{
	public:
		float m_spottingFov;                     // this+0x80
		float m_spottingDistance;                     // this+0x84
		float m_passiveSpottingTimeInterval;                     // this+0x88
		float m_timeRequiredToPassiveSpot;                     // this+0x8C
		float m_orderNeedAmmoPercentage;                     // this+0x90
		float m_orderHealPercentage;                     // this+0x94
		float m_orderRepairPercentage;                     // this+0x98
		float m_pickupOrderDistance;                     // this+0x9C
		float m_healOrderDistance;                     // this+0xA0
		float m_ammoOrderDistance;                     // this+0xA4
		float m_repairOrderDistance;                     // this+0xA8
		float m_coolDownHistoryTime;                     // this+0xAC
		int m_coolDownAllowedSpotsWithinHistory;          // this+0xB0
		bool m_onlyAllowedToHaveOneSpottedPlayer;        // this+0xB4
	}; // fb::SpottingComponentData

};

#endif
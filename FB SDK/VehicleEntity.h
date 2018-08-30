#ifndef _VehicleEntity_H
#define _VehicleEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
	class VehicleEntity
	{
	public:
		PAD(0x4);
		PhysicsEntity* m_physicsEntity;		// 0x00
		FLOAT m_waterLevel;					// 0x04
		FLOAT m_terrainLevel;				// 0x08
		FLOAT m_waterLevelUpdateTimer;		// 0x0C
		FLOAT m_terrainLevelUpdateTimer;	// 0x10
		enum DamageState
		{

			 DamageState_Healthy,                   // constant 0x0
			 DamageState_Disabled,                     // constant 0x1
			 DamageState_Critical,                     // constant 0x2

		}; // DamageState
	}; // 0x14

};

#endif
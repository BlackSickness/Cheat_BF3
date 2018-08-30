#ifndef _WeaponFiringData_H
#define _WeaponFiringData_H
#include "Frostbite_Classes.h"
namespace fb
{
	class WeaponFiringData
		: public GameDataContainer				// 0x00
	{
	public:
		FiringFunctionData* m_primaryFire;		// 0x08
		FLOAT m_deployTime;						// 0x0C
		FLOAT m_reactivateCooldownTime;			// 0x10
		FLOAT m_altDeployTime;					// 0x14
		PAD(0x4);								// 0x18
		INT m_shotLimit;						// 0x1C
		DataContainer* m_weaponSway;			// 0x20
		FLOAT m_supportDelayProne;				// 0x24
	}; // 0x28

};

#endif
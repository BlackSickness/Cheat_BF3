#ifndef _ProjectileEntityData_H
#define _ProjectileEntityData_H
#include "Frostbite_Classes.h"
#include "GamePhysicsEntityData.h"
namespace fb
{
		class ProjectileEntityData
		: public GamePhysicsEntityData				// 0x00
	{
	public:
		PAD(0xC);									// 0x64
		INT m_hitReactionWeaponType;				// 0x70
		FLOAT m_initialSpeed;						// 0x74
		FLOAT m_timeToLive;							// 0x78
		FLOAT m_initMeshHideTime;					// 0x7C
		FLOAT m_visualConvergeDistance;				// 0x80
		FLOAT m_unknown;							// 0x84
		MaterialContainerPair* m_materialPair;		// 0x88
		DataContainer* m_explosion;					// 0x8C
		WeaponSuppressionData* m_suppressionData;	// 0x90
		String m_ammunitionType;					// 0x94
		CHAR m_serverProjectileDisabled;			// 0x98
		CHAR m_detonateOnTimeout;					// 0x99
		PAD(0x2);									// 0x9A
	}; // 0x9C

};

#endif
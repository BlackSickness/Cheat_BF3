#ifndef _BulletEntityData_H
#define _BulletEntityData_H
#include "Frostbite_Classes.h"
#include "ProjectileEntityData.h"
namespace fb
{
	class BulletEntityData
		:public ProjectileEntityData	//0x00
	{
	public:
		PAD(0x4);
		Vec3	m_initialAngularVelocity;		 // 0xA0

		void*	m_trailEffect;		 // 0xB0

		void*	m_mesh;		 // 0xB4

		float	m_maxAttachableInclination;		 // 0xB8
		bool	m_extraDamping;		 // 0xBC
		bool	m_isAttachable;		 // 0xBD
		float	m_stamina;		 // 0xC0
		void*	m_flyBySound;		 // 0xC4

		void*	m_dudExplosion;		 // 0xC8

		float	m_gravity;		 // 0xCC
		float	m_impactImpulse;		 // 0xD0
		float	m_detonationTimeVariation;		 // 0xD4
		float	m_vehicleDetonationRadius;		 // 0xD8
		float	m_vehicleDetonationActivationDelay;		 // 0xDC
		float	m_flyBySoundRadius;		 // 0xE0
		float	m_flyBySoundSpeed;		 // 0xE4
		float	m_firstFrameTravelDistance;		 // 0xE8
		float	m_distributeDamageOverTime;		 // 0xEC
		float	m_startDamage;		 // 0xF0
		float	m_endDamage;		 // 0xF4
		float	m_damageFalloffStartDistance;		 // 0xF8
		float	m_damageFalloffEndDistance;		 // 0xFC
		float	m_timeToArmExplosion;		 // 0x100
		bool	m_hasVehicleDetonation;		 // 0x104
		bool	m_instantHit;		 // 0x105
		bool	m_stopTrailEffectOnUnspawn;		 // 0x106
	};


};

#endif
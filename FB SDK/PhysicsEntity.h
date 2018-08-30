#ifndef _PhysicsEntity_H
#define _PhysicsEntity_H
#include "Frostbite_Classes.h"
#include "PhysicsEntityBase.h"
#include "HavokPhysicsData.h"
#include "PhysicsEntityParts.h"
namespace fb
{
		class PhysicsEntity
		: public PhysicsEntityBase		// 0x00
	{
	public:
		PAD(0x8);								// 0x58
		AxisAlignedBox m_rbAabb;				// 0x60
		PhysicsEntityParts m_parts;				// 0x80
		PhysicsEntityData* m_data;				// 0x98
		HavokPhysicsData* m_havokPhysicsPart;	// 0x9C
		DWORD m_rb;								// 0xA0 hkpRigidBody*
		hkpShape* m_raycastShape;				// 0xA4
		DWORD m_rbProxy;						// 0xA8 hkpRigidBody*
		DWORD m_characterBody;					// 0xAC hkpRigidBody*
		INT m_simulationType;					// 0xB0
	}; // 0xB4
};

#endif
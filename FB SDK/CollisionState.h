#ifndef _CollisionState_H
#define _CollisionState_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CollisionState
	{
	public:
		Vec3 m_position;			// 0x00
		Vec3 m_normal;				// 0x10
		UINT m_materialIndex;		// 0x20
		UINT m_ownMaterialIndex;	// 0x24
		FLOAT m_speed;				// 0x28
		INT m_valid;				// 0x2C
	}; // 0x30

};

#endif
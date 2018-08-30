#ifndef _RayCastHit_H
#define _RayCastHit_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class RayCastHit
	{
	public:
		Vec3 m_position;					// 0x00
		Vec3 m_normal;						// 0x10
		PhysicsEntityBase* m_rigidBody;		// 0x20
		MaterialContainerPair* m_material;	// 0x24
		DWORD m_part;						// 0x28
		INT m_bone;							// 0x2C
		FLOAT m_lambda;						// 0x30
		PAD(0xC);							// 0x34
	}; // 0x40

};

#endif
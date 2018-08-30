#ifndef _CharacterPhysicsEntityCollisionShapes_H
#define _CharacterPhysicsEntityCollisionShapes_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class CharacterPhysicsEntityCollisionShapes
	{
	public:
		hkpShape* m_shapes[3];
		PAD(0xC);
		AxisAlignedBox m_aabbs[3];
	};
};

#endif
#ifndef _PhysicsEntityParts_H
#define _PhysicsEntityParts_H
#include "Frostbite_Classes.h"
#include "DynamicBitSet.h"
namespace fb
{
	class PhysicsEntityParts
	{
	public:
		DynamicBitSet m_enabled;			// 0x00
		LinearTransform* m_base;			// 0x08
		EntityBusPeer** m_transformNodes;	// 0x0C
		hkpShape** m_detailShapes;			// 0x10
		LPBYTE m_transformIndices;			// 0x14
	}; // 0x18

};

#endif
#ifndef _SpatialEntityData_H
#define _SpatialEntityData_H
#include "EntityData.h"
namespace fb
{
	class SpatialEntityData
		: public EntityData				// 0x00
	{
	public:
		PAD(0x4);						// 0x0C
		LinearTransform m_transform;	// 0x10
	}; // 0x50/ 0x08

};

#endif
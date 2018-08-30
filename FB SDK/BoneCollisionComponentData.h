#ifndef _BoneCollisionComponentData_H
#define _BoneCollisionComponentData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ComponentData.h"
namespace fb
{
	class BoneCollisionComponentData
		: public ComponentData								// 0x00
	{
	public:
		PAD(0x8);											// 0x58
		SkeletonCollisionData* m_skeletonCollisionData;		// 0x60
	}; // 0x64

};

#endif
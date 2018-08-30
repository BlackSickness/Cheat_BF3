#ifndef _SkeletonCollisionData_H
#define _SkeletonCollisionData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class SkeletonCollisionData
		: public DataContainer								// 0x00
	{
	public:
		SkeletonAsset* m_skeletonAsset;						// 0x08
		Array<BoneCollisionData> m_boneCollisionTransforms; // 0x0C
	};
};

#endif
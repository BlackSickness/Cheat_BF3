#ifndef _SkeletonAsset_H
#define _SkeletonAsset_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class SkeletonAsset
		: public Asset							// 0x00
	{
	public:
		Array<String> m_boneNames;				// 0x0C
		//String  m_boneNames;	
		Array<INT> m_hierarchy;					// 0x10
		Array<LinearTransform> m_localPose;		// 0x14
		Array<LinearTransform> m_modelPose;		// 0x18
		String m_weaponBoneName;				// 0x1C
		String m_headBoneName;					// 0x20
		String m_hipBoneName;					// 0x24
		String m_cameraBoneName;				// 0x28
	}; // 0x2C

};

#endif
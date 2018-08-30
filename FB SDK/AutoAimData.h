#ifndef _AutoAimData_H
#define _AutoAimData_H
#include "Frostbite_Classes.h"
namespace fb
{
	class AutoAimData
	{
	public:
		Vec3 m_autoAimOuterBoxOffset;		 // 0x00
		Vec3 m_autoAimOuterBoxExtends;		 // 0x10
		Vec3 m_autoAimInnerBoxOffset;		 // 0x20
		Vec3 m_autoAimInnerBoxExtends;		 // 0x30
		CharacterPoseType	m_poseType;		 // 0x40
	};
};

#endif
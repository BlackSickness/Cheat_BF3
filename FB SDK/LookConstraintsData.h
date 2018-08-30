#ifndef _LookConstraintsData_H
#define _LookConstraintsData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class LookConstraintsData
	{
	public:
		FLOAT m_minLookYaw;			// 0x00
		FLOAT m_maxLookYaw;			// 0x04
		FLOAT m_minLookPitch;		// 0x08
		FLOAT m_maxLookPitch;		// 0x0C
	}; // 0x10

};

#endif
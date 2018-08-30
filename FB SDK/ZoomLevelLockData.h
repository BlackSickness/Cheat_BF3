#ifndef _ZoomLevelLockData_H
#define _ZoomLevelLockData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ZoomLevelLockData
	{
	public:
		FLOAT m_outlineTaggedDistance;		// 0x00
		LockType m_lockType;				// 0x04
	}; // 0x08

};

#endif
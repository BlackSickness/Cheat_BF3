#ifndef _FiringDispersionData_H
#define _FiringDispersionData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class FiringDispersionData
	{
	public:
		FLOAT m_minAngle;			// 0x00
		FLOAT m_maxAngle;			// 0x04
		FLOAT m_increasePerShot;	// 0x08
		FLOAT m_decreasePerShot;	// 0x0C
	}; // 0x10

};

#endif
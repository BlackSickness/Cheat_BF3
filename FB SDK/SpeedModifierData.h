#ifndef _SpeedModifierData_H
#define _SpeedModifierData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class SpeedModifierData
	{
	public:
		FLOAT m_forwardConstant;		// 0x00
		FLOAT m_backwardConstant;		// 0x04
		FLOAT m_leftConstant;			// 0x08
		FLOAT m_rightConstant;			// 0x0C
	}; // 0x10

};

#endif
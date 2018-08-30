#ifndef _BreathControlData_H
#define _BreathControlData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class BreathControlData
		: public DataContainer						// 0x00
	{
	public:
		FLOAT m_breathControlTime;					// 0x08
		FLOAT m_breathControlReleaseTime;			// 0x0C
		FLOAT m_breathControlPenaltyMultiplier;		// 0x10
		FLOAT m_breathControlPenaltyTimeout;		// 0x14
	}; // 0x18

};

#endif
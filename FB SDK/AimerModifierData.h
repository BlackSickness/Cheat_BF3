#ifndef _AimerModifierData_H
#define _AimerModifierData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class AimerModifierData
		: public Asset						// 0x00
	{
	public:
		FLOAT m_lookSpeedMultiplier;		// 0x0C
		INT m_onlyInSupportedShooting;		// 0x10
	}; // 0x14

};

#endif
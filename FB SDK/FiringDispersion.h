#ifndef _FiringDispersion_H
#define _FiringDispersion_H
#include "Frostbite_Classes.h"
namespace fb
{
	class FiringDispersion
	{
	public:
		FLOAT m_currAngle;				// 0x00
		FLOAT m_multiplier;				// 0x04
		FiringDispersionData* m_data;	// 0x08
		PAD(0x10);						// 0x0C
	}; // 0x1C
};

#endif
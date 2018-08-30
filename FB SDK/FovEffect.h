#ifndef _FovEffect_H
#define _FovEffect_H
#include "Frostbite_Classes.h"
namespace fb
{
	
	class FovEffect
	{
	public:
		FLOAT m_fov;			// 0x00
		FLOAT m_fadeTime;		// 0x04
		FLOAT m_delay;			// 0x08
		INT m_active;			// 0x0C
	}; // 0x10

};

#endif
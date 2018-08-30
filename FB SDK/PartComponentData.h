#ifndef _PartComponentData_H
#define _PartComponentData_H
#include "Frostbite_Classes.h"
#include "ComponentData.h"
namespace fb
{
		class PartComponentData
		: public ComponentData		// 0x00
	{
	public:
		PAD(0x8);					// 0x58
		DWORD m_healthStates;		// 0x60 RefArray<HealthStateData>
		DWORD m_partLinks;			// 0x64 RefArray<PartLinkData>
		CHAR m_isSupported;			// 0x68
		CHAR m_isFragile;			// 0x69
		CHAR m_isNetworkable;		// 0x6A
		CHAR m_isWindow;			// 0x6B
		CHAR m_animatePhysics;		// 0x6C
		PAD(0x3);					// 0x6D
	}; // 0x70
};

#endif
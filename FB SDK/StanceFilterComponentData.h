#ifndef _StanceFilterComponentData_H
#define _StanceFilterComponentData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class StanceFilterComponentData
	{				
	public:
		PAD(0x60);
		int *m_validStances;                     // this+0x60
		float m_stanceChangeTime;                     // this+0x64
		PAD(0x4);
		bool m_filterSpecificActions;                     // this+0x6C
		bool m_undoParentStanceFilter;                     // this+0x6D
	}; // fb::StanceFilterComponentData

};

#endif
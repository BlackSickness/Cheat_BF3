#ifndef _StanceFilterComponent_H
#define _StanceFilterComponent_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class StanceFilterComponent // Inherited class at offset 0x10
	{
		virtual void  *funki0();// __vecDelDtor(unsigned int);	// V: 0x0
		virtual void *funki();//const class fb::StanceFilterComponentData & stanceFilterData();	// V: 0x4
		StanceFilterComponent * m_previousStanceFilter;                     // this+0x4
		EntryComponent * m_controllingEntry;                     // this+0x8
		float m_stanceSwitchTimer;                     // this+0xC
		class eastl::map<enum fb::EntryInputActionEnum,float,eastl::less<enum fb::EntryInputActionEnum>,fb::eastl_arena_allocator> m_cachedEntryInputActionMap;                     // this+0x10
	}; // fb::StanceFilterComponent

};

#endif
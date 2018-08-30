#ifndef _WeaponComponent_H
#define _WeaponComponent_H
#include "Frostbite_Classes.h"
namespace fb
{
		class WeaponComponent
	{
	public:
		class WeaponState
		{
			public:
			int m_barrelIndex;                     // this+0x0, len(0x4)

		}; // WeaponState

		eastl::vector<LinearTransform,eastl_arena_allocator> m_barrelTransforms;                     // this+0x0
		bool m_isEnabled;                     // this+0x10
		
	}; // fb::WeaponComponent

};

#endif
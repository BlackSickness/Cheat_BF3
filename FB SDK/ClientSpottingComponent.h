#ifndef _ClientSpottingComponent_H
#define _ClientSpottingComponent_H
#include "Frostbite_Classes.h"
#include "ClientComponent.h"
#include "SpottingComponent.h"
namespace fb
{
	class ClientSpottingComponent
		:public ClientComponent, // Inherited class at offset 0x0
		fb::network::IClientNetworkable, // Inherited class at offset 0x10
		public SpottingComponent // Inherited class at offset 0x1C
	{
		public:
		float m_currentTime;                     // this+0x20
		/*class eastl::queue<float,eastl::deque<float,fb::eastl_arena_allocator,64> >*/ void* m_spotTimestamps; // this+0x24
		float m_passiveSpottingTimer;                     // this+0x50
		float m_targetInAimTimer;                     // this+0x54
		bool m_needMoreAmmo;                     // this+0x58
		bool m_targetsInAim;                     // this+0x59
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x24

	}; // fb::ClientSpottingComponent

};

#endif
#ifndef _ProximityHook_H
#define _ProximityHook_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ProximityHook // Inherited class at offset 0x0
	{
		enum PhysicsEntities
		{
			 MaxPhysicsEntities                     // constant 0x20
		}; 
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void objectAdded(const class fb::PhysicsEntityBase &);	// V: 0x4
		virtual void objectRemoved(const class fb::PhysicsEntityBase &);	// V: 0x8
	/*	class fb::ProximityPhantom **/void* m_phantom;                     // 0x4
		/*class fb::ProximityPhantomListener **/void* m_listener;                     // 0x8
		bool m_onlyProximityObjects;                     // 0xC
		class HavokPhysicsManager * m_manager;                     // 0x10
		

		}; // fb::ProximityHook


};

#endif
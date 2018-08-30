#ifndef _Entity_H
#define _Entity_H

#include "Frostbite_Classes.h"
#include "EntityBusPeer.h"
#include "SupportsWeakPtr.h"
namespace fb
{


		
//new sup as pub
	class Entity
		: public EntityBusPeer, SupportsWeakPtr			// 0x00
	{
	public:
		DWORD m_weakTokenHolder;		// 0x04
		DWORD m_flags;					// 0x08
	}; // 0x0C

	


};

#endif
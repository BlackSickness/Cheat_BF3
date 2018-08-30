#ifndef _Component_H
#define _Component_H
#include "Frostbite_Classes.h"
#include "EntityBusPeer.h"
namespace fb
{
	class Component
		:public  EntityBusPeer						// 0x00
	{
	public:
		ComponentData* m_data;				// 0x04
		ComponentCollection* m_collection;	// 0x08
		PAD(0x4);							// 0x0C
	}; // 0x10
};

#endif
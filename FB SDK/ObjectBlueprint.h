#ifndef _ObjectBlueprint_H
#define _ObjectBlueprint_H
#include "Frostbite_Classes.h"
#include "Blueprint.h"
namespace fb
{
	class ObjectBlueprint
		: public Blueprint			// 0x00
	{
	public:
		DataContainer* m_object;	// 0x20
	}; // 0x24
};

#endif
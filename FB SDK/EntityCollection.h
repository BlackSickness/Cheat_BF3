#ifndef _EntityCollection_H
#define _EntityCollection_H
#include "Frostbite_Classes.h"
#include "EntityCollectionSegment.h"
namespace fb
{
	class EntityCollection
	{
	public:
	EntityCollectionSegment * firstSegment; // 0x0
	EntityCreator * creator; // 0x4
	}; 

};

#endif
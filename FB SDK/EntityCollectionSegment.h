#ifndef _EntityCollectionSegment_H
#define _EntityCollectionSegment_H
#include "Frostbite_Classes.h"
namespace fb
{
	class EntityCollectionSegment
	{
	public:
	eastl::vector<fb::Entity *> m_Collection;
	void * m_subLevel; // 0x10
	EntityCollectionSegment * m_prev; // 0x14
	EntityCollectionSegment * m_next; // 0x18
	DWORD m_iterableSize; // 0x1C
	DWORD m_collectionIndex; // 0x20
	};
};

#endif
#ifndef _AsyncRayCastQueue_H
#define _AsyncRayCastQueue_H
#include "Frostbite_Classes.h"
namespace fb
{
	class AsyncRayCastQueue
	{

		class Query
		{

			struct fb::Vec3 start;                     // this+0x0
			struct fb::Vec3 end;                     // this+0x10
			struct fb::SafeQueryResult * results;                     // this+0x20
			unsigned int resultCount;                     // this+0x24

		}; // Query

		 eastl::fixed_list<fb::AsyncRayCastQueue::Query,1,0> m_queries;                     // this+0x0
		const char * m_name;                     // this+0x98
		GameWorld * m_world;                     // this+0x9C
	
	}; // fb::AsyncRayCastQueue<1>

};

#endif
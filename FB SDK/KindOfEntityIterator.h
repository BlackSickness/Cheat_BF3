#ifndef _KindOfEntityIterator_H
#define _KindOfEntityIterator_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/EntityWorld.h"
namespace fb
{
	template<typename T> struct KindOfEntityIterator 
	:public fb::EntityWorld::EntityIterator
	{
			KindOfEntityIterator()
			{}

			KindOfEntityIterator(fb::EntityWorld* manager,fb::ClassInfo* classId, bool onlyIncludeIterable = true)
			{
				manager->kindOfQuery(classId,this,onlyIncludeIterable);
			}
	};

};

#endif
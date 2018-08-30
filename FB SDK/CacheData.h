#ifndef _CacheData_H
#define _CacheData_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CacheData
	{
		public:
		unsigned int value;                     // this+0x0
		unsigned int listener;                     // this+0x4
		class ListenerRec
		{

			PropertyModificationListener * listener;                     // this+0x0
			int name;                     // this+0x4

		}; // ListenerRec

		int listenerName;                     // this+0x8
		unsigned int listenerCount;                     // this+0x8
		unsigned int typeInfo;                     // this+0xC
		bool emptySource;                     // this+0x10

	}; // fb::CacheData/ 0x08

};

#endif
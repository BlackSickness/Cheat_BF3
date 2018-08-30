#ifndef _ComponentCollection_H
#define _ComponentCollection_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ComponentCollection
	{
	public:
		GameEntity* owner;					// 0x00
		BYTE playerCount;					// 0x04
		BYTE totalCount;					// 0x05
		BYTE offsetCount;					// 0x06
		PAD(0x1);							// 0x07
		ComponentInfo *getInfo( int index )
		{
            ComponentInfo *info = (ComponentInfo *)this;
            return &(info[index + 1]);
        }

	}; // 0x08

};

#endif
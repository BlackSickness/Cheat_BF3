#ifndef _ComponentInfo_H
#define _ComponentInfo_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ComponentInfo
    {
    public:
        fb::Component* component; //0x0000
        fb::Component* entry; //0x0004
        DWORD flags; //0x0008
    char _0x000C[4];

    };//Size=0x0010

};

#endif
#ifndef _ClientProximityHookImpl_H
#define _ClientProximityHookImpl_H
#include "Frostbite_Classes.h"
#include "ProximityHookImpl.h"
namespace fb
{
		class ClientProximityHookImpl
		:public ProximityHookImpl
	{
		LPVOID vtable;
	}; // fb::ClientProximityHookImpl

};

#endif
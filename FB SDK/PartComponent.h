#ifndef _PartComponent_H
#define _PartComponent_H
#include "Frostbite_Classes.h"
namespace fb
{
	template <class T>
	class PartComponent
		: public T							// 0x00
	{
	public:
		PhysicsEntity* m_physicsEntity;		// sizeof(T) + 0x00
		CHAR m_isNetworkable;				// sizeof(T) + 0x04
		PAD(0x7);							// sizeof(T) + 0x05
		INT m_healthStateIndex;				// sizeof(T) + 0x0C
	}; // sizeof(T) + 0x10

};

#endif
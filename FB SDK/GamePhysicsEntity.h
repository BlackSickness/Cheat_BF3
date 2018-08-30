#ifndef _GamePhysicsEntity_H
#define _GamePhysicsEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
	template <class T>
	class GamePhysicsEntity
		: public T				// 0x00
	{
	public:
		FLOAT m_health;			// sizeof(T)
	}; // sizeof(T) + 0x04

};

#endif
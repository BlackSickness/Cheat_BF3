#ifndef _ClientGhostGameEntity_H
#define _ClientGhostGameEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
		template <class T>
	class ClientGhostGameEntity
		: public T,						// 0x00
		public network::ClientGhost		// sizeof(T)
	{
	}; // sizeof(T) + 0x40
};

#endif
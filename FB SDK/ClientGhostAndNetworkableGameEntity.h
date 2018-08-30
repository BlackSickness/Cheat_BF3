#ifndef _ClientGhostAndNetworkableGameEntity_H
#define _ClientGhostAndNetworkableGameEntity_H
#include "Frostbite_Classes.h"
#include "ClientGhostGameEntity.h"
namespace fb
{
	class ClientGhostAndNetworkableGameEntity
		: public ClientGhostGameEntity<ClientPhysicsEntity>,	// 0x00
		public network::IClientNetworkable						// 0x68
	{
	}; // 0x70

};

#endif
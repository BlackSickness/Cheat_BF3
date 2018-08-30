#ifndef _ClientPhysicsEntity_H
#define _ClientPhysicsEntity_H
#include "Frostbite_Classes.h"
#include "GamePhysicsEntity.h"
#include "Hook.h"
namespace fb
{
	class ClientPhysicsEntity
		: public GamePhysicsEntity<ClientGameEntity>,		// 0x00
		public IRigidBodyHook								// 0x24
	{
	}; // 0x28
};

#endif
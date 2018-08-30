#ifndef _GamePhysicsEntityData_H
#define _GamePhysicsEntityData_H
#include "Frostbite_Classes.h"
#include "GameEntityData.h"
namespace fb
{
	class GamePhysicsEntityData
		: public GameEntityData				// 0x00
	{
	public:
		DataContainer* m_physicsData;		// 0x60
	}; // 0x64

};

#endif
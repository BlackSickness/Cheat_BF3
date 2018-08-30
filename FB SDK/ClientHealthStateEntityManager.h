#ifndef _ClientHealthStateEntityManager_H
#define _ClientHealthStateEntityManager_H
#include "Frostbite_Classes.h"
namespace fb
{
	
	class HealthStateEntityManager
	{
	public:
		LPVOID vftable;							// 0x00
		GameWorld* m_world;						// 0x04
		DWORD m_masterManager;					// 0x08
		PartComponentData* m_partComponent;		// 0x0C
		DWORD m_instanceId;						// 0x10
	}; // 0x14


	class ClientHealthStateEntityManager
		: public HealthStateEntityManager	// 0x00
	{
	public:
	}; // 0x14
};

#endif
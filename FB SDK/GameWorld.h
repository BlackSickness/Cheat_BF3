#ifndef _GameWorld_H
#define _GameWorld_H
#include "Frostbite_Classes.h"
#include "EntityWorld.h"
namespace fb
{
		class GameWorld
		: public EntityWorld,			// 0x00
		public IPhysicsRayCaster		// 0x840
	{
	public:
		DWORD m_spatialQueryManager;	// 0x844 SpatialQueryManager*
		IPhysicsManager* m_physicsManager;// 0x848 IPhysicsManager*
		LPVOID m_terrainHeightFunc;		// 0x84C
		LPVOID m_hasTerrainFunc;		// 0x850
		LPVOID m_terrainMaterial;		// 0x854
		LPVOID m_getSoldierFunc;		// 0x858
		//new
		__declspec(noinline) static GameWorld* Singleton();
	}; // 0x85C

};

#endif
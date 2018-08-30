#ifndef _TerrainEntity_H
#define _TerrainEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
		class TerrainEntity
	{
		void* m_physicsEntity; 
			void* m_terrain; 
	//	class fb::ScopedPtr<fb::TerrainPhysicsEntity> m_physicsEntity;                     // 0x0
	//	class fb::ResourceProxy<fb::ITerrain,1> m_terrain;                     // 0x4
		
	}; // fb::TerrainEntity

};

#endif
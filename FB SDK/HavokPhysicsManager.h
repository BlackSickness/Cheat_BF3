#ifndef _HavokPhysicsManager_H
#define _HavokPhysicsManager_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class HavokPhysicsManager
	//	:public IPhysicsManager
	{
		public:
		///*class fb::CriticalSection*/void* m_cs;             // 0x10
		PAD(0x30);//char Unknowns01[0x30]; // 0x0
		HookCollisionInfo * m_collisions;                    // 0x30
		HookProximityInfo * m_proximityObjects;              // 0x34
		/*class fb::HavokManager **/void *m_havokManager;    // 0x38
		MaterialGridManager * m_materialGridManager;         // 0x3C
		IPhysicsRayCaster * m_rayCaster;                     // 0x40
		/*class fb::HavokEntityFactory * */ void *m_entityFactory;      // 0x44
		/*class fb::RagdollSkeletonManager **/ void *m_ragdollSkeletonManager;                     // 0x48
		/*class fb::WaterPhysicsEntity **/void  *m_waterEntity;            // 0x4C
		MaterialContainerPair * m_defaultWaterMaterial;    // 0x50
		float m_maxVehicleHeight;                     // 0x54
		/*class EA::Thread::AtomicInt<unsigned int>*/void*  m_collisionCount;      // 0x58
		/*class EA::Thread::AtomicInt<unsigned int> */void* m_proximityObjectCount; // 0x5C
		/*class fb::TerrainPhysicsEntity */void*  m_terrainPhysicsEntity;        // 0x60
		/*class eastl::vector<fb::CharacterPhysicsEntity *,fb::eastl_arena_allocator>*/void*  m_characterEntities;                     // 0x64
		unsigned int m_worldCollisionCount;                     // 0x74
		unsigned int m_effectWorldCollisionCount;               // 0x78
		HookCollisionInfo * m_worldCollisions;                  // 0x7C
		HookCollisionInfo * m_effectWorldCollisions;            // 0x80
	/*	class eastl::map<hkpWorld *,eastl::map<int,eastl::set<hkpEntity *,eastl::less<hkpEntity *>,fb::eastl_arena_allocator>,eastl::less<int>,fb::eastl_arena_allocator>,eastl::less<hkpWorld *>,fb::eastl_arena_allocator>*/void*  m_addBatchMap;                     // 0x84
	/*	class eastl::map<hkpWorld *,eastl::set<hkpEntity *,eastl::less<hkpEntity *>,fb::eastl_arena_allocator>,eastl::less<hkpWorld *>,fb::eastl_arena_allocator>*/void*  m_removeBatchMap;                     // 0x9C
		bool m_batchModifyWorldEnabled;							// 0xB4
		bool m_backstep;										// 0xB5
		bool m_useDelayedWakeUp;								// 0xB6
		bool m_regionWakeEnabled;								// 0xB7
		float m_prevDt;											// 0xB8
		/*	class eastl::list<fb::PhysicsEntityBase const *,fb::eastl_arena_allocator> */void* m_clientSimulationCont;                     // 0xBC
		IPhysicsRenderer * m_renderer;                     // 0xC8
	/*	class fb::SmartRef<fb::PhysicsSettings>*/void*  m_settings;                     // 0xCC
	/*	class fb::SmartRef<fb::PhysicsRenderSettings>*/void*  m_renderSettings;                     // 0xD0
	/*	class eastl::list<hkpEntity *,fb::eastl_arena_allocator>*/void*  m_wakeUpEntityList;                     // 0xD4
	/*	class eastl::list<hkpEntity *,fb::eastl_arena_allocator>*/void*  m_wakeUpEWEntityList;                     // 0xE0
	/*	class eastl::map<hkpRigidBody *,eastl::vector<fb::AxisAlignedBox,fb::eastl_arena_allocator>,eastl::less<hkpRigidBody *>,fb::eastl_arena_allocator>*/void*  m_wakeUpRegionList;                     // 0xEC
	/*	class eastl::map<hkpRigidBody *,eastl::vector<fb::AxisAlignedBox,fb::eastl_arena_allocator>,eastl::less<hkpRigidBody *>,fb::eastl_arena_allocator> */void* m_wakeUpEWRegionList;                     // 0x104
		};

};

#endif
#ifndef _Level_H
#define _Level_H

#include "WorldData.h"

namespace fb
{
	class PathfindingBlob
	{
	public:
		GUID m_blobId;				// 0x00
		DWORD m_blobSize;			// 0x10
		Array<UINT> m_chunkSizes;	// 0x14
	}; // 0x18

	class LevelDescription
	{
	public:
		String m_name;							// 0x00
		String m_description;					// 0x04
		RefArray<DataContainer> m_components;	// 0x08
		BYTE m_isCoop;							// 0x0C
		BYTE m_isMenu;							// 0x0D
		BYTE m_isMultiplayer;					// 0x0E
		PAD(0x1);								// 0x0F
	}; // 0x10

	class LevelData
		: public WorldData								// 0x00
	{
	public:
		DataContainer* m_levelReference;				// 0x30
		PathfindingBlob m_blob;							// 0x34
		DataContainer* m_aiSystem;						// 0x4C
		FLOAT m_worldSizeXZ;							// 0x50
		LevelDescription m_description;					// 0x54
		String m_gameConfigurationName;					// 0x64
		DataContainer* m_emitterSystemAsset;			// 0x68
		RefArray<DataContainer> m_exclusionVolumes;		// 0x6C
		FLOAT m_defaultFov;								// 0x70
		FLOAT m_infantryFovMultiplier;					// 0x74
		DWORD m_maxEntityBusNetworkCount;				// 0x78
		DataContainer* m_soundStates;					// 0x7C
		DataContainer* m_voiceOverSystem;				// 0x80
		RefArray<Asset> m_voiceOverLogic;				// 0x84
		FLOAT m_maxVehicleHeight;						// 0x88
		String m_aerialHeightmapData;					// 0x8C
		DataContainer* m_enlightenShaderDatabase;		// 0x90
		RefArray<Asset> m_antProjectAssets;				// 0x94
		DataContainer* m_faceAnimationWaveMappings;		// 0x98
		DataContainer* m_animatedSkeletonDatabase;		// 0x9C
		RefArray<Asset> m_cameraModes;					// 0xA0
		RefArray<DataContainer> m_cameraTransitions;	// 0xA4
		DataContainer* m_hackForceBuild;				// 0xA8
		BYTE m_hugeBroadPhase;							// 0xAC
		BYTE m_freeStreamingEnable;						// 0xAD
		PAD(0x2);										// 0xAE
	}; // 0xB0

	class LevelSetupOption
	{
		String m_criterion;		// 0x00
		String m_value;			// 0x04
	}; // 0x08

	class LevelSetup
	{
	public:
		String m_name;									// 0x00
		Array<LevelSetupOption> m_inclusionOptions;		// 0x04
		DWORD m_difficultyIndex;						// 0x08
		PAD(0xC);										// 0x0C
	}; 
		class SubLevel
	{
	public:
		LPVOID vftable;											// 0x00
		eastl::vector<EntityCollectionSegment*> m_segments;		// 0x04
		eastl::vector<UINT> m_deletedEntities;					// 0x14
		Blueprint* m_subLevelData;								// 0x24
		SubLevel* m_parent;										// 0x28
		SubLevel* m_child;										// 0x2C
		SubLevel* m_sibling;									// 0x30
		MemoryArena* m_arena;									// 0x34
		ResourceCompartment m_compartment;						// 0x38
		Realm m_realm;											// 0x3C
		INT m_refCount;											// 0x40
		BYTE m_isDestroyed;										// 0x44
		PAD(3);									// 0x45
	}; // 0x48

	class PreloadedSubLevel
	{
		void* bundleName;                     // 0x0
		StreamRealm streamRealm;                     // 0x4
	}; // PreloadedSubLevel
	
	class CreationInfo
	{
		void *preloadedSubLevels;   
//		eastl::fixed_vector<fb::Level::PreloadedSubLevel,64,1,fb::eastl_arena_allocator> preloadedSubLevels;                     // 0x0								
	}; // CreationInfo

	class Level
		: public SubLevel	//, public PreloadedSubLevel	, public CreationInfo
	{
	public:

		GUID m_checksum;								// 0x48
		MaterialGridManager* m_materialGridManager;		// 0x58
		EntityBus* m_entityBus;							// 0x5C
		LevelData* m_data;								// 0x60
		TeamInfo* m_teamInfo;							// 0x64
		LevelSetup m_levelSetup;						// 0x68
	//old to get to physics from Level not Clientlevel over clientgamecont.
	//	PAD(0x38);// 0x80
	//	WorldRenderModule* m_worldRenderModule;  // 0xB8  184  oder 24+60=84
	//	HavokPhysicsManager* hkPhysicsManager;//0xBC
	//	GameWorld* m_gameWorld; //0x00C0  192
	}; //0xC0

	class IEmitterCollisionHook // Inherited class at offset 0x90
	{
		virtual void onCollision(const struct fb::Vec3 &, const struct fb::Vec3 &, const struct fb::Vec3 &, const class fb::MaterialContainerPair *, const class fb::MaterialContainerPair *, class fb::SpatialEntity *);	// V: 0x0		
	}; // fb::IEmitterCollisionHook

	class SimUpdateArgs
	{

		float deltaTime;                     // 0x0
		float filteredDeltaTime;                     // 0x4
		float interpolationFactor;                     // 0x8
		float previousInterpolationFactor;                     // 0xC

	}; // SimUpdateArgs

	class FrameInterpolationUpdateArgs
	{

		float deltaTime;                     // 0x0
		float interpolationFactor;                     // 0x4
		float previousInterpolationFactor;                     // 0x8

	}; // FrameInterpolationUpdateArgs

	class ClientLevel	
	//: public Level//, public IEmitterCollisionHook ,public SimUpdateArgs,public FrameInterpolationUpdateArgs
    {
    public:
		//old
		//char _skipped_0[184]; // PAD(0xB8);0x0000  
       // seems i need to pad 28 bytes less now
		//char _skipped_0[156]; //0x0000  
		PAD(0x9C);
		DebrisManager*    m_debrisManager;
		PAD(0x4);
        VegetationManager*    m_vegetationManager;
		PAD(0x4);
        EmitterManager*    m_emitterManager;
        void*    m_emitterRenderManager;
        void*    m_decalManager;
        WorldRenderModule* m_worldRenderModule;  // 0xB8 
        HavokPhysicsManager*  m_PhysicsManager; //0x00BC  
        GameWorld* m_gameWorld; //0x00C0  
        void* m_tweaker; //0x00C4 fb::ClientLevelTweaker 
        BYTE m_isFinalized; //0x00C8  
        BYTE m_hasStartedServer; //0x00C9  
        BYTE m_autoRespawn; //0x00CA  
        BYTE _ClientLevel_padding; //0x00C
    };//Size=0x00CC(204)
};

#endif
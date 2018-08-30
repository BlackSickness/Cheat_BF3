#ifndef _EntityWorld_H
#define _EntityWorld_H
#include "Frostbite_Classes.h"
namespace fb
{
	class EntityWorld
	{
	public:
		class SpatialSize
		{
		public:
			FLOAT halfSizeXZ;	// 0x00
			FLOAT minY;			// 0x04
		}; // 0x08

		class RemovedEntityInfo
		{
		public:
			Entity* entity;				// 0x00
			LPVOID func;				// 0x04
			EntityCreator* creator;		// 0x08
			LPVOID userData;			// 0x0C
		}; // 0x10
		
		class EntityCollection
		{
		public:
			EntityCollectionSegment* firstSegment;	// 0x00
			EntityCreator* creator;					// 0x04
		}; // 0x08

		class EntityIterator
        {
			public:
				eastl::vector<fb::EntityWorld::EntityCollection>* m_collections;    //offset = 0x0, length = 0x4
				fb::EntityCollectionSegment* m_currentSegment;    //offset = 0x4, length = 0x4
				unsigned int m_collectionIndexIt;    //offset = 0x8, length = 0x4
				unsigned int m_collectionIndexEnd;    //offset = 0xC, length = 0x4
				unsigned int m_entityIndexIt;    //offset = 0x10, length = 0x4
				unsigned int m_entityIndexEnd;    //offset = 0x14, length = 0x4
				byte m_onlyIncludeIterable;    //offset = 0x18, length = 0x1
				char pad_19[3];
		};

		void kindOfQuery(fb::ClassInfo* typeId, fb::EntityWorld::EntityIterator* result,bool onlyIncludeIterable = true)
        {
            typedef void (__thiscall* kindOfQuery_t)(fb::EntityWorld*,ClassInfo*,fb::EntityWorld::EntityIterator*,bool);

            kindOfQuery_t m_kindOfQuery = (kindOfQuery_t)KINDOFQUERY;//0x551790;

            m_kindOfQuery(this,typeId,result,onlyIncludeIterable);
        }

		virtual void addSpatialEntity(SpatialEntity *);	// V: 0x0
		virtual void removeSpatialEntity(SpatialEntity *);	// V: 0x4
		virtual void updateSpatialEntity(SpatialEntity *);	// V: 0x8
	
		//LPVOID vftable;														// 0x00
		SpatialSize m_spatialSize;											// 0x04
		eastl::fixed_vector<RemovedEntityInfo, 128, 2> m_removedEntities;	// 0x0C
		eastl::vector<EntityCollection> m_collections;						// 0x820
		SubLevel* m_rootLevel;												// 0x830
		WORD m_entityRuntimeId;												// 0x834
		PAD(0x2);															// 0x836
		CHAR m_isDeletingAllEntities;										// 0x838
		CHAR m_isLoadingSaveGame;											// 0x839
		PAD(0x2);															// 0x83A
	}; // 0x840

	

};

#endif
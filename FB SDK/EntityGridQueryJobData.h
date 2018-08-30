#ifndef _EntityGridQueryJobData_H
#define _EntityGridQueryJobData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class EntityGridQueryJobData
	{
	public:

		enum QueryType
		{
			 SphereQuery,                 // constant 0x0
			 RayQuery                     // constant 0x1
		}; // QueryType

		enum QueryDetail
		{

			Detailed,                    // constant 0x0
			Collision                     // constant 0x1

		}; // QueryDetail

		enum 
		{
			 DontCheckWaterBit,                     // constant 0x1
			 DontCheckTerrainBit,                   // constant 0x2
			 DontCheckRagdollBit,                   // constant 0x4
			 DontCheckCharacterBit,                 // constant 0x8
			 DontCheckGroupBit,                     // constant 0x10
			 DontCheckPhantomsBit,                  // constant 0x20
			 DontCheckMaterials,                    // constant 0x40
		}; // <unnamed-tag>

		/*union __m128*/LPD3DXMATRIX center;        // 0x0
		/*union __m128*/LPD3DXMATRIX radius;        // 0x10
		EntityGridQueryJobData::QueryType queryType;// 0x20
		EntityGridQueryJobData::QueryDetail queryDetail;// 0x24
		int maxQueryResult;                      // 0x28
		int excludeListSize;                     // 0x2C
		SpatialEntity * excludeList[0x8];        // 0x30
		int collisionFlags;                      // 0x50
		int materialFlags;                       // 0x54
//		ClassInfoRange classInfoRange;           // 0x58
		int entitiesToHitCount;                  // 0x60
		PhysicsEntityContainer * entitiesToHit;  // 0x64
		QueryResult * queryResult;               // 0x68
		short useGridCulling;                    // 0x6C
		short useOldCulling;                     // 0x6E

	}; // fb::EntityGridQueryJobData


};

#endif
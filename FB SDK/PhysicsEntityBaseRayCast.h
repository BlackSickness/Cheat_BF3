#ifndef _PhysicsEntityBaseRayCast_H
#define _PhysicsEntityBaseRayCast_H

namespace fb
{
	class PhysicsEntityBaseRayCast
	{
	public:
		enum 
		{
			 MaxExcludedEntities         // constant 0x8
		}; 

		enum RayCastParameters
		{
			MaxRayCastHitCount          // constant 0x5
		};

		enum RayCastFlags
		{
			  CheckDetailMesh,               // constant 0x1
			  IsAsyncRaycast,                // constant 0x2
			  DontCheckWater,                // constant 0x4
			  DontCheckTerrain,              // constant 0x8
			  DontCheckRagdoll,              // constant 0x10
			  DontCheckCharacter,            // constant 0x20
			  DontCheckGroup,                // constant 0x40
			  DontCheckPhantoms,             // constant 0x80
			  FORCE32BIT                     // constant 0x7FFFFFFF
		}; // RayCastFlags

		enum 
		{
			 InvalidMaterial                // constant 0xFF
		}; // <unnamed-tag>

		class RayCastOutput
		{
		public:
			Vec3 normal;                     // 0x0
			float lambda;                    // 0x10
			unsigned int part;               // 0x14
			unsigned int bone;               // 0x18
			unsigned int materialIndex;      // 0x1C
			MaterialContainerPair * materialPtr; // 0x1C
		}; // RayCastOutput

		class RayCastInput
		{
		public:
			struct fb::Vec3 from;                   // 0x0
			struct fb::Vec3 to;                     // 0x10
			unsigned int maxHitCount;               // 0x20
			unsigned int flags;                     // 0x24
			unsigned int materialFlags;             // 0x28

		}; // RayCastInput


	}; // fb::PhysicsEntityBaseRayCast



};

#endif
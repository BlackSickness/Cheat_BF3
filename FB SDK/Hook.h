#ifndef _Hook_H
#define _Hook_H

namespace fb
{
		class HookCollisionData
	{

		enum CollisionDataEnum
		{

			 InstantlyDestroyed,               // constant 0x80000000
			 IsPartBClientDstrMask,            // constant 0x40000000
			 SupportPointMask,                 // constant 0x20000000
			 IsBodyBOwner,                     // constant 0x10000000
			 PartIndexMask                     // constant 0xFFFFFF

		}; // CollisionDataEnum

		unsigned int m_data;                     // 0x0

	}; // fb::HookCollisionData

	class IRigidBodyHook
	{
	public:
		class CollisionInfo
		{

			Vec4 posAndSpeed;                // 0x0
			Vec3 normal;                     // 0x10
			HookCollisionData collisionData; // 0x20
			class BodyInfos
			{

				PhysicsEntityBase * body;             // 0x0
				unsigned int part;                    // 0x4
				MaterialContainerPair * material;     // 0x8
				bool destroyBody;                     // 0xC

			}; 

			BodyInfos bodyInfos[0x2] ;                     // 0x24

		}; // CollisionInfo
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void onCollision(const struct fb::IRigidBodyHook::CollisionInfo &);	// V: 0x4
		

	}; // fb::IRigidBodyHook


	class CharacterThreadData
	{

		eastl::vector<fb::CharacterPhysicsEntity *> entities;                     // 0x0
		float deltaTime;                     // 0x10
										
	}; // CharacterThreadData

	class HookCollisionInfo
	{

		IRigidBodyHook * hook;                     // 0x0
		IRigidBodyHook::CollisionInfo collisionInfo; // 0x10

	}; // HookCollisionInfo

	class HookProximityInfo
	{

/*		class fb::ProximityHook **/ void *hook;                     // 0x0
		PhysicsEntityBase * entity;                     // 0x4

	}; // HookProximityInfo

};

#endif
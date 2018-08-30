#ifndef _PhysicsEntityBase_H
#define _PhysicsEntityBase_H
#include "Frostbite_Classes.h"
#include "SpatialEntity.h"
namespace fb
{
	class PhysicsEntityBase
		: public SpatialEntity						// 0x00
	{
	public:

		
		virtual float mass();	// V: 0x70
		virtual float invMass();	// V: 0x74
		virtual const  Vec3 & linearVelocity();	// V: 0x78
		virtual const  Vec3 & angularVelocity();	// V: 0x7C
		virtual const  Vec3 & position();	// V: 0x80
		virtual void setSleeping(bool);	// V: 0x84
		virtual bool isSleeping();	// V: 0x88
		virtual const char * assetName();	// V: 0x8C
		virtual void addToWorld();	// V: 0x90
		virtual void removeFromWorld();	// V: 0x94
		virtual bool isAddedToWorld();	// V: 0x98
		virtual void addHook(class IRigidBodyHook *);	// V: 0x9C
		virtual void removeHook(class IRigidBodyHook *);	// V: 0xA0
		virtual unsigned int rayCast(struct PhysicsEntityBaseRayCast::RayCastOutput *, const struct PhysicsEntityBaseRayCast::RayCastInput *);	// V: 0xA4
		virtual void finalizeRayCast(struct PhysicsEntityBaseRayCast::RayCastOutput *, const struct Vec3 &, const struct Vec3 &);	// V: 0xA8
		virtual unsigned int partCount();	// V: 0xAC
		virtual class EntityBusPeer * partTransformNode(unsigned int);	// V: 0xB4
		virtual unsigned int getPartTransforms(struct QuatTransform *);	// V: 0xB8
		virtual const struct QuatTransform & getPartTransform(unsigned int, struct QuatTransform &);	// V: 0xBC
		virtual const struct QuatTransform & getTransformAsQuat(struct QuatTransform &);	// V: 0xC0
		virtual const class MaterialContainerPair * partMaterial(unsigned int, const struct Vec3 &);	// V: 0xC4
		virtual void setProperty(unsigned int, unsigned int);	// V: 0xD0
		virtual unsigned int property(unsigned int);	// V: 0xD4
		virtual unsigned int removeProperty(unsigned int);	// V: 0xD8
		
		PhysicsEntityUserData m_physicsUserData;	// 0x10
		PAD(0x8);									// 0x28
		ITypedObject* m_userData;					// 0x30
		DWORD m_em;									// 0x34 SpatialQueryManager
		HavokPhysicsManager* m_manager;				// 0x38 HavokPhysicsManager
		DWORD* m_hook;								// 0x3C HavokRigidBodyHook
		PAD(0x8);									// 0x40
		CHAR m_isAddedToEntityGrid;					// 0x48
		PAD(0xF);									// 0x49
	}; // 0x58


};

#endif
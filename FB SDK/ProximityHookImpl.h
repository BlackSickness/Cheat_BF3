#ifndef _ProximityHookImpl_H
#define _ProximityHookImpl_H
#include "Frostbite_Classes.h"
#include "FB SDK/ProximityHook.h"
#include "FB SDK/RayCastResult.h"
namespace fb
{
	class ProximityHookImpl
		:public ProximityHook
	{
	public:
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void func0(); // V: 0x0
		virtual void func1(); // V: 0x4
		virtual void func2(); // V: 0x8
		virtual SafeQueryResult * castRayAsync(const struct fb::Vec3 &, const struct fb::Vec3 &);	// V: 0xC
		virtual void releaseAsyncResult(SafeQueryResult *);	// V: 0x10
		class RayCast
		{

			RayCastResult m_result;                     // 0x0
			Vec3 m_startOffset;                     // 0x20
			Vec3 m_endOffset;                     // 0x30
			Vec3 m_lastStartAbsolute;                     // 0x40
			Vec3 m_lastEndAbsolute;                     // 0x50
			double m_lastUpdateTime;                     // 0x60
			float m_minimumRaycastUpdateTime;                     // 0x68
		
		}; // RayCast

		virtual class TerrainEntity * getTerrainEntity( Entity *);	// V: 0x14
		enum RayIdentifier
		{

			 RIInteraction,                    // constant 0x0
			 RIBash,                     // constant 0x1
			 RIIdentifierCount,                     // constant 0x2

		}; // RayIdentifier

		PhysicsEntityContainer m_entities[0x20];      // 0x20
		unsigned short m_numEntities;                 // 0x120
		CharacterPoseType m_pose;                     // 0x124
		double m_lastUpdateTime;                      // 0x128
		CharacterEntity * m_characterEntity;          // 0x130
		eastl::fixed_vector<fb::ProximityHookImpl::RayCast,2,1> m_rayCasts; // 0x140
		WeakPtr<GameEntity> m_interactableObject;     // 0x240
		float m_forwardInput;						  // 0x244
		
	}; // fb::ProximityHookImpl

};

#endif
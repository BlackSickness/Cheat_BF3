#ifndef _Ragdoll_H
#define _Ragdoll_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/Hook.h"
#include "FB SDK/ClientComponent.h"
namespace fb
{
	class RagdollCallbackHandler 
		:public IRigidBodyHook // Inherited class at offset 0x0
	{
		virtual void onRagdollRemoved();	// V: 0x10
		virtual bool onForceActivate();	// V: 0x14
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
	}; // fb::RagdollCallbackHandler

	class RagdollComponent 
		:public  RagdollCallbackHandler // Inherited class at offset 0x0	
	{
	public:
		virtual bool isServerSideRagdollEnabled();	// V: 0x0
		class RagdollCollisionCallbackHandler
		{

			RagdollCallbackHandler * m_soldierCallbackHandler;                     // 0x4
			RagdollComponent * m_animatedRagdoll;                     // 0x8
			int m_leftLegPart;                     // 0xC
			int m_rightLegPart;                     // 0x10
			bool m_nonRagdollContactDetected;                     // 0x14
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // RagdollCollisionCallbackHandler

		
		/*RagdollComponentData & */void*m_ragdollComponentData;                     // 0x10
		class fb::ant::AnimationSkeleton * m_skeleton;                     // 0x14
		/*struct fb::ant::PoseBlendDataInternal*/void* m_blendData;                     // 0x18
		struct fb::ant::UpdatePoseResultData m_updatePoseResultData;                     // 0x30
		/*class fb::RagdollGS*/void* m_gamestate;                     // 0x58
		LinearTransform m_ragdollModelSpace;                     // 0x70
		bool m_replicated;                     // 0xB0
		fb::QuatTransform * m_ragdollTransforms;                     // 0xB4
		class eastl::vector<fb::QuatTransform> m_boneVelocities;                     // 0xB8
		class eastl::vector<fb::QuatTransform> m_lastFrameBoneTransforms;                     // 0xC8
		/*class fb::WeakPtr<fb::RagdollEntity> */void*m_ragdoll;                     // 0xD8
		/*		class fb::WeakPtr<fb::ant::Animatable>*/void* m_animatable;                     // 0xDC
		class fb::RagdollComponent::RagdollCollisionCallbackHandler * m_ragdollCollisionCallbackHandler;                     // 0xE0
		/*		const struct fb::ant::RagdollSkeletonData **/void* m_ragdollSkeletonData;                     // 0xE4
		float m_activeTime;                     // 0xE8
		unsigned int m_boneCount;                     // 0xEC
		float m_forceBlendTimer;                     // 0xF0
		float m_forceBlendVelocity;                     // 0xF4
		float m_previousBlendValue;                     // 0xF8
		bool m_delayedActivatePending;                     // 0xFC
		bool m_reviveBlend;                     // 0xFD
		LinearTransform m_blendedCenterTransform;                     // 0x100
		LinearTransform m_originalCenterTransform;                     // 0x140
		LinearTransform m_centerTransform;                     // 0x180
		bool m_centerTransformSet;                     // 0x1C0
		class TrajectoryBlender
		{

			float m_waitTime;                     // 0x0
			float m_blendTime;                     // 0x4
			float m_originalBlendTime;                     // 0x8

		}; // TrajectoryBlender

		TrajectoryBlender m_trajectoryBlender;                     // 0x1C4

	}; // fb::RagdollComponent


	class ClientRagdollComponent
		:public ClientComponent, // Inherited class at offset 0x0
		 RagdollComponent, // Inherited class at offset 0x10
		network::IClientNetworkable // Inherited class at offset 0x1E0
	{

		class ClientRagdollComponentState
		{

			Quat stateRoot;                     // 0x0
			Quat stateRagdoll[0x10];                     // 0x10
			float stateHinge[0x10];                     // 0x110
			Vec3 stateTrans;                     // 0x150
			float blendValue;                     // 0x160
			unsigned int inReviveBlend;                     // 0x164, len(0x1)
			unsigned int maskTransform;                     // 0x165, len(0x1)
			unsigned int maskBlendValue;                     // 0x166, len(0x1)

		}; // ClientRagdollComponentState

		class Interpolator
			:public network::Interpolator<ClientRagdollComponent::ClientRagdollComponentState>   // Inherited class at offset 0x0
		{
			class fb::ClientRagdollComponent & m_ragdollComponent;                     // 0x48
			virtual void * __vecDelDtor(unsigned int);	// V: 0x10

		}; // Interpolator


		ClientRagdollComponent::Interpolator * m_interpolator;                     // 0x1EC
		ClientAntAnimatableComponent * m_animatableComponent;                     // 0x1F0
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x24

	}; // fb::ClientRagdollComponent
};

#endif
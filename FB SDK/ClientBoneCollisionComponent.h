#ifndef _ClientBoneCollisionComponent_H
#define _ClientBoneCollisionComponent_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/BoneCollisionComponentData.h"
#include "FB SDK/ClientComponent.h"
namespace fb
{
	class BoneCollisionComponent
	{
	public:
	
		enum Bone
		{
			Bone_RightShoulder,
			Bone_LeftShoulder,
			Bone_Pelvis,
			Bone_Chest,
			Bone_Head,
			Bone_RightThigh,
			Bone_LeftThigh,
			Bone_RightKnee,
			Bone_LeftKnee,
			Bone_Neck,
			Bone_UNK10,
			Bone_UNK11,
			Bone_Root,
			Bone_Total
		};

		class BoneTransformInfo
		{
		public:
			LinearTransform transform;		// 0x00
			Vec3 position;					// 0x40
		}; // 0x50
		
		BoneCollisionComponentData* m_boneCollisionData;							// 0x00
		ant::UpdatePoseResultData m_updatePoseResultData;							// 0x04
		ant::AnimationSkeleton* m_skeleton;											// 0x2C
		BoneTransformInfo* m_boneCollisionTransforms;								// 0x30
		eastl::vector<eastl::pair<INT, MaterialContainerPair *>> m_boneCollisionInfo;	// 0x34
		FLOAT m_latencyBufferTime;													// 0x44
		FLOAT m_latencyBufferInterval;												// 0x48
		PAD(0x174);																	// 0x4C
		BoneTransformInfo* m_latencyTransforms;										// 0x1C0
		CHAR m_hiLod;																// 0x1C4
		PAD(0x3);																	// 0x1C5
		DWORD m_debugColor;															// 0x1C8
		INT m_collisionBoneCount;													// 0x1CC
		byte m_collisionEnabled;													// 0x1D0
		byte m_collisionUpdated;													// 0x1D1
		CHAR m_isServer;															// 0x1D2
		PAD(0x1);																	// 0x1D3

	}; // 0x1D4


	class ClientBoneCollisionComponent
		: public ClientComponent,			// 0x00
		public BoneCollisionComponent		// 0x10
	{
	}; // 0x1E4

};

#endif
#ifndef _ANT_H
#define _ANT_H

namespace fb
{

	namespace ant
	{
		


		class AnimationUpdateArgs
		{

			float deltaTime;                     // this+0x0
			float physicsOnlyDeltaTime;                     // this+0x4
			unsigned int preceedingPhysicsOnlyTickCount;                     // this+0x8
			float tickDeltaTime;                     // this+0xC
			float absoluteTime;                     // this+0x10
			unsigned int currentTick;                     // this+0x14
			bool betweenFrames;                     // this+0x18
			float interpolationFactor;                     // this+0x1C
			struct fb::LinearTransform cameraTransform;                     // this+0x20
			float cameraFovScale;                     // this+0x60
			float animationPositionAdjustTime;                     // this+0x64
			float animationSimTime;                     // this+0x68
			bool animationSimUpdate;                     // this+0x6C
			bool interpolationEnabled;                     // this+0x6D
			bool physicsOnlyTick;                     // this+0x6E

		}; // fb::ant::AnimationUpdateArgs
		class UpdatePoseSkeletonData
		{
		public:
			LinearTransform * m_inverseDefaultPose;                     // 0x0
			eastl::vector<unsigned char> m_renderToAntConversionMap;                     // 0x4
			eastl::vector<unsigned char> m_antToRenderConversionMap;                     // 0x14
			eastl::vector<unsigned char> m_parents;                     // 0x24
			eastl::vector<unsigned char> m_childs;                     // 0x34
			eastl::vector<unsigned char> m_siblings;                     // 0x44
			eastl::vector<unsigned char> m_reducedToRenderConversionMap;                     // 0x54
			eastl::vector<unsigned char> m_renderToReducedConversionMap;                     // 0x64
			unsigned char m_trajectoryBoneIndex;                     // 0x74

		}; // fb::ant::UpdatePoseSkeletonData

	

		class UpdatePoseResultDataInternal
		{
		public:
			fb::QuatTransform * m_localTransforms;                     // this+0x0
			fb::QuatTransform * m_worldTransforms;                     // this+0x4
			LPD3DXMATRIX  m_renderTransforms;                     // this+0x8
			fb::QuatTransform * m_interpolatedLocalTransforms;                     // this+0xC
			fb::QuatTransform * m_interpolatedWorldTransforms;                     // this+0x10
			fb::QuatTransform * m_activeWorldTransforms;                     // this+0x14
			fb::QuatTransform * m_activeLocalTransforms;                     // this+0x18
			int m_slot;                     // this+0x1C
			int m_readerIndex;                     // this+0x20
			byte m_validTransforms;                     // this+0x24
			byte m_poseUpdateEnabled;                     // this+0x25
			byte m_poseNeeded;                     // this+0x26
			PAD(0x1);										// 0x27
		}; // fb::ant::UpdatePoseResultDataInternal

		class UpdatePoseResultData
			:public UpdatePoseResultDataInternal
		{
		public:
		}; // 0x28

		class UpdatePoseInitDataInternal
		{
		public:
			LinearTransform m_animationOffset;                     // this+0x0
			LinearTransform m_overrideBoneTransform;                     // this+0x40
			LinearTransform m_spineXTransform;                     // this+0x80
			EA::Ant::SQT * m_sourceTransforms;                     // this+0xC0
			int m_slot;                     // this+0xC4
			float m_spineXFactor;                     // this+0xC8
			float m_distanceFromCamera;                     // this+0xCC
			unsigned char m_spineXIndex;                     // this+0xD0
			unsigned char m_overrideBoneIndex;                     // this+0xD1
			bool m_enabled;                     // this+0xD2
			bool m_traj2refRig;                     // this+0xD3
			bool m_overrideTrajectory;                     // this+0xD4
			bool m_interpolateTrajectory;                     // this+0xD5
			bool m_teleport;                     // this+0xD6

		}; // fb::ant::UpdatePoseInitDataInternal

		class PoseBlendDataInternal
		{

			fb::QuatTransform * m_transforms;                     // this+0x0
			eastl::vector<unsigned char> * m_blendToRenderConversionMap;                     // this+0x4
			eastl::vector<unsigned char> * m_renderToBlendConversionMap;                     // this+0x8
			float m_factor;                     // this+0xC
			unsigned int m_boneCount;                     // this+0x10
			int m_slot;                     // this+0x14

		}; // fb::ant::PoseBlendDataInternal

		class PoseInterpolationDataInternal
		{

			enum LodLevel
			{

				LodFull,                    // constant 0x0
				LodReduced,                     // constant 0x1
				LodTrajectory,                    // constant 0x2
				NumLodLevels                     // constant 0x3

			}; // LodLevel

			fb::QuatTransform * m_startTransforms;                     // this+0x0
			fb::QuatTransform * m_endTransforms;                     // this+0x4
			float m_factor;                     // this+0x8
			bool m_enabled;                     // this+0xC
			LodLevel m_lodLevel;                     // this+0x10

		}; // fb::ant::PoseInterpolationDataInternal


		class AnimationSkeleton
		{
		public:

			class PoseResultMatrix
			{
				UpdatePoseResultDataInternal * m_elements[0x3];                     // this+0x0

			}; // PoseResultMatrix

			class TickPair
			{

				int first;                     // this+0x0
				int second;                     // this+0x4

			}; // TickPair

			class PoseBlock
			{
			public:
				fb::QuatTransform* m_localTransforms;				// 0x00
				fb::QuatTransform* m_worldTransforms;				// 0x04
				LPD3DXMATRIX m_renderTransforms;				// 0x08
				fb::QuatTransform* m_interpolatedWorldTransforms;	// 0x0C
				fb::QuatTransform* m_interpolatedLocalTransforms;	// 0x10
				fb::QuatTransform* m_targetLocalTransforms;			// 0x14
				UpdatePoseInitDataInternal * * m_initData;                     // this+0x18
				PoseBlendDataInternal * * m_blendData;                     // this+0x1C
				AnimationSkeleton::PoseResultMatrix * m_resultData;                     // this+0x20
				PoseInterpolationDataInternal * m_interpolationData;                     // this+0x24
				AnimationSkeleton::TickPair * m_interpolationTicks;                     // this+0x28

			}; // 0x2C

			// watch out
			//	/*const class EA::Ant::Rig::SkeletonAsset **/void* m_antSkeleton; // this+0x0

			SkeletonAsset* m_skeletonAsset;						// 0x00
			int m_boneCount;										// 0x04
			eastl::vector<LPCSTR> m_unknown;						// 0x08
			eastl::vector<char const *> m_boneNames;				// 0x18
			DWORD  m_sourceBoneCount;								// 0x28
			DWORD  m_dmaAlignedPoseSize2Comp;						// 0x2C
			DWORD  m_dmaAlignedPoseSize3Comp;						// 0x30
			DWORD  m_dmaAlignedPoseSize4Comp;						// 0x34
			//new
			UpdatePoseSkeletonData m_updatePoseSkeletonData;        // 0x38
			//changed from a4 to a0
			PAD(0xA0);												// 0x3C
			eastl::vector<INT> m_activePoseSlots;					// 0xDC
			DWORD m_poseCount;										// 0xEC
			eastl::fixed_vector<PoseBlock*, 16, 2> m_poseBlocks;	// 0xF0
			CHAR m_hasInterpolationTransforms;						// 0x144
			CHAR m_hasRenderTransforms;								// 0x145
			PAD(0x2);												// 0x146
		}; // 0x148
	};



};

#endif
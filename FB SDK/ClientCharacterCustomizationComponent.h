#ifndef _ClientCharacterCustomizationComponent_H
#define _ClientCharacterCustomizationComponent_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/CharacterCustomizationComponentState.h"
namespace fb
{
	class ClientCharacterCustomizationComponent
		:public ClientComponent, // Inherited class at offset 0x0
		network::IClientNetworkable, // Inherited class at offset 0x10
		network::Interpolator<CharacterCustomizationComponentState>, // Inherited class at offset 0x1C
		CharacterCustomizationComponent // Inherited class at offset 0x64
	{
		public:
		/*enum 
		{
			 kVersion                     // constant 0x1
		}; // <unnamed-tag>
		*/
		MeshModel * m_activeMeshModels1pArray;                     // 0xDC
		MeshModel * m_activeMeshModels3pArray;                     // 0xE0
		MeshModel * m_activeAttachedMeshModels1pArray;                     // 0xE4
		MeshModel * m_activeAttachedMeshModels3pArray;                     // 0xE8
		eastl::fixed_vector<MeshModel *,16,/*0*/1>m_active1pMeshes;                     // 0xEC
		eastl::fixed_vector<MeshModel *,16,/*0*/1> m_active3pMeshes;                     // 0x13C
		eastl::fixed_vector<MeshModel *,4,/*0*/1> m_activeAttached1pMeshes;                     // 0x18C
		eastl::fixed_vector<MeshModel *,4,/*0*/1> m_activeAttached3pMeshes;                     // 0x1AC
		class TransformBoneCountPair
		{
		public:
			LinearTransform baseTransform;              // 0x0
			LinearTransform * basePoseTransformsPtr;    // 0x40
			unsigned int boneCount;                     // 0x44
			unsigned int attachedBoneId;                // 0x48

		}; // TransformBoneCountPair

		eastl::fixed_vector<ClientCharacterCustomizationComponent::TransformBoneCountPair,4,/*0*/1> m_activeAttached1pTransforms;                     // 0x1D0
		eastl::fixed_vector<ClientCharacterCustomizationComponent::TransformBoneCountPair,4,/*0*/1> m_activeAttached3pTransforms;                     // 0x320
		/*class fb::PropertyWriter<int> */void*m_facePoserLibraryIndex;  // 0x470
		ClientAntAnimatableComponent * m_animatableComponent[0x2];		 // 0x474
		bool m_mustAlwaysBe3p;                      // 0x47C
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x24

	}; // fb::ClientCharacterCustomizationComponent


};

#endif
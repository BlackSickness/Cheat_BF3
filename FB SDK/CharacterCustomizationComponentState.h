#ifndef _CharacterCustomizationComponentState_H
#define _CharacterCustomizationComponentState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class CharacterCustomizationComponentState
	{

		const class fb::Asset * active1pAssets[0x10];                     // 0x0
		const class fb::ObjectVariation * active1pVariations[0x10];                     // 0x40
		const class fb::Asset * active3pAssets[0x10];                     // 0x80
		const class fb::ObjectVariation * active3pVariations[0x10];                     // 0xC0
		struct fb::CharacterCustomizationComponent::AttachedAssetAndSocketInfo activeAttached1pAssets[0x4]; // 0x100
		struct CharacterCustomizationComponent::AttachedAssetAndSocketInfo activeAttached3pAssets[0x4]; // 0x130
		int activeMeshIndices[0x10];                     // 0x160
		int activeAttachedMeshIndices[0x4];                     // 0x1A0
		unsigned int maskActive1pMeshesFlag;                     // 0x1B0, len(0x1)
		unsigned int maskActive3pMeshesFlag;                     // 0x1B1, len(0x1)
		unsigned int maskActiveAttached1pMeshesFlag;                     // 0x1B2, len(0x1)
		unsigned int maskActiveAttached3pMeshesFlag;                     // 0x1B3, len(0x1)

	}; // CharacterCustomizationComponentState
};

#endif
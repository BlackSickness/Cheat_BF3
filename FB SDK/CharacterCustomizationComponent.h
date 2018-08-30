#ifndef _CharacterCustomizationComponent_H
#define _CharacterCustomizationComponent_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class CharacterCustomizationComponent 
	{
	public:
		class AttachedAssetAndSocketInfo
		{

			Asset * asset;                     // 0x0
			ObjectVariation *  objectVariation;  // 0x4
			unsigned char socketIndex;           // 0x8
			unsigned char socketObjectDataIndex; // 0x9
		}; // AttachedAssetAndSocketInfo

		unsigned int m_skinnedVisualSocketCount;                     // 0x0
		unsigned int m_attachedSocketCount;                     // 0x4

		eastl::fixed_vector<unsigned int,16,1/*0*/> m_objectsPerSlotCount;                     // 0x8
		eastl::fixed_vector<unsigned int,4,1/*0*/>  m_objectsPerAttachedSocketCount;                     // 0x58
		
	}; // fb::CharacterCustomizationComponent
};

#endif
#ifndef _AntRef_H
#define _AntRef_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class AntRef
		
	{
		class ArrayTypeInfo
			:public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{
			
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t
			:public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{
			
		}; // ArrayTypeInfo_t

	
		int m_assetId;                     // this+0x0
		struct fb::Guid m_assetGuid;                     // this+0x4
		struct fb::Guid m_packageGuid;                     // this+0x14
		struct fb::Guid m_projectGuid;                     // this+0x24
		class fb::String m_assetName;                     // this+0x34
	
	}; // fb::AntRef

};

#endif
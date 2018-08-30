#ifndef _CameraShakeManager_H
#define _CameraShakeManager_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class CameraShakeManager
	{
	public:
		class CameraShakeInfo
		{

			float pitch;                     // this+0x0
			float yaw;                     // this+0x4
			float roll;                     // this+0x8
			float releaseTimer;                     // this+0xC

		}; // CameraShakeInfo

		eastl::fixed_map<void const *,CameraShakeManager::CameraShakeInfo,64,1,eastl::less<void const *>,fb::eastl_arena_allocator> m_modifiers;                     // this+0x0
		DWORD m_modifiersCs;                     // this+0x850
	
	}; // fb::CameraShakeManager

};

#endif
#ifndef _Rumble_H
#define _Rumble_H

namespace fb
{
	class Rumble
	{

		class PadRumble
		{

			float low;                     // this+0x0
			float high;                     // this+0x4
			float duration;                     // this+0x8

		}; // PadRumble

		class eastl::list<fb::Rumble::PadRumble,fb::eastl_arena_allocator> m_rumbles;                     // this+0x0
		float m_rumbleTimer;                     // this+0xC
		float m_continuousRumbleLow;                     // this+0x10
		float m_continuousRumbleHigh;                     // this+0x14
		float m_lastSetContinuousRumbleTime;                     // this+0x18
		float m_strengthScale;                     // this+0x1C
		bool m_isEnabled;                     // this+0x20
		
	}; // fb::Rumble

};

#endif
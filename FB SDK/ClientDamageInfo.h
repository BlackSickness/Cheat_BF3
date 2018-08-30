#ifndef _ClientDamageInfo_H
#define _ClientDamageInfo_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class ClientDamageInfo
	{

		struct fb::Vec3 m_position;                     // this+0x0
		struct fb::Vec3 m_direction;                     // this+0x10
		struct fb::Vec3 m_origin;                     // this+0x20
		float m_damage;                     // this+0x30
		float m_distributeDamageOverTime;                     // this+0x34
		unsigned int m_boneIndex;                     // this+0x38
		unsigned int m_hitDirection;                     // this+0x3C
		bool m_isBulletDamage;                     // this+0x40, len(0x1)

	}; // fb::ClientDamageInfo

};

#endif
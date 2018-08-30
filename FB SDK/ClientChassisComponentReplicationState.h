#ifndef _ClientChassisComponentReplicationState_H
#define _ClientChassisComponentReplicationState_H
#include "Frostbite_Classes.h"
namespace fb
{
		class ClientChassisComponentReplicationState
	{
	public:
	  Vec3 m_position;						// 0x00
	  Vec3 m_orientation;					// 0x10
	  Vec3 m_velocity;						// 0x20
	  Vec3 m_angularVelocity;				// 0x30
	  fb::CollisionState m_collision;		// 0x40
	}; // 0x70

};

#endif
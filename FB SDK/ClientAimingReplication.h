#ifndef _ClientAimingReplication_H
#define _ClientAimingReplication_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ClientAimingReplication
	{
	public:
		LPVOID vftable;			// 0x00
		FLOAT m_yaw;			// 0x04
		FLOAT m_pitch;			// 0x08
		FLOAT m_deltaYaw;		// 0x0C
		FLOAT m_deltaPitch;		// 0x10
		FLOAT m_activated;		// 0x14
	}; // 0x18

};

#endif
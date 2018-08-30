#ifndef _ClientLockingController_H
#define _ClientLockingController_H
#include "FB SDK/Frostbite_Classes.h"
#include "LockingController.h"
namespace fb
{
	class ClientLockingController
		: public LockingController					// 0x00
	{
	public:
		WeakPtr<ClientPhysicsEntity> m_currTarget;	// 0x1C
		Vec3 m_targetPos;							// 0x20
		WORD m_targetGhostId;						// 0x30
		PAD(0x2);									// 0x32
	}; // 0x34
};

#endif
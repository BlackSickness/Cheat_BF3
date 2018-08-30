#ifndef _SoldierAimingEnvironment_H
#define _SoldierAimingEnvironment_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class SoldierAimingEnvironment
	{
	public:
		ClientSoldierEntity* m_soldier;					// 0x00
		WeakPtr<ClientControllableEntity> m_target;		// 0x04
		CHAR m_hasTarget;								// 0x08
		CHAR m_hasFriendlyTarget;						// 0x09
		CHAR m_hasChangedTarget;						// 0x0A
		CHAR m_hasStickyBoxTarget;						// 0x0B
		CHAR m_hasSnapBoxTarget;						// 0x0C
		PAD(0x3);										// 0x0D
	}; // 0x10
};

#endif
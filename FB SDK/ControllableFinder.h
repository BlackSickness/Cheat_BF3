#ifndef _ControllableFinder_H
#define _ControllableFinder_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ControllableFinder
	{
	public:
		PAD(0x468);												// 0x00
		GameWorld* m_gameWorld;									// 0x468
		WeakPtr<ClientPlayer> m_ignoredPlayer;					// 0x46C
		WeakPtr<ClientControllableEntity> m_controllableInAim;	// 0x470
		PAD(0xC);												// 0x474
		Vec3 m_lastRayBegin;									// 0x480
		Vec3 m_lastRayEnd;										// 0x490
		RayCastHit m_lastHIt;									// 0x4A0
	}; // 0x4E0

};

#endif
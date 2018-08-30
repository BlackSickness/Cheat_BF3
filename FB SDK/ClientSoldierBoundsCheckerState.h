#ifndef _ClientSoldierBoundsCheckerState_H
#define _ClientSoldierBoundsCheckerState_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class ClientSoldierBoundsCheckerState
	{

		float leftForwardRayFraction;                     // 0x0
		float rightForwardRayFraction;                     // 0x4
		float rightBackRayFraction;                     // 0x8
		float leftBackRayFraction;                     // 0xC
		bool leftForwardRayHasHit;                     // 0x10, len(0x1)
		bool rightForwardRayHasHit;                     // 0x11, len(0x1)
		bool rightBackRayHasHit;                     // 0x12, len(0x1)
		bool leftBackRayHasHit;                     // 0x13, len(0x1)
		unsigned int maskForwardRaysChanged;                     // 0x14, len(0x1)
		unsigned int maskBackwardRaysChanged;                     // 0x15, len(0x1)
	
	}; // fb::ClientSoldierBoundsCheckerState

};

#endif
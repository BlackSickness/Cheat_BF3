#ifndef _ClientSoldierBoundsChecker_H
#define _ClientSoldierBoundsChecker_H
#include "Frostbite_Classes.h"
#include "SoldierBoundsChecker.h"
#include "ClientSoldierBoundsCheckerState.h"
namespace fb
{
	class ClientSoldierBoundsChecker
		:public network::IClientNetworkable, // Inherited class at offset 0x0
		SoldierBoundsChecker, // Inherited class at offset 0x60
		network::Interpolator<fb::ClientSoldierBoundsCheckerState> // Inherited class at offset 0xC
	{
		LPVOID vtable;
	}; // fb::ClientSoldierBoundsChecker

};

#endif
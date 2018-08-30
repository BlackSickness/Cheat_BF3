#ifndef _ClientSpottingTargetComponent_H
#define _ClientSpottingTargetComponent_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ClientSpottingTargetComponent
	{
	public:
		PAD(0x18);
		int m_spotType; //0x18 should be 1 to spot
		ClientPlayer *m_spotterPlayer; // 0x1C
		ClientPlayer *m_playerThatOrders; // 0x20
		float m_lastOrderTime; // 0x24
	};

};

#endif
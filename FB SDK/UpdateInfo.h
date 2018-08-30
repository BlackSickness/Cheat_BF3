#ifndef _UpdateInfo_H
#define _UpdateInfo_H
#include "Frostbite_Classes.h"
namespace fb
{
	class UpdateInfo // Inherited class at offset 0x0
	{

		void * queryResult;                     // this+0x0
		float deltaTime;                     // this+0x4
		float interpolationFactor;                     // this+0x8
		unsigned int ticks;                     // this+0xC
		UpdatePass updatePass;                     // this+0x10

	}; // fb::UpdateInfo

};

#endif
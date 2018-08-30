#ifndef _RayCastResult_H
#define _RayCastResult_H
#include "Frostbite_Classes.h"
namespace fb
{
	class RayCastResult
	{

		Vec3 normal;                     // 0x0
		WeakPtr<fb::PhysicsEntityBase> entity;                     // 0x10
		float fraction;                     // 0x14
		bool hasHit;                     // 0x18
		unsigned int part;                     // 0x1C
	
	}; // fb::RayCastResult

};

#endif
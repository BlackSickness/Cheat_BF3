#ifndef _PhysicsEntityContainer_H
#define _PhysicsEntityContainer_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class PhysicsEntityContainer
	{

		SpatialEntity * entity;                     // 0x0
		unsigned short classId;                     // 0x4
		unsigned short pad;                     // 0x6

	}; // fb::PhysicsEntityContainer

};

#endif
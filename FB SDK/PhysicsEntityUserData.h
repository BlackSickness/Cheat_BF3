#ifndef _PhysicsEntityUserData_H
#define _PhysicsEntityUserData_H

namespace fb
{
	class PhysicsEntityUserData
	{
	public:
		
		 char * materialIndices;                     // 0x0
		 int * materialFlags;                     // 0x4
		 void * partsEnabled;                     // 0x8
		 int flags;                     // 0xC
		 float mass;                     // 0x10
		 short partCount;                     // 0x14
		 char materialCount;                     // 0x16
		 char pad;                     // 0x17
	}; // 0x18

};

#endif
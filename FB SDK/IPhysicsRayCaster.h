#ifndef _IPhysicsRayCaster_H
#define _IPhysicsRayCaster_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class IPhysicsRayCaster
	{
	public:
	virtual bool physicsRayQuery(char* text, Vec3 *from, Vec3 *to, RayCastHit *hit, int flag, void* PhysicsEntityList);
	virtual struct SafeQueryResult   * asyncPhysicsRayQuery(const char *ident,Vec3 *from, Vec3 *to, unsigned int flags, void* excluded);
/*

// GameWorld_RayCast (as there are multiple rayCast overloads i quoted the params for the one i use)
// (const char *ident, 
fb::GameWorld::RayCastTest rayCastTest, 
fb::Vec3 *start, 
fb::Vec3 *end, 
fb::RayCastHit *hits, 
unsigned int maxHitCount, 
unsigned int materialFlags, 
unsigned int flags, 
eastl::fixed_vector<fb::PhysicsEntityBase const *,8,0> *excluded)
0x7ACBF0 

int __stdcall fb__GameWorld__asyncPhysicsRayQuery(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // ST40_4@1
  int v7; // ST44_4@1
  int v8; // esi@1
  int v9; // edx@1
  char v10; // [sp+20h] [bp-90h]@1

  fb__PhysicsEntityRayCastCollector__PhysicsEntityRayCastCollector(a2, a3, a4, a5);
  fb__ClassInfoRange__insert_0(37341560, 1);
  v8 = fb__GameWorld__asyncRayCast(a1, a2, a3, v6, v7, 1, a5, 0, a4, 0);
  nullsub_100(v8, v9, &v10);
  return v8;
}
*/

//virtual bool physicsRayQuery(const char *, const struct fb::Vec3 &, const struct fb::Vec3 &, class fb::RayCastHit &, unsigned int, const class eastl::fixed_vector<fb::PhysicsEntityBase const *,8,0,eastl::EASTLDummyAllocatorType> *);	// V: 0x0
//virtual struct SafeQueryResult * asyncPhysicsRayQuery(const char *, const struct fb::Vec3 &, const struct fb::Vec3 &, unsigned int, const class eastl::fixed_vector<fb::PhysicsEntityBase const *,8,0,eastl::EASTLDummyAllocatorType> *);	// V: 0x4
	
		static IPhysicsRayCaster* Singleton(void)
		{
			return *(IPhysicsRayCaster**)OFFSET_PHYSICSRAYQUERYVTABLE;
		}
	};


};

#endif
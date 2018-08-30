#ifndef _ClientChassisComponentSimulation_H
#define _ClientChassisComponentSimulation_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ClientChassisComponentSimulation
	{
	public:
		//LPVOID vftable;			// 0x00
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void prePhysicsUpdate(const struct fb::EntityUpdateInfo &, const class fb::EntryInput &);	// V: 0x4
		virtual void postPhysicsUpdate(const struct fb::EntityUpdateInfo &);	// V: 0x8
		virtual const struct fb::LinearTransform & worldTransform();	// V: 0xC
				
	}; // 0x04

};

#endif
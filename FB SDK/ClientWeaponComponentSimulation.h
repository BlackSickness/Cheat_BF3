#ifndef _ClientWeaponComponentSimulation_H
#define _ClientWeaponComponentSimulation_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class ClientWeaponComponentSimulation // Inherited class at offset 0x0
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void updateAsync(const class fb::EntryInput &, class fb::ClientPlayer *, const struct fb::Vec3 &, bool);	// V: 0x4
		virtual void updateSync(const class fb::EntryInput &, class fb::ClientPlayer *, const struct fb::Vec3 &, bool);	// V: 0x8
		virtual struct fb::LinearTransform shootSpace();	// V: 0xC
		virtual void updateShootSpace(const struct fb::LinearTransform &);	// V: 0x10
		virtual void addWeaponFiringCallbacks(class fb::WeaponFiringCallbacks *);	// V: 0x14
		virtual void removeWeaponFiringCallbacks(class fb::WeaponFiringCallbacks *);	// V: 0x18
		virtual bool updateRequired();	// V: 0x1C
	}; // fb::ClientWeaponComponentSimulation

};

#endif
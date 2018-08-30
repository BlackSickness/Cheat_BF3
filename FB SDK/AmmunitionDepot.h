#ifndef _AmmunitionDepot_H
#define _AmmunitionDepot_H
#include "Frostbite_Classes.h"
namespace fb
{
		class AmmunitionDepot
	{
	public:
		virtual void decrementPrimaryAmmo();	// V: 0x0
		virtual void resetHoldAndRelease();	// V: 0x4
		virtual const GameObjectData * firingHolderData();	// V: 0x8
		virtual bool shortReloadActive();	// V: 0xC
		virtual void heatInformation(bool &, float &);	// V: 0x10
		virtual bool isAmmoFull();	// V: 0x14
		virtual bool isAmmoInMagsFull();	// V: 0x18
		virtual bool isOutOfAmmo();	// V: 0x1C
		virtual float percentageAmmoLeft();	// V: 0x20
	}; // 0x04

};

#endif
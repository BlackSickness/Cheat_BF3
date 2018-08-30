#ifndef _IClientSoldierHealthModule_H
#define _IClientSoldierHealthModule_H
#include "Frostbite_Classes.h"
#include "SoldierHealthModuleBinding.h"
#include "SoldierHealthModuleGS.h"
#include "ClientDamageInfo.h"
#include "ClientDamageGiverInfo.h"

#include "SoldierHealthModuleData.h"
namespace fb
{
	class IClientSoldierHealthModule
	{
	public:
		//LPVOID vftable;		// 0x00
		virtual void * funcdummy();// __vecDelDtor(unsigned int);	// V: 0x0
		virtual void onDamage(const class fb::ClientDamageInfo &, const class fb::ClientDamageGiverInfo &);	// V: 0x4
		virtual float getNewPredictedHealth(float, bool, class fb::ClientPlayer *, bool, bool);	// V: 0x8
		virtual bool isAlive();	// V: 0xC
		virtual bool isDying();	// V: 0x10
		virtual bool isDead();	// V: 0x14
		virtual bool isManDown();	// V: 0x18
		virtual bool isInteractiveManDown();	// V: 0x20
		virtual bool isImmortal();	// V: 0x28
		virtual bool isFakeImmortal();	// V: 0x2C
		virtual bool hasRestrictedMovement();	// V: 0x30
		virtual void onHealthHasChanged(float);	// V: 0x34
		virtual enum fb::SoldierEntity::DeathType deathType();	// V: 0x38
		virtual class fb::ClientPlayer * damageGiver();	// V: 0x3C
		virtual void update(const class fb::EntryInput &);	// V: 0x40
		virtual void onSpawn();	// V: 0x44
		virtual void onUnSpawn();	// V: 0x48
		virtual class fb::SoldierHealthModuleGS * getGameState();	// V: 0x4C
		virtual const struct fb::SoldierHealthModuleBinding & getGameStateBinding();	// V: 0x50
		virtual const class fb::SoldierHealthModuleData * data();	// V: 0x54
		virtual float getManDownStateHealthPoints();	// V: 0x60
		virtual void setInteractiveManDownAllowed(bool);	// V: 0x64
		virtual float getManDownStateTime();	// V: 0x68
		virtual void resetLastDamageTimer();	// V: 0x6C
			
	}; // 0x04

};

#endif
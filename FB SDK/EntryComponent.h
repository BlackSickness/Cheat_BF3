#ifndef _EntryComponent_H
#define _EntryComponent_H
#include "Frostbite_Classes.h"
#include "WeaponFiring.h"
namespace fb
{
	class EntryComponent
	{
	public:
		class WeaponInfo
		{
		public:
			//new
			//LPVOID vftable;		// 0x00
			virtual void worldTransform(LinearTransform &);    // V: 0x0 
			virtual void getState(WeaponFiring &);    // V: 0x4 
			virtual void addWeaponFiringCallbacks(WeaponFiringCallbacks *);    // V: 0x8 
			virtual void removeWeaponFiringCallbacks(WeaponFiringCallbacks *);    // V: 0xC 
			virtual WeaponFiring * weaponFiring();    // V: 0x10 
			virtual Weapon * weapon();    // V: 0x14 
			virtual WeaponComponent * weaponComponent();	// V: 0x1C
			virtual void* serverWeaponComponent();	// V: 0x20
//		virtual ServerWeaponComponent * serverWeaponComponent();	// V: 0x20
		
		}; // 0x04

		class FiringCallbacks
		{
		public:
			LPVOID vftable;				// 0x00
			EntryComponent* m_entry;	// 0x04
			fb::WeaponInfo* m_info;			// 0x08
		}; // 0x0C
		class EntrySorter
		{
		}; // EntrySorter

		class Subscriber
		{
		public:
			//LPVOID vftable;		// 0x00
			virtual void onUnSpawn();	// V: 0x0
		}; // 0x04

		class State
		{
				public:
			int m_activeStance;                     // this+0x0
			int m_previousStance;                     // this+0x4
			bool m_stanceResetOnExit;                     // this+0x8

		}; // State

		virtual unsigned int getActiveStance();	// V: 0x0
		//virtual const class fb::EntryComponentData & entryData();	// V: 0x28
		//virtual void*entryData();
		//virtual bool onSwitchStance();	// V: 0x2C
	
		//LPVOID vftable;								// 0x00
		
		//FiringCallbacks **m_weapons;
		eastl::vector<FiringCallbacks*> m_weapons;	// 0x04
		eastl::vector<Subscriber*> m_subscribers;	// 0x14
		class fb::CharacterPoseConstraints * m_poseConstraints;                     // this+0x24
	
		//PAD(0x4);									// 0x24
	}; // 0x28


};

#endif
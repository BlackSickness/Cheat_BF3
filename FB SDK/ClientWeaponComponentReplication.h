#ifndef _ClientWeaponComponentReplication_H
#define _ClientWeaponComponentReplication_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ClientWeaponComponentReplication
		:public ClientWeaponComponentSimulation // Inherited class at offset 0x0
	{
	public:
	
		LPVOID vtable;
		ClientWeapon * m_weapon;                     // this+0x4
		ClientWeaponFiringReplication * m_replication;                     // this+0x8
		Component * m_owner;                     // this+0xC
		class FiringCallbacks
			:public WeaponFiringCallbacks // Inherited class at offset 0x0
		{
				ClientWeaponComponentReplication & m_weapon;                     // this+0x4
		}; // FiringCallbacks

		ClientWeaponComponentReplication::FiringCallbacks * m_firingCallback;                     // this+0x10
		LinearTransform m_shootSpace;                     // this+0x20
		bool m_updateRequired;                     // this+0x60
		/*const class fb::WeaponComponentData & */void * m_data;                     // this+0x64
		

	}; // fb::ClientWeaponComponentReplication

};

#endif
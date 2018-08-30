#ifndef _ClientWeaponComponent_H
#define _ClientWeaponComponent_H
#include "Frostbite_Classes.h"
#include "ClientPartComponent.h"
#include "WeaponComponent.h"
namespace fb
{
	class ClientWeaponComponent
		:public ClientPartComponent, // Inherited class at offset 0x0
		 WeaponComponent // Inherited class at offset 0x4C
	{
		class Interpolator
			:public network::Interpolator<fb::ClientWeaponComponentState> // Inherited class at offset 0x0
		{

			class fb::ClientWeaponComponent & m_parent;                     // this+0x40
			virtual void * __vecDelDtor(unsigned int);	// V: 0x10

		}; // Interpolator
		ClientWeaponComponent::Interpolator * m_interpolationObject;  // this+0x60
		ClientWeapon * m_weapon;                     // this+0x64
		ClientWeaponComponentSimulation * m_controller;                     // this+0x68
		ClientWeaponComponentReplication * m_replicatedWeapon;                     // this+0x6C
		ClientWeaponComponentPrediction * m_predictedWeapon;                     // this+0x70
		ClientLockingController * m_lockingController;                     // this+0x74
		ClientLockingController * m_secondaryLockingController;                     // this+0x78
		ClientPlayer * m_player;                     // this+0x7C
		class WeaponInfo
			:public fb::EntryComponent::WeaponInfo // Inherited class at offset 0x0
		{

		
			ClientWeaponComponent & m_weapon;                     // this+0x4
			ClientWeaponComponentReplication & m_replicated;                     // this+0x8
			ClientWeaponComponentPrediction & m_predicted;                     // this+0xC
			ClientStanceFilterComponent * m_stanceFilterComponent;                     // this+0x10

		}; // WeaponInfo

		ClientWeaponComponent::WeaponInfo * m_weaponInfo;                     // this+0x80
		class ClientWeaponFiringCallbacks
			:public fb::WeaponFiringCallbacks // Inherited class at offset 0x0
		{
			ClientWeaponComponent & m_weapon;                     // this+0x4
		}; // ClientWeaponFiringCallbacks
	public:
		ClientWeaponComponent::ClientWeaponFiringCallbacks * m_weaponFiringCallback;                     // this+0x84
		MeshModel * m_weaponMeshModel;                     // this+0x88
		ClientEntryComponent * m_firingEntry;                     // this+0x8C 140


		unsigned int m_meshTransformDirty;                     // this+0x90, len(0x4) 144
		unsigned int m_isFiring;                     // this+0x94, len(0x1)
		unsigned int m_hadInitialAnimUpdate;                     // this+0x95, len(0x1)
		unsigned int m_animHadVisualUpdate;                     // this+0x96, len(0x1)
		unsigned int m_replicatedBarrelIndex;                     // this+0x94
		unsigned int m_predictedBarrelIndex;                     // this+0x98
		//	virtual void * __vecDelDtor(unsigned int);	// V: 0x24

	}; // fb::ClientWeaponComponent


};

#endif
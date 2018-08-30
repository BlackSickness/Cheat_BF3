#ifndef _ClientWeaponComponentPrediction_H
#define _ClientWeaponComponentPrediction_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ClientWeaponComponentSimulation.h"
#include "FB SDK/WeaponFiringState.h"
namespace fb
{
	class ClientWeaponComponentPrediction
		:public ClientWeaponComponentSimulation // Inherited class at offset 0x0
	{
		class State
		{
			class fb::WeaponFiringState firingState;                     // this+0x0
		}; // State

		class fb::WeaponFiring * m_weaponFiring;                     // this+0x4
		struct fb::ClientWeaponComponentPrediction::State * m_currentState;                     // this+0x8
		struct fb::ClientWeaponComponentPrediction::State m_predictionState;                     // this+0xC
		struct fb::ClientWeaponComponentPrediction::State m_correctionState;                     // this+0x50
		class fb::ClientWeapon * m_weapon;                     // this+0x94
		class CorrectionCallbackHandler
			:public WeaponFiringCallbacks // Inherited class at offset 0x0
		{
			class fb::AmmunitionDepot & m_ammoDepot;                     // this+0x4
		
		}; // CorrectionCallbackHandler

		class fb::ClientWeaponComponentPrediction::CorrectionCallbackHandler * m_correctionCallbackHandler;                     // this+0x98
		/*const class fb::WeaponComponentData & */void*m_data;                     // this+0x9C
		const class fb::ClientComponent & m_owner;                     // this+0xA0
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::ClientWeaponComponentPrediction

};

#endif
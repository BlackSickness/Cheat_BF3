#ifndef _ClientSoldierWeaponsComponent_H
#define _ClientSoldierWeaponsComponent_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponSwayCallbackImpl.h"
#include "FB SDK/AnimatedWeaponGS.h"
#include "FB SDK/ClientWeaponsState.h"
#include "FB SDK/SoldierWeaponsComponent.h"
#include "FB SDK/WeaponSwitchingCallbacks.h"
#include "FB SDK/WeaponSwitchingState.h"
namespace fb
{
	class ClientSoldierWeaponsComponent
		: public ClientComponent,												// 0x00
		public network::IClientNetworkable,										// 0x10
		public network::Interpolator<LPVOID>,									// 0x18
		public SoldierWeaponsComponent,											// 0x58
		public WeaponSwitchingCallbacks,										// 0x60
		public WeaponFiringCallbacks											// 0x64
	{
	public:
		class ZoomCorrectionState
		{
			PAD(0x4);			// 0x00
			INT hasZoom;		// 0x04
			DWORD zoomLevel;	// 0x08
		}; // 0x0C

		class State
		{
		public:
			WeaponSwitchingState weaponSwitchingState;		// 0x00
			ZoomCorrectionState zoomCorrectionState;		// 0x20
		}; // 0x2C

		class ClientWeaponSwayCallbackImpl
			: public WeaponSwayCallbackImpl		// 0x00
		{
		public:
			INT m_hasBeenLocalPlayer;			// 0x50
		}; // 0x54

		DWORD m_correctionCallbackcHandler;										// 0x68
		PAD(0x4);																// 0x6C
		LinearTransform m_weaponTransform;										// 0x70
		ClientAntAnimatableComponent* m_animatableComponent[0x2];				// 0xB0
		ClientSoldierEntity* m_soldier;											// 0xB8
		eastl::vector<ClientSoldierWeapon*> m_weapons;							// 0xBC
		ClientAnimatedSoldierWeaponHandler* m_currentAnimatedWeaponHandler;		// 0xCC
		INT m_weaponMeshWasEnabled;												// 0xD0
		WeaponSwitching* m_replicatedWeaponSwitching;							// 0xD4
		WeaponSwitching* m_predictedWeaponSwitching;							// 0xD8
		ClientWeaponSwayCallbackImpl* m_weaponSwayCallback;						// 0xDC
		INT m_hasOrHadLocalPlayer;												// 0xE0
		SoldierAimingEnvironment* m_aimingEnvironment;							// 0xE4
		AimingConstraints* m_swimAimingConstraints;								// 0xE8
		PAD(0x64);																// 0xEC
		INT m_oldZoomState;														// 0x150
		INT m_lastZoomLevel;													// 0x154
		FLOAT m_timeSinceWeaponFire;											// 0x158
		CHAR m_needsWweapon1pResource;											// 0x15C
		CHAR m_weaponLightDisabled;												// 0x15D
		PAD(0x2);																// 0x15E
		State m_correctionState;												// 0x160
		State m_predictionState;												// 0x18C
		State* m_currentState;													// 0x1B8
		ClientWeaponsState m_currentWeaponsState;								// 0x1BC
		AnimatedWeaponGS m_gameState;											// 0x280
		PAD(0x28);																// 0x328
		LinearTransform m_globalAimOverride;									// 0x350
		INT m_globalAimOverrideMode;											// 0x390
		CHAR m_animationsDisabledForCurrentWeapon;								// 0x394
		CHAR m_instantReloadEnabled;											// 0x395
		CHAR m_flaggedForLowAmmo;												// 0x396
		PAD(0x1);																// 0x397
		AnimatedSoldierWeapon* m_lastAnimatedSoldierWeapon;						// 0x398
		DWORD m_1pWeaponAsset;													// 0x39C
		DWORD m_3pWeaponAsset;													// 0x3A0
	}; // 0x3A4


};

#endif
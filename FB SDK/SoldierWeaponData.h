#ifndef _SoldierWeaponData_H
#define _SoldierWeaponData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class SoldierWeaponData
	{ 
		PAD(0xa0);
		struct fb::Vec3 m_interactionOffset;                     // this+0xA0
		class fb::Array<fb::WeaponModifierData> m_weaponModifierData;                     // this+0xB0
		class fb::CtrRefBase m_aimingController;                     // this+0xB4
		class fb::CtrRefBase m_firstPersonCamera;                     // this+0xB8
		struct fb::HudData m_hud;                     // this+0xBC
		class fb::String m_damageGiverName;                     // this+0x100
		struct fb::PickupSettingsData m_pickupSettings;                     // this+0x110
		enum fb::WeaponAnimBaseSetEnum m_animBaseSet;                     // this+0x130
		class fb::CtrRefBase m_animationData;                     // this+0x134
		float m_renderFov;                     // this+0x138
		float m_zoomRenderFov;                     // this+0x13C
		class fb::CtrRefBase m_streamGroup1p;                     // this+0x140
		float m_weaponFloatParam;                     // this+0x144
		class fb::CtrRefBase m_soldierWeaponBlueprint;                     // this+0x148
		enum fb::QuickThrowTypeEnum m_quickThrowType;                     // this+0x14C
		class fb::CtrRefBase m_voiceOverInfo;                     // this+0x150
		enum fb::EntryInputActionEnum m_switchWeaponStateInputAction;                     // this+0x154
		class fb::String m_persistenceId;                     // this+0x158
		class fb::CtrRefBase m_customization;                     // this+0x15C
		class fb::RefArray<fb::SocketData> m_sockets;                     // this+0x160
		bool m_redeployWhenSwitchingWeaponStates;                     // this+0x164
		bool m_useQuickThrowOnAutomaticSwitchback;                     // this+0x165
		bool m_hideWhenOutOfAmmo;                     // this+0x166
		bool m_allowSwitchingToWeaponOutOfAmmo;                     // this+0x167
		bool m_lowerOnOwnTeam;                     // this+0x168
		bool m_enableBreathControl;                     // this+0x169
		bool m_canBeInSupportedShooting;                     // this+0x16A
		bool m_allowSwitchingToWeaponInVehicles;                     // this+0x16B
		bool m_allowSwitchingToWeaponReloading;                     // this+0x16C
		bool m_switchToPrimaryWhenOutOfAmmo;                     // this+0x16D
		class fb::CtrRefBase m_sourceModel;                     // this+0x170
		class fb::CtrRefBase m_sourceDataScene;                     // this+0x174
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4
	}; // fb::SoldierWeaponData
};

#endif
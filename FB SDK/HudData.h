#ifndef _HudData_H
#define _HudData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class HudData
	{
	public:
		float m_crosshairScaleMin;                     // this+0x0
		float m_crosshairScaleMax;                     // this+0x4
		float m_crosshairOpacityMin;                     // this+0x8
		float m_crosshairOpacityMax;                     // this+0xC
		float m_crosshairOpacityModifier;                     // this+0x10
		String m_crosshairTypeId;                     // this+0x14
		String m_weaponClass;                     // this+0x18
		float m_cameraShakeModifier;                     // this+0x1C
		float m_seaLevelAltFreq;                     // this+0x20
		float m_lowAmmoWarning;                     // this+0x24
		float m_reloadPrompt;                     // this+0x28
		int m_renderTargetIndex;                     // this+0x2C
		class fb::CtrRefBase m_hudPropertyList;                     // this+0x30
		byte m_showMinimap;                     // this+0x34
		byte m_infiniteAmmo;                     // this+0x35
		byte m_hideCrosshairWhenAimOnFriend;                     // this+0x36
		byte m_hideAmmo;                     // this+0x37
		byte m_useRangeMeter;                     // this+0x38
		byte m_usePredictedSight;                     // this+0x39
		byte m_useWeaponOrientations;                     // this+0x3A
		byte m_useVelocityVectorMarker;                     // this+0x3B
		byte m_useLockingController;                     // this+0x3C
		byte m_useThrust;                     // this+0x3D
		byte m_useGForce;                     // this+0x3E
		byte m_useSkidSlip;                     // this+0x3F
		byte m_useClimbRate;                     // this+0x40
		byte m_useAimWarning;                     // this+0x41
		byte m_useRenderTarget;                     // this+0x42
	
	}; // fb::HudData

};

#endif
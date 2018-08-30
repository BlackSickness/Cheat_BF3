#ifndef _ClientSoldierAimingSimulation_H
#define _ClientSoldierAimingSimulation_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/SoldierAimingSimulationData.h"
#include "FB SDK/AimAssist.h"
namespace fb
{
	class ClientSoldierAimingSimulation
	{
	public:
		enum ZoomFadeState
		{
			NoFade,
			Fading,
		};

		SoldierAimingSimulationData* m_data;					// 0x00
		SoldierAimingEnvironment* m_environment;				// 0x04
		AimAssist* m_fpsAimer;									// 0x08
		FLOAT m_yaw;											//0x0C	
		FLOAT m_pitch;											// 0x10
		FLOAT m_aimYawTimer;									// 0x14
		FLOAT m_aimPitchTimer;									// 0x18
		Vec2 m_sway;											// 0x1C
		PAD(0xC);												// 0x24
		AimAssist::UpdateContext m_updateContext;				// 0x30
		PAD(0x4);												// 0xEC
		DWORD m_zoomLevel;										// 0xF0
		DWORD m_oldZoomLevel;									// 0xF4
		DWORD m_switchToZoomLevel;								// 0xF8
		FLOAT m_zoomTransitionTimer;							// 0xFC	
		FLOAT m_fovMultiplier;									// 0x100
		FLOAT m_fovTransitionTimer;								// 0x104
		PAD(0x4);												// 0x108
		ZoomFadeState m_fadeState;								// 0x10C
		FLOAT m_fadeTimer;										// 0x110
		eastl::vector<AimerModifierData*> m_modifierData;		// 0x114
		FLOAT m_currentZoomTransitionTime;						// 0x124
		FLOAT m_currentFovTransitionTime;						// 0x128
	}; // 0x12C

};

#endif
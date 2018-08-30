#ifndef _SoldierAimingSimulationData_H
#define _SoldierAimingSimulationData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ZoomLevelData.h"
#include "FB SDK/AimingPoseData.h"
namespace fb
{
		class SoldierAimingSimulationData
		: public GameDataContainer					// 0x00
	{
	public:
		RefArray<ZoomLevelData> m_zoomLevels;		// 0x08
		FLOAT m_zoomTransitionTime;					// 0x0C
		DataContainer* m_aimAssist;					// 0x10
		AimingPoseData m_standPose;					// 0x14
		AimingPoseData m_crouchPose;				// 0x2C
		AimingPoseData m_pronePose;					// 0x44
		DWORD m_zoomTransitionTimeArray;			// 0x5C
		FLOAT m_fovTransitionTime;					// 0x60
		FLOAT m_fovDelayTime;						// 0x64
		Array<AimerModifierData*> m_modifiers;		// 0x68
		FLOAT m_aimingRange;						// 0x6C
		FLOAT m_lockedAimToTargetSpeed;				// 0x70
		INT m_rootToZoomAfterReload;				// 0x74
	}; // 0x78

};

#endif
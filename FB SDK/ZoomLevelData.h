#ifndef _ZoomLevelData_H
#define _ZoomLevelData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/DataContainer.h"
namespace fb
{
	class ZoomLevelData
		: public DataContainer
	{
	public:
		FLOAT m_fieldOfView;								// 0x08
		FLOAT m_timeYawMultiplier;							// 0x0C 
		FLOAT m_lookSpeedMultiplier;						// 0x10 
		FLOAT m_sprintLookSpeedMultiplier;					// 0x14 
		FLOAT m_moveSpeedMultiplier;						// 0x18
		FLOAT m_swayPitchMultiplier;						// 0x1C 
		FLOAT m_swayYawMultiplier;							// 0x20 
		FLOAT m_supportedSwayPitchMultiplier;				// 0x24 
		FLOAT m_supportedSwayYawMultiplier;					// 0x28 
		FLOAT m_timePitchMultiplier;						// 0x2C 
		FLOAT m_dispersionMultiplier;						// 0x30 
		FLOAT m_startFadeToBlackAtTime;						// 0x34 
		FLOAT m_recoilMultiplier;							// 0x38 
		FLOAT m_recoilFovMultiplier;						// 0x3C 
		FLOAT m_cameraImpulseMultiplier;					// 0x40 
		ZoomLevelActivateEventType m_onActivateEventType;	// 0x44
		FLOAT m_startFadeFromBlackAtTime;					// 0x48 
		FLOAT m_fadeToBlackDuration;						// 0x4C 
		FLOAT m_fadeFromBlackDuration;						// 0x50 
		FLOAT m_unknown;									// 0x54 
		CHAR m_fadeToBlackInZoomTransition;					// 0x58 
		CHAR m_useFovSpecialisation;						// 0x59 
		CHAR m_allowFieldOfViewScaling;						// 0x5A 
		PAD(0x1);											// 0x5B
	}; // 0x5C

};

#endif
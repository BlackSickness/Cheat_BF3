#ifndef _LockingControllerData_H
#define _LockingControllerData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class LockingControllerData
		: public DataContainer
	{
	public:
		Array<ZoomLevelLockData> m_zoomLevelLock;	// 0x08
		FLOAT m_lockTime; 							// 0x0C
		FLOAT m_releaseTime; 						// 0x10 
		FLOAT m_releaseOnNewTargetTime;				// 0x14 
		FLOAT m_sampleRate; 						// 0x18 
		FLOAT m_holdStillThreshold; 				// 0x1C 
		FLOAT m_rayLength; 							// 0x20 
		FLOAT m_minimumLockTime; 					// 0x24 
		FLOAT m_acceptanceAngle; 					// 0x28 
		FLOAT m_angleConstant; 						// 0x2C 
		FLOAT m_sensitivity; 						// 0x30 
		FLOAT m_distanceConstant; 					// 0x34 
		CHAR m_positionOnly; 						// 0x38 
		CHAR m_lockOnWorldSpacePos; 				// 0x39 
		CHAR m_lockOnVisibleTargetsOnly;			// 0x3A 
		CHAR m_lockOnEmptyVehicles; 				// 0x3B 
	};

};

#endif
#ifndef _SoldierAimAssistData_H
#define _SoldierAimAssistData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/GameDataContainer.h"
namespace fb
{
	
	class SoldierAimAssistData
		: public GameDataContainer								// 0x00
	{
	public:
		PAD(0x8);												// 0x08
		Vec3 m_eyePosOffset;									// 0x10 
		Vec3 m_stickyBoxScale;									// 0x20 
		Vec3 m_snapDistanceScale;								// 0x30 
		Vec3 m_snapBoxScale;									// 0x40 
		Vec3 m_stickyDistanceScale;								// 0x50 
		Vec3 m_maxAcceleration;									// 0x60 
		FLOAT m_accelerationDamping;							// 0x68 
		FLOAT m_accelerationInputThreshold;						// 0x6C 
		FLOAT m_accelerationMultplier;							// 0x70 
		FLOAT m_squaredAcceleration;							// 0x74 
		FLOAT m_yawSpeedStrength;								// 0x78 
		Array<FLOAT> m_zoomedInputPolynomial;					// 0x7C
		FLOAT m_accelerationTimeThreshold;						// 0x80 
		Array<FLOAT> m_attractDistanceFallOff;					// 0x84
		FLOAT m_attractUserInputMultiplier;						// 0x88 
		FLOAT m_attractOwnSpeedInfluence;						// 0x8C 
		FLOAT m_attractTargetSpeedInfluence;					// 0x90 
		FLOAT m_attractOwnRequiredMovementForMaximumAttract;	// 0x94 
		FLOAT m_attractStartInputThreshold;						// 0x98 
		FLOAT m_attractZoomingMultiplier;						// 0x9C 
		FLOAT m_attractZoomingPostTime;							// 0xA0 
		FLOAT m_attractYawStrength;								// 0xA4 
		FLOAT m_attractPitchStrength;							// 0xA8 
		FLOAT m_pitchSpeedStrength;								// 0xAC 
		FLOAT m_attractSoftZone;								// 0xB0 
		Array<FLOAT> m_inputPolynomial;							// 0xB4
		CHAR m_useYawAcceleration;								// 0xB8 
		CHAR m_usePitchAcceleration;							// 0xB9
		PAD(0x2);												// 0xBA
	}; // 0xBC

};

#endif
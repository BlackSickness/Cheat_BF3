#ifndef _ClientSoldierPrediction_H
#define _ClientSoldierPrediction_H
#include "Frostbite_Classes.h"
#include "ClientSoldierSimulation.h"
#include "IInputFilter.h"
namespace fb
{
		class ClientSoldierPrediction
		: public ClientSoldierSimulation,				// 0x00
		public IInputFilter								// 0x08
	{
	public:
		class DeltaState
		{
		public:
			Vec3 position;		// 0x00
			Vec3 velocity;		// 0x10
			Vec3 eyePosition;	// 0x20
		}; // 0x30

		PAD(0x4);										// 0x0C
		DeltaState m_correctionDelta;					// 0x10
		DeltaState m_frameCorrectionDelta;				// 0x40
		Vec3 m_velocity;								// 0x70
		FLOAT m_correctionInterpolationTime;			// 0x80
		FLOAT m_correctionInterpolationTimer;			// 0x84
		FLOAT m_frameInterpolationFactor;				// 0x88
		INT m_noInterpolateNextCorrection;				// 0x8C
		CharacterPhysicsEntityState* m_currentState;	// 0x90
		PAD(0xC);										// 0x94
		CharacterPhysicsEntityState m_predictionState;	// 0xA0
		CharacterPhysicsEntityState m_correctionState;	// 0x1A0
		SoldierEntityActionState m_actionState;			// 0x2A0
	}; // 0x2A4

};

#endif
#ifndef _AimAssist_H
#define _AimAssist_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/AimingConstraints.h"
namespace fb
{
	class AimAssist
	{
	public:
		class UpdateContext
		{
		public:
			FLOAT deltaTime;				// 0x00
			Vec2 movementInput;				// 0x04
			Vec2 aimingInput;				// 0x0C
			FLOAT minimumPitch;				// 0x14
			FLOAT maximumPitch;				// 0x18
			FLOAT lookSpeedmUltiplier;		// 0x1C
			FLOAT aimScale;					// 0x20
			PAD(0xC);						// 0x24
			LinearTransform reticuleSpace;	// 0x30
			Vec3 reticuleSpeed;				// 0x70
			FLOAT reticuleFieldOfView;		// 0x80
			CHAR hasStickyTarget;			// 0x84
			CHAR hasSnapTarget;				// 0x85
			CHAR forceAimSnap;				// 0x86
			CHAR usePitchZoomSnap;			// 0x87
			FLOAT attractZoomMultiplier;	// 0x88
			FLOAT targetRadius;				// 0x8C
			Vec3 targetPosition;			// 0x90
			Vec3 targetSpeed;				// 0xA0
			DWORD zoomLevel;				// 0xB0
			FLOAT zoomTransitionTimer;		// 0xB4
			INT isMouseInput;				// 0xB8
		}; // 0xBC

		SoldierAimAssistData* m_data;				// 0x00
		AimingConstraints* m_aimingConstraints;		// 0x04
		DWORD m_lastZoomLevel;						// 0x08
		FLOAT m_yaw;								// 0x0C
		PAD(0x8);									// 0x10
		FLOAT m_pitch;								// 0x18
		//shifted by 8 bytes after this
		Vec2 m_speed;								// 0x14
		FLOAT m_acceleration;						// 0x1C
		FLOAT m_accelerationTimer;					// 0x20
		FLOAT m_attractZoomPostTimer;				// 0x24
		FLOAT m_targetDistance;						// 0x28
		FLOAT m_softZoneLambda;						// 0x2C
		FLOAT m_polynomialFactor;					// 0x30
		CHAR m_useAimAssist;						// 0x34
		CHAR m_useInputPolynomials;					// 0x35
		CHAR m_hasChangedZoomed;					// 0x36
		CHAR m_isSnapZoom;							// 0x37
	}; // 0x38

};

#endif
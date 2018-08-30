#ifndef _CameraData_H
#define _CameraData_H
#include "Frostbite_Classes.h"
#include "GameObjectData.h"
namespace fb
{
	class CameraData
		: public GameObjectData				// 0x00
	{
	public:
		Vec3 m_occlusionRayOffset;			// 0x10
		FLOAT m_shakeFactor;				// 0x20
		FLOAT m_preFadeTime;				// 0x24
		FLOAT m_fadeTime;					// 0x28
		FLOAT m_fadeWaitTime;				// 0x2C
		FLOAT m_soundListenerRadius;		// 0x30
		DataContainer* m_viewFx;			// 0x34
		FLOAT m_nearPlane;					// 0x38
		FLOAT m_soundOcclusion;				// 0x3C
		INT m_stayFadedWhileStreaming;		// 0x40
	}; // 0x44

};

#endif
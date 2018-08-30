#ifndef _CameraContext_H
#define _CameraContext_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CameraContext
	{
	public:
		PAD(0x8);			// 0x00
		LinearTransform m_transform;			// 0x08
		LinearTransform m_targetTransform;		// 0x48
		CameraIds m_cameraId;					// 0x88
		DWORD m_cameraActivePosition;			// 0x8C
	}; // 0x90

};

#endif
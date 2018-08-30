#ifndef _Camera_H
#define _Camera_H
#include "Frostbite_Classes.h"
#include "ITypedObjectWithRefCount.h"
namespace fb
{
	class Camera
		: public ITypedObjectWithRefCount		// 0x00
	{
	public:
		PAD(0x8);								// 0x08
		LinearTransform m_transform;			// 0x10
		Vec2 m_viewportOffset;					// 0x50
		PAD(0x4);								// 0x58
		FovEffect m_fovInEffect;				// 0x5C
		FovEffect m_fovOutEffect;				// 0x6C
		CameraData* m_data;						// 0x7C
		FLOAT m_fov;							// 0x80
		FLOAT m_dofFocusDistance;				// 0x84
	}; // 0x88
};

#endif
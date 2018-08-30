#ifndef _FreeCameraInput_H
#define _FreeCameraInput_H
#include "Frostbite_Classes.h"
#include "Input.h"
namespace fb
{
		class FreeCameraInput
		: public Input						// 0x00
	{
	public:
		PAD(0x8);							// 0x08
		Vec3 m_move;						// 0x10
		Vec3 m_rotate;						// 0x20
		DWORD m_simTickCount;				// 0x30
		FLOAT m_inverseTick;				// 0x34
		FLOAT m_fovIncrease;				// 0x38
		InputActionMapping* m_map;			// 0x3C
		INT m_moveSpeed;					// 0x40
		INT m_rotateSpeed;					// 0x44
		CHAR m_hadPostFrame;				// 0x48
		CHAR m_turboSpeed;					// 0x49
		CHAR m_enabled;						// 0x4A
		PAD(0x1);							// 0x4B
	}; // 0x4C

};

#endif
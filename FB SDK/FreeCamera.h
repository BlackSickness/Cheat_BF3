#ifndef _FreeCamera_H
#define _FreeCamera_H
#include "Frostbite_Classes.h"
#include "Camera.h"
namespace fb
{
		class FreeCamera
		: public Camera								// 0x00
	{
	public:
		class State
		{
		public:
			FLOAT rotateLeftRight;		// 0x00
			FLOAT rotateUpDown;			// 0x04
			FLOAT moveLeftRight;		// 0x08
			FLOAT moveUpDown;			// 0x0C
			FLOAT moveReverseForward;	// 0x10
			FLOAT increaseFov;			// 0x14
		}; // 0x18

		PAD(0x8);									// 0x88
		FreeCameraInput* m_currentInput;			// 0x90
		FreeCameraInput* m_defaultCameraInput;		// 0x94
		FreeCameraInput* m_editorCameraInput;		// 0x98
		State m_realState;							// 0x9C
		State m_wantedState;						// 0xB4
		PAD(0x4);									// 0xCC
		Vec3 m_targetPos;							// 0xD0
		FLOAT m_rotateLeftRightHeldDown;			// 0xE0
		FLOAT m_rotateUpDownHeldDown;				// 0xE4
		FLOAT m_moveLeftRightHeldDown;				// 0xE8
		FLOAT m_moveUpDownHeldDown;					// 0xEC
		FLOAT m_moveReverseFowardHeldDown;			// 0xF0
		FLOAT m_increaseFovHeldDown;				// 0xF4
	}; // 0xF8

};

#endif
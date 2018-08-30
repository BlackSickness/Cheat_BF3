#ifndef _CameraComponent_H
#define _CameraComponent_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CameraComponent // Inherited class at offset 0x10
	{
	public:

		class State
		{
				public:
			bool m_alternateViewActive;                     // this+0x0
			bool m_isFadingOut;                     // this+0x1
			float m_transitionTimer;                     // this+0x4

		}; // State

				
	}; // fb::CameraComponent
};

#endif
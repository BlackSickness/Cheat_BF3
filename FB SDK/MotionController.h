#ifndef _MotionController_H
#define _MotionController_H

//#include "../Frostbite_classes.h"

namespace fb
{

	class MotionControllerState
	{

		Vec2 axis;                     // this+0x0
		bool digitalButtons[0xD];      // this+0x8

	}; // fb::MotionControllerState

	class MotionController
	{
	public:
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual bool init();	// V: 0x4
		virtual void preFrameUpdate(float);	// V: 0x8
		virtual void sample(float);	// V: 0xC
		virtual void sampleBetweenFrames(float);	// V: 0x10
		virtual void setVibration(float, bool);	// V: 0x18
		struct MotionControllerState m_state;                     // this+0x4
		struct MotionControllerState m_oldState;                     // this+0x1C
	};


};

#endif
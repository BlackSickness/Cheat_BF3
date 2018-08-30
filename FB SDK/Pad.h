#ifndef _Pad_H
#define _Pad_H

//#include "../Frostbite_classes.h"

namespace fb
{


	class Pad
	{
	public:
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual bool init();	// V: 0x4
		virtual void preFrameUpdate(float);	// V: 0x8
		virtual void sample(float);	// V: 0xC
		virtual void sampleBetweenFrames(float);	// V: 0x10
		virtual void setVibration(float, float, bool);	// V: 0x40
		
		DWORD m_state;                     // 0x4
		bool m_vibrationActive;                     // 0x9C
		bool m_vibrateTimerActive;                     // 0x9D
		bool m_killVibration;                     // 0x9E
		bool m_isActivePortLocked;                     // 0x9F
		float m_vibrateCountdown;                     // 0xA0
		void* m_suppressedPadIds;                     // 0xA4

	};


};

#endif
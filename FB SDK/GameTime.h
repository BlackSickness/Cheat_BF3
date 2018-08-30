#ifndef _GameTime_H
#define _GameTime_H

//#include "../Frostbite_classes.h"

namespace fb
{

	class GameTime
	{
	public:
		DWORD m_ticks;						// 0x00
		DWORD m_tickFrequency;				// 0x04
		DWORD m_tickIndexInFrame;			// 0x08
		DWORD m_lastTickIndexInFrame;		// 0x0C
		DWORD m_tickCountInFrame;			// 0x10
		FLOAT m_deltaTime;					// 0x14
		FLOAT m_passedDeltaTimeInFrame;		// 0x18
		DOUBLE m_time;						// 0x1C
		INT m_useVariableDeltaTime;			// 0x24
	}; // 0x28


};

#endif
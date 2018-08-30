#ifndef _TIMER_H
#define _TIMER_H

namespace fb
{

class Timer
	{

		unsigned __int64 m_count;                     // this+0x0
		unsigned __int64 m_counts;                     // this+0x8
		double m_deltaTime;                     // this+0x10
		double m_time;                     // this+0x18
		double m_invFrequency;                     // this+0x20

	}; // fb::Timer

	class Timer2
	{

		enum Flags
		{

			 Running,                     // constant 0x1
			 Paused                     // constant 0x2

		}; // Flags

		unsigned __int64 m_startTime;                     // this+0x0
		unsigned __int64 m_ticks;                     // this+0x8
		unsigned int m_flags;                     // this+0x10

	}; // fb::Timer2

	class TimeDemoBase
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void update(float);	// V: 0x4
					

	}; // fb::TimeDemoBase
};

#endif
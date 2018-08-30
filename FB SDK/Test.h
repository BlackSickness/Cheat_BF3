#ifndef _Test_H
#define _Test_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class Test
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		TestDetails m_details;                     // this+0x4
		Test * next;                     // this+0x14
		bool m_timeConstraintExempt;                     // this+0x18
	}; // fb::Test

};

#endif
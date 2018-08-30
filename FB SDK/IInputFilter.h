#ifndef _IInputFilter_H
#define _IInputFilter_H
#include "Frostbite_Classes.h"
namespace fb
{
	class IInputFilter
	{
	public:
		//LPVOID vftable;		// 0x00
		virtual void filterPlayerInput(EntryInputState &);	// V: 0x0
	
	}; // 0x04

};

#endif
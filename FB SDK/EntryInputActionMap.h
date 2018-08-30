#ifndef _EntryInputActionMap_H
#define _EntryInputActionMap_H
#include "Frostbite_Classes.h"
#include "InputActionMap.h"
namespace fb
{
	class EntryInputActionMap
		: public InputActionMap				// 0x00
	{
	public:
		LPVOID vftable;						// 0x10
		InputActionMapSlot m_slot;			// 0x14
	}; // 0x18

};

#endif
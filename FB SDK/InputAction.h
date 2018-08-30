#ifndef _InputAction_H
#define _InputAction_H
#include "Frostbite_Classes.h"
namespace fb
{
	class InputAction
	{
	public:
		DataContainer* m_data;					// 0x00 InputActionData
		InputConceptIdentifiers m_concept;		// 0x04
	}; // 0x08

};

#endif
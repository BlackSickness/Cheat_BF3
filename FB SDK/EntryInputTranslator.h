#ifndef _EntryInputTranslator_H
#define _EntryInputTranslator_H
#include "Frostbite_Classes.h"
#include "Input.h"
namespace fb
{
	class EntryInputTranslator
		: public Input							// 0x00
	{
	public:
		EntryInputActionMap* m_inputActionMap;	// 0x08
		InputActionMappingsData* m_mappingData;	// 0x0C
	}; // 0x10

};

#endif
#ifndef _InputActionMappingsData_H
#define _InputActionMappingsData_H
#include "Frostbite_Classes.h"
#include "DataContainer.h"
namespace fb
{
	class InputActionMappingsData
		: public DataContainer				// 0x00
	{
	public:
		RefArray<DataContainer> m_mappings;	// 0x08
	}; // 0x0C

};

#endif
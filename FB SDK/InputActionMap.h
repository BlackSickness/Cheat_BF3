#ifndef _InputActionMap_H
#define _InputActionMap_H
#include "Frostbite_Classes.h"
namespace fb
{
	class InputActionMap
	{
	public:
		eastl::vector<InputActions> m_actions;			// 0x00
	}; // 0x10

};

#endif
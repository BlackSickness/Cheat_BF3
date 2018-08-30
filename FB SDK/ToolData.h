#ifndef _ToolData_H
#define _ToolData_H
#include "Frostbite_Classes.h"
#include "DataContainer.h"
namespace fb
{
	class ToolData
		: public DataContainer		// 0x00
	{
	public:
		INT m_isAlwaysActive;		// 0x08
	}; // 0x0C

};

#endif
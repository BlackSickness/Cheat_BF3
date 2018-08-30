#ifndef _DATACONTAINER_H
#define _DATACONTAINER_H

#include "Frostbite_classes.h"

namespace fb
{

	class DataContainer
		: public ITypedObject		// 0x00
	{
	public:
		WORD m_refCnt;				// 0x04
		WORD m_flags;				// 0x06
	}; // 0x08
};

#endif
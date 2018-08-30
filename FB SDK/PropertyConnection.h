#ifndef _PropertyConnection_H
#define _PropertyConnection_H

#include "Frostbite_Classes.h"

namespace fb
{

	class PropertyConnection
	{
	public:
		DataContainer* m_source;		// 0x00
		DataContainer* m_target;		// 0x04
		INT m_sourceFieldId;			// 0x08
		INT m_targetFieldId;			// 0x0C
	}; // 0x10

	class LinkConnection
		: public PropertyConnection		// 0x00
	{
	}; // 0x10
};

#endif
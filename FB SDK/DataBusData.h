#ifndef _DataBusData_H
#define _DataBusData_H

#include "Frostbite_Classes.h"

namespace fb
{

	class DataBusData
		: public Asset										// 0x00
	{
	public:
		Array<PropertyConnection> m_propertyConnections;	// 0x0C
		Array<LinkConnection> m_linkConnections;			// 0x10
	}; // 0x14


};

#endif
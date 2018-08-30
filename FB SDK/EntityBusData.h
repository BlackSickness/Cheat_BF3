#ifndef _EntityBusData_H
#define _EntityBusData_H

#include "DataBusData.h"

namespace fb
{

	class EntityBusData
		: public DataBusData						// 0x00
	{
	public:
		Array<EventConnection> m_eventConnections;	// 0x14
		DataContainer* m_descriptor;				// 0x18
		BYTE m_needNetworkid;						// 0x1C
		BYTE m_interfaceHasConnections;				// 0x1D
		BYTE m_hasNetworkedEvents;					// 0x1E
		PAD(0x1);									// 0x1F
	}; // 0x20
};

#endif
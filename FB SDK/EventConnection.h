#ifndef _EventConnection_H
#define _EventConnection_H

namespace fb
{
	class EventConnection
	{
	public:
		DataContainer* m_source;		// 0x00
		DataContainer* m_target;		// 0x04
		INT m_sourceEvent;				// 0x08
		INT m_targetEvent;				// 0x0C
		INT m_targetType;				// 0x10
	}; // 0x14 0x08

};

#endif
#ifndef _EntityEvent_H
#define _EntityEvent_H

namespace fb
{
	class EntityEvent :public ITypedObject // Inherited class at offset 0x0
	{
		int eventId;                     // this+0x4
		const void * sender;                     // this+0x8
		virtual void * __vecDelDtor(unsigned int);	// V: 0x10

	}; // fb::EntityEvent

};

#endif
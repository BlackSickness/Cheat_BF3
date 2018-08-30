#ifndef _ITypedObjectWithRefCount_H
#define _ITypedObjectWithRefCount_H
#include "Frostbite_Classes.h"
#include "ITypedObject.h"
namespace fb
{
		class ITypedObjectWithRefCount
		: public ITypedObject			// 0x00
	{
	public:
		INT m_refCount;					// 0x04
	}; // 0x08

};

#endif
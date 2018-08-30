#ifndef _IResourceObject_H
#define _IResourceObject_H
#include "ITypedObject.h"
namespace fb
{
	class IResourceObject :public ITypedObject // Inherited class at offset 0x0
	{
		virtual int addRef();	// V: 0x4
		virtual int release();	// V: 0x8
				
	}; // fb::IResourceObject

};

#endif

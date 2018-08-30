#ifndef _TntObject_H
#define _TntObject_H
#include "IResourceObject.h"
namespace fb
{
	template <class T>
	class TntObject
		: public T			// 0x00
	{
	public:
		UINT m_refCnt;		// sizeof(T) + 0x00
	}; // sizeof(T) + 0x04

};

#endif
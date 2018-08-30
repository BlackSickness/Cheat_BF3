#ifndef _RefCountBase_H
#define _RefCountBase_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class RefCountBase // Inherited class at offset 0x0
	{
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		LPVOID vtable;
		int m_refCount;                     // 0x4
				

	}; // fb::RefCountBase

};

#endif
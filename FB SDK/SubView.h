#ifndef _SubView_H
#define _SubView_H
#include "Frostbite_Classes.h"
#include "ITypedObject.h"
namespace fb
{
	class SubView
		: public ITypedObject			// 0x00
	{
	public:
		DataContainer* m_data;			// 0x04 SubViewData
	}; // 0x08

};

#endif
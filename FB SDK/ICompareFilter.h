#ifndef _ICompareFilter_H
#define _ICompareFilter_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/TypeInfo.h"
#include "FB SDK/FieldInfo.h"
namespace fb
{
	
	class ICompareFilter
	{

		virtual bool filterField(TypeInfo *, FieldInfo::FieldInfoData *);	// V: 0x0
			
	}; // fb::ICompareFilter

};

#endif
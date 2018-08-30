#ifndef _CompareParams_H
#define _CompareParams_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class CompareParams
	{
	public:
		bool deepCompare;                     // 0x0
		bool asMember;                     // 0x1
		ICompareFilter * compareFilter;                     // 0x4

	}; // CompareParams

};

#endif
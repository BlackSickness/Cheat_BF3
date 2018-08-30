#ifndef _MemberInfoFlags_H
#define _MemberInfoFlags_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class MemberInfoFlags
	{
	public:
		unsigned short flagBits;                     // 0x0
		enum 
		{

			 kMemberTypeMask,                     // constant 0x3
			 kTypeCategoryShift,                     // constant 0x2
			 kTypeCategoryMask,                     // constant 0x3
			 kTypeCodeShift,                     // constant 0x4
			 kTypeCodeMask,                     // constant 0x1F
			 kMetadata,                     // constant 0x800
			 kHomogeneous,                     // constant 0x1000
			 kAlwaysPersist,                     // constant 0x2000
			 kExposed,                     // constant 0x2000
			 kLayoutImmutable,                     // constant 0x4000
			 kBlittable                     // constant 0xFFFF8000

		}; // <unnamed-tag>

	}; // fb::MemberInfoFlags
};

#endif
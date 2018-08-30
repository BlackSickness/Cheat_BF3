#ifndef _MemberInfo_H
#define _MemberInfo_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class MemberInfo // Inherited class at offset 0x0
		:public Noncopyable 
	{
	public:
		class MemberInfoData
		{
			public:
			char * name;                     // 0x0
			MemberInfoFlags flags;                     // 0x4

		}; // MemberInfoData

		/*const void*/MemberInfoData * m_MinfoData;                     // 0x0				
	}; // fb::MemberInfo

};

#endif
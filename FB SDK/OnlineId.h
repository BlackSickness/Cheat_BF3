#ifndef _OnlineId_H
#define _OnlineId_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class OnlineId
	{
	public:
		ULONGLONG m_nativeData;		// 0x00
		CHAR m_szId[0x11];			// 0x08
		PAD(0x7);					// 0x19
	}; // 0x20
};

#endif
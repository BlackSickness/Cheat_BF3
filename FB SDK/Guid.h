#ifndef _Guid_H
#define _Guid_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class Guid
	{

		unsigned int data1;                       // 0x0
		unsigned short data2;                     // 0x4
		unsigned short data3;                     // 0x6
		unsigned char data4[0x8] ;                // 0x8

	}; // fb::Guid

};

#endif
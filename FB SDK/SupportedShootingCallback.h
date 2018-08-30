#ifndef _SupportedShootingCallback_H
#define _SupportedShootingCallback_H
#include "Frostbite_Classes.h"
namespace fb
{
	class SupportedShootingCallback
	{
	public:
		//LPVOID vftable;			// 0x00
		virtual bool isSupported();	// V: 0x0
		virtual bool isAboutToBeSupported();	// V: 0x4
	}; // 0x04

};

#endif
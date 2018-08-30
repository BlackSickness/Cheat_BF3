#ifndef _SystemSettings_H
#define _SystemSettings_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class SystemSettings
		:public DataContainer // Inherited class at offset 0x0
	{
		String m_name;                     // 0x10
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::SystemSettings

};

#endif
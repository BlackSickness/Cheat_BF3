#ifndef _ModuleInfo_H
#define _ModuleInfo_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ModuleInfo
	{
	public:

		char * m_moduleName;                     // this+0x0
		ModuleInfo * m_nextModule;                     // this+0x4
		TestList * m_testList;                     // this+0x8

	}; // fb::ModuleInfox08

};

#endif
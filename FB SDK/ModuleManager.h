#ifndef _ModuleManager_H
#define _ModuleManager_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ModuleManager
	{
	public:
		static fb::ModuleInfo* findModule(char* moduleName)
		{ 
			typedef fb::ModuleInfo*(__cdecl* findModule_t)(char*);

			findModule_t m_findModule = (findModule_t)MODULEMANAGER;//0x4521B0;

			return m_findModule(moduleName);
		}

	};

};

#endif
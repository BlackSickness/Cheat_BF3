#ifndef _FieldAliasEntry_H
#define _FieldAliasEntry_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class FieldAliasEntry
	{

		class eastl::vector<char const *> aliases;                     // 0x0
		bool initialized;                     // 0x10
	
	}; // fb::FieldAliasEntry

};

#endif
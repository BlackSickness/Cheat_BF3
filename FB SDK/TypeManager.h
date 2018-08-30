#ifndef _TypeManager__H
#define _TypeManager__H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class TypeManager
	{
	public:
		static fb::TypeInfo* findType(char* typeName, fb::ModuleInfo* module)
		{
			typedef fb::TypeInfo* (_cdecl* findType_t)(char*,fb::ModuleInfo*);
				
			findType_t m_findType = (findType_t)TYPEMANAGER;//0x4625E0;

			return m_findType(typeName,module);
		}
	};

};

#endif
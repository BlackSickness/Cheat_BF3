#ifndef _ObjectVariation_H
#define _ObjectVariation_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class ObjectVariation
		:public Asset
	{
		
		unsigned int m_nameHash;                     // 0x30
		/*class fb::RefArray<fb::BlueprintVariation>*/void* m_blueprintVariations;                     // 0x34
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::ObjectVariation

};

#endif
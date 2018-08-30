#ifndef _PrefabBlueprint_H
#define _PrefabBlueprint_H
#include "Blueprint.h"
namespace fb
{
	class PrefabBlueprint
		: public Blueprint						// 0x00
	{
		RefArray<GameObjectData> m_objects;		// 0x20
	}; // 0x24

};

#endif
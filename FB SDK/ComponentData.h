#ifndef _ComponentData_H
#define _ComponentData_H
#include "Frostbite_Classes.h"
#include "GameObjectData.h"

namespace fb
{
	class ComponentData
		: public GameObjectData	,					// 0x00
		network::IClientNetworkable 
	{
		LinearTransform m_transform;				// 0x10
		RefArray<GameObjectData> m_components;		// 0x50
		INT m_excluded;								// 0x54
	}; // 0x58
};

#endif
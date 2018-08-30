#ifndef _GameEntityData_H
#define _GameEntityData_H
#include "SpatialEntityData.h"
namespace fb
{
	class GameEntityData
		: public SpatialEntityData				// 0x00
	{
	public:
		String m_name;//	RefArray<GameObjectData> m_components;	// 0x50
		BYTE m_enabled;							// 0x54
		BYTE m_runtimeComponentCount;			// 0x55
		PAD(0xA);								// 0x56

		//unsigned char m_runtimeComponentCount;               // 0x75	
		//class fb::Array<fb::WeaponStateData> m_weaponStates; // 0x80
		//enum fb::WeaponClassEnum m_weaponClass;              // 0x84
	
	}; // 0x60

};

#endif
#ifndef _GameObjectData_H
#define _GameObjectData_H
#include "GameDataContainer.h"
namespace fb
{
		class GameObjectData
		: public GameDataContainer				// 0x00
	{
	public:
		WORD m_indexInBlueprint;				// 0x08
		BYTE m_isEventConnectionTarget;			// 0x0A
		BYTE m_isPropertyConnectionTarget;		// 0x0B
		//String m_name;  
	}; // 0x0C

};

#endif
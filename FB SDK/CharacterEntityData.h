#ifndef _CharacterEntityData_H
#define _CharacterEntityData_H
#include "Frostbite_Classes.h"
#include "ControllableEntityData.h"
namespace fb
{
	class CharacterEntityData
		: public ControllableEntityData			// 0x00
	{
	public:
		PlayerSpawnType m_playerSpawnType;		// 0x80
		PersonViewMode m_defaultViewMode;		// 0x84
		PAD(8);		// 0x88
	};

};

#endif
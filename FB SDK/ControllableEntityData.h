#ifndef _ControllableEntityData_H
#define _ControllableEntityData_H
#include "Frostbite_Classes.h"
#include "GamePhysicsEntityData.h"
namespace fb
{
		class ControllableEntityData
		: public GamePhysicsEntityData			// 0x00
	{
	public:
		PAD(0x8);								// 0x64
		INT m_defaultTeam;						// 0x6C
		FLOAT m_lowHealthThreshold;				// 0x70
		PAD(0x4);								// 0x74
		DataContainer* m_materialPair;			// 0x78
		PAD(0x4);								// 0x7C
	}; // 0x80
};

#endif
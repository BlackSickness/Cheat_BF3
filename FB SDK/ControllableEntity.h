#ifndef _ControllableEntity_H
#define _ControllableEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
		class ControllableEntity
	{
	public:
		virtual float maxHealth();			// V: 0x0
		MaterialContainerPair* m_material;	// 0x04
		INT m_teamId;						// 0x08
		INT m_defaultTeamId;				// 0x0C
	}; // 0x10

};

#endif
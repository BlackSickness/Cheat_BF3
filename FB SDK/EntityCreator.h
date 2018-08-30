#ifndef _EntityCreator_H
#define _EntityCreator_H
#include "Frostbite_Classes.h"
namespace fb
{
	class EntityCreator
	{
	public:
		enum RayCastTest
        {
            RCTDetailed = 0,
            RCTCollision
        };
		LPVOID vftable;						// 0x00
		EntityCreator* m_previousCreator;	// 0x04
		EntityCreator* m_nextCreator;		// 0x08
		Realm m_realm;						// 0x0C
		INT m_linked;						// 0x10
	}; // 0x14

};

#endif
#ifndef _TeamInfo_H
#define _TeamInfo_H
#include "Frostbite_Classes.h"
namespace fb
{
	class TeamInfo
	{
	public:
		TeamEntityData* m_teams[17];			// 0x00
		UINT m_teamCount;						// 0x44
	};

};

#endif
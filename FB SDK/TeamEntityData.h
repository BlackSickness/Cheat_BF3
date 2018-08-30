#ifndef _TeamEntityData_H
#define _TeamEntityData_H
#include "GameEntityData.h"
namespace fb
{
	class TeamEntityData
		: public GameEntityData			// 0x00
	{
	public:
		DataContainer* m_team;			// 0x60
		INT m_id;						// 0x64
	}; // 0x68

};

#endif
#ifndef _ClientGameEntity_H
#define _ClientGameEntity_H
#include "Frostbite_Classes.h"
#include "GameEntity.h"
namespace fb
{
		class ClientGameEntity
		: public GameEntity		// 0x00
	{
	public:
		bool visulUpdate(float deltatime)
		{
			typedef bool (__thiscall* R_visualUpdate)(ClientGameEntity *pThis,float deltatime);
			R_visualUpdate m_visualUpdate=(R_visualUpdate)VISUALUPDATE;//0x01100610;
			
			return m_visualUpdate(this,deltatime);
		}
	}; // 0x20

};

#endif
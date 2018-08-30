#ifndef _SCORE_H
#define _SCORE_H

//#include "../Frostbite_classes.h"

namespace fb
{
	class PlayerScoreManager
	{
	public:
		PAD(0x40);
		ClientPlayerScoreManager* m_clientPlayerScoreManager;

		static PlayerScoreManager* Singleton(void)
		{
			return *(PlayerScoreManager**)PLAYERSCOREMANAGER;
		}
	};

	class ClientPlayerScoreManager
	{
	public:
		eastl::list<fb::ClientPlayerScore *,eastl_arena_allocator> m_playerScores;   

		ClientPlayerScore* getScoreByPlayer(ClientPlayer* pPlayer)
		{
			typedef ClientPlayerScore* (__thiscall* tgetScoreByPlayer)(ClientPlayerScoreManager*, ClientPlayer*);
			tgetScoreByPlayer m_getScoreByPlayer=(tgetScoreByPlayer)GET_CLIENTPLAYER_SCORE;
			return m_getScoreByPlayer(this,pPlayer);
		}
	};

	class PlayerScore
	{
	public:
		// new kozmos uc post
		char unknown[12];
		__int32	m_rank;						// 0x0
		__int32 m_kills;		// 0x4
		__int32	m_deaths;		// 0x8
		__int32	m_score;					// 0xC
		__int32	m_globalScoreOrginal;		// 0x10
		__int32	m_globalScoreUpdated;		// 0x14
		__int32	m_veteran;					// 0x18
		float	m_time;					// 0x1C
	};//SIZE=0x20

	class ClientPlayerScore
	{
	public:
		PAD(0x012C);
		PlayerScore m_score; //0x012C
	};


};

#endif
#ifndef _ClientGameContext_H
#define _ClientGameContext_H

#include "FB SDK/GameContext.h"

namespace fb
{
	class ClientGameContext
		: public GameContext							// 0x00
	{
	public:
		ClientPlayerManager* m_clientPlayerManager;		// 0x30
		online::OnlineManager * m_onlineManager;        // 0x34
        ClientGameView* m_gameView;                     // 0x38
        void* m_interpolationManager;					// 0x3C
        ClientPlayerScoreManager* m_clientPlayerScoreManager; // 0x40
        Client* m_client;                               // 0x44
	public:
		static ClientGameContext* Singleton()
		{
			DWORD CLIENTGAMECONTEXT=0x02380B58;
			return *(ClientGameContext**)(CLIENTGAMECONTEXT);
		}
	}; // 0x34

};

#endif
#ifndef _PlayerManager_H
#define _PlayerManager_H

//#include "../Frostbite_classes.h"

namespace fb
{


	class PlayerManager
	{
	public:
	// LPVOID vftable;						// 0x00
		//new
		virtual VOID Function0();                                // V:00
		virtual /*const */eastl::vector<Player*> getPlayers();       // V:04
		virtual /*const */eastl::vector<Player*> getSpectators();    // V:08
		PlayerData* m_playerData;			// 0x04
		DWORD m_maxPlayerCount;				// 0x08
		DWORD m_playerCountBitCount;		// 0x0C
		DWORD m_playerIdBitCount;			// 0x10
	}; // 0x14

	class ClientPlayerManager
		: public PlayerManager,								// 0x00
		public network::ClientGhost,						// 0x14
		public network::Interpolator<LPVOID>,				// 0x54
		public network::IClientNetworkable					// 0x94
	{
	public:
		eastl::vector<ClientPlayer*> m_players;				// 0x9C
		eastl::vector<ClientPlayer*> m_spectators;			// 0xAC
		ClientPlayer* m_localPlayer;						// 0xBC
		ClientPlayer** m_idToPlayerMap;						// 0xC0
		PAD(0x4);											// 0xC4
		ClientPlayerManagerPlayer* m_networkablePlayers;	// 0xC8

		__forceinline ClientPlayer* getLocalPlayer()
        {
                return *(ClientPlayer**) ((DWORD)this + 0xBC);
        }
 
        __forceinline ClientPlayer** getIdToPlayerMap()
        {
                return *(ClientPlayer***) ((DWORD)this + 0xC0);
        }
 
        __forceinline ClientPlayer* getPlayerFromId(unsigned int id)
        {
                fb::ClientPlayer *result = 0;
 
                if (id < this->m_maxPlayerCount)
                        result = this->getIdToPlayerMap()[id];
 
                return result;
        }
	};

	class ClientPlayerManagerPlayer
		: public network::IClientNetworkableGroupMember		// 0x00
	{
	public:
		ClientPlayerManager* m_manager;						// 0x08
		DWORD m_id;											// 0x0C
	}; // 0x10
};

#endif
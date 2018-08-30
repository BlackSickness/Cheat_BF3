#ifndef _ONLINE_H
#define _ONLINE_H

namespace fb
{

	
	namespace online
	{


		class ClientConnection
			:public network::EngineConnectionPeer, // Inherited class at offset 0x0
			network::IControlObjectClient ,// Inherited class at offset 0x18D0
			network::IChatMessageHandler, // Inherited class at offset 0x18D4
			fb::MessageListener // Inherited class at offset 0x18D8
		{

			/*class fb::online::ClientPeer * */void*m_parent;                     // this+0x18E0
		/*	class fb::online::ClientStateMachine * */void*m_stateMachine;                     // this+0x18E4
		/*	class fb::network::StreamManagerMoveClient */void*m_moveManager;                     // this+0x18E8
		/*	class fb::network::StreamManagerFile */void*m_fileManager;                     // this+0x1954
		/*	class fb::network::StreamManagerDamage */void*m_damageManager;                     // this+0x19EC
		/*	class fb::network::StreamManagerDestructionClient */void*m_destructionManager;                     // this+0x1A90
		/*	class fb::network::StreamManagerChat * */void*m_streamManagerChat;                     // this+0x1B04
		/*	class fb::network::InterpolationManager * */void*m_interpolationManager;                     // this+0x1B08
		/*	class fb::network::IGhostConnection * */void*m_ghostConnectionCallback;                     // this+0x1B0C
		/*	class fb::network::IDestructionHandler * */void*m_terrainDestructionHandler;                     // this+0x1B10
		/*	class fb::network::IDestructionHandler * */void*m_partDestructionHandler;                     // this+0x1B14
		/*	class fb::online::ClientDamageStream **/void* m_damageStream;                     // this+0x1B18
			float m_totalTime;                     // this+0x1B1C
			float m_timeUntilFpsCalculation;                     // this+0x1B20
			unsigned int m_incomingRate;                     // this+0x1B24
			float m_loadingTimeout;                     // this+0x1B28
			float m_loadedTimeout;                     // this+0x1B2C
			float m_ingameTimeout;                     // this+0x1B30
			float m_fps;                     // this+0x1B34
			int m_ignoredFrameDiff;                     // this+0x1B38
			const int m_constantFrameDiff;                     // this+0x1B3C
		/*	class fb::online::ClientToServerInfoCl * */void*m_clientToServerInfo;                     // this+0x1B40
		/*	class eastl::list<fb::online::ConnectionSubscriber *,fb::eastl_arena_allocator>*/void* m_subscribers;                     // this+0x1B44
		/*	class fb::network::ICompress * */void*m_compression;                     // this+0x1B50
			class eastl::basic_string<char,fb::eastl_arena_allocator> m_dataLogName;                     // this+0x1B54
			bool m_isPredictionEnable;                     // this+0x1B64
			class fb::ClientControllableEntity * m_predictedControllable;                     // this+0x1B68
			unsigned int m_predictedEntryId;                     // this+0x1B6C
			class TimerIcon
			{

				class fb::Timer m_timer;                     // this+0x0
				int m_iconId;                     // this+0x28
		
			}; // TimerIcon

			class eastl::list<fb::online::ClientConnection::TimerIcon,fb::eastl_arena_allocator> m_timerIcons;                     // this+0x1B70
			bool m_ignoreLinkLevel;                     // this+0x1B7C
			class DeletedGhost
			{

				float serverTimeStamp;                     // this+0x0
				class fb::network::ClientGhost * ghost;                     // this+0x4

			}; // DeletedGhost

			class eastl::basic_string<char,fb::eastl_arena_allocator> m_lastNetClassName;                     // this+0x1B80
			class eastl::vector<fb::online::ClientConnection::DeletedGhost,fb::eastl_arena_allocator> m_deletedGhosts;                     // this+0x1B90
/*			class eastl::list<eastl::pair<unsigned int,fb::WeakPtr<fb::ClientProxyProjectileEntity> >,fb::eastl_arena_allocator>*/void* m_proxyProjectileQueue;                     // this+0x1BA0
			enum Input
			{

				 TeamRadio                     // constant 0x0

			}; // Input

			class fb::InputActionMapping * m_inputMap;                     // this+0x1BAC
			/*class fb::EntryInputState */void*m_initialState;                     // this+0x1BB0
			class ClientControlObjectState
				//:public fb::ControlObjectState // Inherited class at offset 0x0
			{
				class ControlObjectState // Inherited class at offset 0x0
					:public network::IControlObjectState
				{
					unsigned char  m_originalBuffer[0x1000];                     // this+0x4
					unsigned char * m_buffer;                     // this+0x1004
					unsigned int * m_startWritePosition;                     // this+0x1008
					/*class fb::BitStream*/void* m_stream;                     // this+0x1010
						
				}; // fb::ControlObjectState
				
				class fb::online::ClientConnection * m_owner;                     // this+0x1120
				
			}; // ClientControlObjectState

			class fb::online::ClientConnection::ClientControlObjectState * m_baseLineStates;                     // this+0x1EB0
			unsigned int m_baseLineStateCount;                     // this+0x1EB4
			class fb::BitArray m_usedBaseLineStates;                     // this+0x1EB8
			bool m_useDeltaCompression;                     // this+0x1ECC
			bool m_useVoice;                     // this+0x1ECD
			bool m_singlePlayer;                     // this+0x1ECE
			class AuthenticationState
			{

						class eastl::basic_string<char,fb::eastl_arena_allocator> challenge;                     // this+0x0
				bool isRanked;                     // this+0x10
				
			}; // AuthenticationState

			struct fb::online::ClientConnection::AuthenticationState m_authenticationState;                     // this+0x1ED0
/*			struct fb::IClientAuthCallbacks * */void* m_authCallbacks;                     // this+0x1EE4
			class fb::StatsTracker * m_latencyStats;                     // this+0x1EE8
			class fb::StatsTracker * m_bytesSentStats;                     // this+0x1EEC
			class fb::StatsTracker * m_bytesReceivedStats;                     // this+0x1EF0
			class fb::StatsTracker * m_packetsSentStats;                     // this+0x1EF4
			class fb::StatsTracker * m_packetsReceivedStats;                     // this+0x1EF8
			class fb::StatsTracker * m_pingsSentStats;                     // this+0x1EFC
			class fb::StatsTracker * m_pingsReceivedStats;                     // this+0x1F00
			class fb::StatsTracker * m_forceNotifyPacketsSentStats;                     // this+0x1F04
			class fb::StatsTracker * m_forceNotifyPacketsReceivedStats;                     // this+0x1F08
			class fb::StatsTracker * m_packetsAcceptedStats;                     // this+0x1F0C
			class fb::StatsTracker * m_packetsLostStats;                     // this+0x1F10
			class fb::StatsTracker * m_packetsNotifiedLostStats;                     // this+0x1F14
			struct fb::network::Connection::Stats m_stats;                     // this+0x1F18
			/*class fb::online::ClientConnectionDebugRender */void*  m_connectionDebugRender;                     // this+0x1F50
			/*class fb::ClientNetworkableMessageContext */void*  m_messageContext;                     // this+0x2424
			class eastl::vector<unsigned char,fb::eastl_arena_allocator> m_challenge;                     // this+0x2430
			//virtual void * __vecDelDtor(unsigned int);	// V: 0x38

		}; // fb::online::ClientConnection

		class OnHostInfoCallback
		{

			virtual void onHostInfo(const class fb::ISocketAddress &, unsigned int, const char *);	// V: 0x0
			
		}; // fb::online::OnHostInfoCallback

		class ClientPeer
			:public  fb::network::EnginePeer // Inherited class at offset 0x0
		{
			Client * m_game;                     // this+0x2FE0
			/*class fb::ScopedPtr<fb::ClientChatManager> */void* m_chatManager;                     // this+0x2FE4
			/*class fb::network::GhostManager * */void*m_ghostManager;                     // this+0x2FE8
			/*class fb::network::InterpolationManager * */void*m_interpolationManager;                     // this+0x2FEC
			online::ClientConnection * m_localConnection;                     // this+0x2FF0
			online::OnHostInfoCallback * m_hostInfoCallback;                     // this+0x2FF4
			bool m_connected;                     // this+0x2FF8
		//	virtual void * __vecDelDtor(unsigned int);	// V: 0x18

		}; // fb::online::ClientPeer

		

		class ConnectionSubscriber // Inherited class at offset 0x0
		{		
		}; // fb::online::ConnectionSubscriber

		class OnlineManager
			:public  ConnectionSubscriber // Inherited class at offset 0x0
		{


			enum State
			{

				 Disconnected,                     // constant 0x0
				 PendingConnection,                     // constant 0x1
				 Connecting,                     // constant 0x2
				 Connected,                     // constant 0x3
				 Disconnecting                     // constant 0x4

			}; // State

			enum SocketMode
			{

				 Local,                     // constant 0x0
				 Network,                     // constant 0x1
				 Coop,                     // constant 0x2
				 Lan                     // constant 0x3

			}; // SocketMode

			enum CryptoOption
			{

				 NoCrypto,                     // constant 0x0
				 Blowfish                     // constant 0x1

			}; // CryptoOption

			Client * m_game;                     // this+0x4
			bool m_isSinglePlayer;                     // this+0x8
			bool m_localHost;                     // this+0x9
			bool m_isInprocClient;                     // this+0xA
			network::ICrypto * m_crypto;                     // this+0xC
			ISocketManager * m_socketManager;                     // this+0x10
			NetworkManager * m_networkManager;                     // this+0x14
			class fb::online::ClientPeer * m_peer;                     // this+0x18
			class fb::online::ClientConnection * m_connection;                     // this+0x1C
		/*	const unsigned int m_titleId;                     // this+0x20
			const unsigned int m_protocolVersion;                     // this+0x24
			unsigned int m_defaultOutgoingRate;                     // this+0x28
			unsigned int m_defaultIncomingRate;                     // this+0x2C
			float m_defaultOutgoingFrequency;                     // this+0x30
			float m_defaultIncomingFrequency;                     // this+0x34
			float m_loadingTimeout;                     // this+0x38
			float m_loadedTimeout;                     // this+0x3C
			float m_ingameTimeout;                     // this+0x40
			unsigned int m_port;                     // this+0x44
			bool m_useInternetSimulation;                     // this+0x48
			enum fb::online::OnlineManager::SocketMode m_socketMode;                     // this+0x4C
			class fb::ISocketAddress m_pendingConnectAddress;                     // this+0x50
			class eastl::basic_string<char,fb::eastl_arena_allocator> m_pendingConnectPreferedLevel;                     // this+0x94
			class eastl::basic_string<char,fb::eastl_arena_allocator> m_currentDataLogName;                     // this+0xA4
			enum fb::online::OnlineManager::State m_state;                     // this+0xB4
			enum fb::SecureReason m_reason;                     // this+0xB8
	*/
		
		};
	
	};



};

#endif
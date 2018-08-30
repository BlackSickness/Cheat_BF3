#ifndef _NETWORK_H
#define _NETWORK_H

#include "Frostbite_Classes.h"
#include "ISocket.h"



namespace fb
{


	namespace network
	{
		class Ghost
		{
		public:
			LPVOID vftable;				// 0x00
			PAD(0x3C);		// 0x04
		}; // 0x40

		class ClientGhost
			: public Ghost		// 0x00
		{
		}; // 0x40

		class IControlObjectState 
		{

			virtual void destroy();	// V: 0x0
								
		}; // fb::network::IControlObjectState

		class ServerGhost
			: public Ghost		// 0x00
		{
			enum 
			{

				GhostMaskInit,                    // constant 0x1
				GhostMaskDelete,                     // constant 0x2
				ReservedStates                    // constant 0x2
			};
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			virtual const char * getNetName();	// V: 0x4
			virtual const char * getNetClassName();	// V: 0x8
			virtual unsigned char getNetClassId();	// V: 0xC
			virtual Entity entityCast();	// V: 0x10
			void* m_ghostInfos;//class eastl::hash_set<fb::network::GhostInfo *,eastl::hash<fb::network::GhostInfo *>,eastl::equal_to<fb::network::GhostInfo *>,fb::eastl_arena_allocator,0> m_ghostInfos;                     // 0x4
			void* m_networkables;//class eastl::vector<fb::network::INetworkable *,fb::eastl_arena_allocator> m_networkables;                     // 0x24
			unsigned int m_networkableDescriptorSum;                     // 0x34
			unsigned int m_supportsDeltaCompression;                     // 0x38, len(0x1)
			unsigned int m_allowChangeMask;                     // 0x39, len(0x1)
			unsigned int m_baselineChanged;                     // 0x3A, len(0x1)
			unsigned int m_ownedByGhostFactory;                     // 0x3B, len(0x1)
			unsigned int m_isStaticGhost;                     // 0x3C, len(0x1)
			unsigned int m_iteratingInfos;                     // 0x3D, len(0x1)
		
		}; // 0x40


		class ICryptoKey
		{
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			virtual unsigned int writeKeyToHost(unsigned char *, unsigned int);	// V: 0x4
			virtual unsigned int encryptKeyToClient(unsigned char *, unsigned int);	// V: 0x8
			virtual bool encryptData(unsigned char *, unsigned int, unsigned int *);	// V: 0xC
			virtual bool decryptData(unsigned char *, unsigned int, unsigned int *);	// V: 0x10
			virtual class eastl::basic_string<char,fb::eastl_arena_allocator> toString();	// V: 0x14
			virtual unsigned int getPadding(unsigned int);	// V: 0x18
						

		}; // fb::network::ICryptoKey

		class ICrypto
		{
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			virtual unsigned char getCryptoId();	// V: 0x4
			virtual class fb::network::ICryptoKey * createHostKey();	// V: 0x8
			virtual class fb::network::ICryptoKey * createClientKey();	// V: 0xC
			virtual class fb::network::ICryptoKey * decryptKeyFromHost(unsigned char *, unsigned int);	// V: 0x10
			virtual class fb::network::ICryptoKey * readKeyFromClient(unsigned char *, unsigned int, unsigned int *);	// V: 0x14

		}; // fb::network::ICrypto

		class IChallengeMemento
		{
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		}; // fb::network::IChallengeMemento



		class SecureConnection
		{

				enum State
			{

				 Idle,                     // constant 0x0
				 SendChallenge,                     // constant 0x1
				 SendCustomChallenge,                     // constant 0x2
				 SendConnect,                     // constant 0x3
				 SendAccept,                     // constant 0x4
				 SendAcceptConfirmation,                     // constant 0x5
				 SendConnectionConfirmed,                     // constant 0x6
				 Connected,                     // constant 0x7
				 ChallengeSentNoReply,                     // constant 0x8
				 ChallengeFailed,                     // constant 0x9
				 AcceptFailed,                     // constant 0xA
				 ConnectionFailed,                     // constant 0xB
				 Disconnected,                     // constant 0xC
				 DisconnectedByRemote,                     // constant 0xD
				 Rejected,                     // constant 0xE
				 Error                     // constant 0xF

			}; // State

			class fb::ISocketAddress m_address;                     // this+0x0
			/*class fb::network::Secure::IConnectionInfo **/void*  m_info;                     // this+0x44
			enum fb::SecureReason m_rejectReason;                     // this+0x48
			class eastl::basic_string<char> m_reasonText;                     // this+0x4C
			class fb::network::ICryptoKey * m_localKey;                     // this+0x5C
			class fb::network::ICryptoKey * m_remoteKey;                     // this+0x60
			enum fb::network::SecureConnection::State m_lastNotificationState;                     // this+0x64
			enum fb::network::SecureConnection::State m_state;                     // this+0x68
			/*class fb::network::Secure **/void* m_secure;                     // this+0x6C
			float m_waitTime;                     // this+0x70
			unsigned int m_receivedChallengeNumber;                     // this+0x74
			/*class fb::network::Secure **/void*  m_parent;                     // this+0x78
			unsigned char * m_connectionInfo;                     // this+0x7C
			unsigned int m_connectionInfoSize;                     // this+0x80
			unsigned char m_lastReceivedPacket;                     // this+0x84
			unsigned char m_outgoingPacketNumber;                     // this+0x85
			unsigned int m_acNonce;                     // this+0x88
			unsigned int m_clientNonce;                     // this+0x8C
			unsigned int m_passwordSalt;                     // this+0x90
			bool m_hostConnection;                     // this+0x94
			unsigned short m_localChannel;                     // this+0x96
			unsigned short m_peerChannel;                     // this+0x98
			unsigned int m_tries;                     // this+0x9C
			unsigned int m_connectionTries;                     // this+0xA0
			bool m_isEncrypted;                     // this+0xA4
			/*class fb::network::Secure::IConnectionHandler **/void*  m_handler;                     // this+0xA8
			/*class fb::network::ICompress * */void* m_compress;                     // this+0xAC
			/*class fb::network::PacketNotification **/void*  m_packetNotificator;                     // this+0xB0
			/*class fb::ScopedPtr<fb::network::IChallengeMemento> */void* m_challengeMemento;                     // this+0xB4
		
		}; // fb::network::SecureConnection

		class Secure
		{
		public:

			enum CustomChallengeState
			{

				 ChallengeBusy,                     // constant 0x0
				 ChallengeAccept,// constant 0x1
				 ChallengeReject,                     // constant 0x2
				 ChallengeRejectFull,                     // constant 0x3
				 ChallengeRejectPassword,                     // constant 0x4

			}; // CustomChallengeState

			class IConnectionInfo
			{

					virtual void pad();//~IConnectionInfo();	// V: 0x0
					virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // IConnectionInfo

			class IConnectionHandler
			{

				virtual void onConnecting();	// V: 0x0
				virtual void onConnected();	// V: 0x4
				virtual void onTimeSyncEstablished();	// V: 0x8
				virtual void onAdjustTime(double);	// V: 0xC
				virtual void onDisconnected();	// V: 0x10
				virtual void onDisconnectedByRemote(enum fb::SecureReason, const char *);	// V: 0x14
				virtual void onTimedOut();	// V: 0x18
				virtual void onAcceptFailed();	// V: 0x1C
				virtual void onConnectFailed();	// V: 0x20
				virtual void onNoReply();	// V: 0x24
				virtual void onRejected(enum fb::SecureReason);	// V: 0x28
				virtual void onError(unsigned int);	// V: 0x2C
				virtual enum fb::network::Secure::CustomChallengeState onCustomChallenge(const unsigned char *, unsigned int);	// V: 0x30
				virtual bool getCustomChallengeResponse(unsigned char * &, unsigned int &);	// V: 0x34
				
			}; // IConnectionHandler

			class IHandler
			{

				virtual void onConnectionRequest(const class fb::ISocketAddress &, unsigned int, const unsigned char *, unsigned int);	// V: 0x0
				virtual void onRemoveConnection(const class fb::ISocketAddress &, enum fb::SecureReason, const char *);	// V: 0x4
				virtual void onHostInfo(const class fb::ISocketAddress &, unsigned int, const char *);	// V: 0x8
				virtual enum fb::network::Secure::CustomChallengeState onCustomChallengeRequest();	// V: 0xC
				virtual bool getCustomChallenge(unsigned char * &, unsigned int &);	// V: 0x10
				virtual enum fb::network::Secure::CustomChallengeState onCustomChallengeResponse(const class fb::ISocketAddress &, const unsigned char *, unsigned int, struct fb::network::IChallengeMemento * *);	// V: 0x14
				
			}; // IHandler

			enum State
			{

				 Unknown,                     // constant 0x0
				 ConnectProbe,                     // constant 0x1
				 Connecting,                     // constant 0x2
				 Connected,                     // constant 0x3
				 Accepting,                     // constant 0x4
				 AcceptFailed,                     // constant 0x5
				 Rejected,                     // constant 0x6
				 NoReply,                     // constant 0x7
				 ConnectionFailed,                     // constant 0x8
				 TimedOut,                     // constant 0x9
				 DisconnectedByRemote,                     // constant 0xA
				 Error                    // constant 0xB

			}; // State

			class QosStats
			{

				float minLatency;                     // this+0x0
				float maxLatency;                     // this+0x4
				float latency;                     // this+0x8
				unsigned int incomingBandwidth;                     // this+0xC
				unsigned int outgoingBandwidth;                     // this+0x10

			}; // QosStats

			enum QosStatus
			{

				 QosNotStarted,                     // constant 0x0
				 QosOk,                     // constant 0x1
				 QosSearching,                     // constant 0x2
				 QosResultsPending,                     // constant 0x3
				 QosNoReply,                     // constant 0x4
				 QosRejected,                     // constant 0x5
				 QosError                     // constant 0x6

			}; // QosStatus

			enum ReceiveStatus
			{

				 ReceiveStatusDone,                     // constant 0x0
				 ReceiveStatusContinue,                     // constant 0x1

			}; // ReceiveStatus

			class PasswordHash
			{

				 char hash[0x14];                     // this+0x0

			}; // PasswordHash

				enum Commands
			{

				 ChallengeResponseCmd,                     // constant 0x1
				 ConnectCmd,                     // constant 0x2
				 RejectCmd,                     // constant 0x3
				 AcceptCmd,                     // constant 0x4
				 AcceptConfirmationCmd,                     // constant 0x5
				 ConnectionConfirmedCmd,                     // constant 0x6
				 HostInfoRequestCmd,                     // constant 0x7
				 HostInfoCmd,                     // constant 0x8
				 BusyCmd,                     // constant 0x9
				 ChallengeCmd,                     // constant 0xD
				 DisconnectCmd,                     // constant 0xE
				 CustomChallengeCmd,                     // constant 0xF
				 CustomChallengeResponseCmd,                     // constant 0x10
				 RemoteDisconnectCmd,                     // constant 0x11
				 DataCmd                     // constant 0x14

			}; // Commands

			enum Constants
			{

				 protocolHeaderSize                    // constant 0x3

			}; // Constants

			unsigned char * m_temporaryBuffer;                     // this+0x0
			unsigned char * m_temporarySecondaryBuffer;                     // this+0x4
			int m_temporaryBufferSize;                     // this+0x8
			class eastl::map<unsigned short,fb::network::SecureConnection *,eastl::less<unsigned short>> m_connections;                     // this+0xC
			class eastl::map<fb::ISocketAddress,fb::network::SecureConnection *,eastl::less<fb::ISocketAddress>> m_pendingConnections;                     // this+0x24
			unsigned int m_currentChallengeNumber;                     // this+0x3C
			class fb::network::ICrypto * m_cryptoPlugin;                     // this+0x40
			class fb::network::SecureConnection * m_peerConnection;                     // this+0x44
			struct fb::ISocket * m_socket;                     // this+0x48
			unsigned int m_titleId;                     // this+0x4C
			unsigned int m_titleProtocolVersionId;                     // this+0x50
			float m_time;                     // this+0x54
			float m_deltaTime;                     // this+0x58
			bool m_isListening;                     // this+0x5C
			bool m_isHosting;                     // this+0x5D
			float m_challengeNumberTime;                     // this+0x60
			float m_challengeNumberTimeout;                     // this+0x64
			class fb::BitArray m_channelNumbers;                     // this+0x68
			class fb::network::Secure::IHandler * m_mainHandler;                     // this+0x7C
			bool m_isBusy;                     // this+0x80
			class eastl::basic_string<char,fb::eastl_arena_allocator> m_password;                     // this+0x84
			class Event
			{

				enum Type
				{

					 EventHostInfo,                     // constant 0x0
					 EventConnectionRequest,                     // constant 0x1
					 EventSendCustomChallenge,                     // constant 0x2
					 EventCustomChallenge,                     // constant 0x3
					 EventCustomChallengeResponse                    // constant 0x4

				}; // Type

				virtual enum fb::network::Secure::Event::Type getType();	// V: 0x4
				class fb::ISocketAddress addr;                     // this+0x4
										virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // Event

			class ConnectionRequestEvent
				:public  fb::network::Secure::Event // Inherited class at offset 0x0
			{

				unsigned int clientNonce;                     // this+0x48
				unsigned char * info;                     // this+0x4C
				unsigned int infoSize;                     // this+0x50
				virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // ConnectionRequestEvent

			class HostInfoEvent
				:public  fb::network::Secure::Event // Inherited class at offset 0x0
			{

				unsigned int hostInfoId;                     // this+0x48
				class eastl::basic_string<char,fb::eastl_arena_allocator> hostInfo;                     // this+0x4C

			}; // HostInfoEvent

			class SendCustomChallengeEvent
					:public  fb::network::Secure::Event // Inherited class at offset 0x0
			{

				

										virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // SendCustomChallengeEvent

			class CustomChallengeEvent
					:public  fb::network::Secure::Event // Inherited class at offset 0x0
			{


						unsigned int passwordSalt;                     // this+0x48
				unsigned char * challenge;                     // this+0x4C
				unsigned int challengeSize;                     // this+0x50
								virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // CustomChallengeEvent

			class CustomChallengeResponseEvent
					:public  fb::network::Secure::Event // Inherited class at offset 0x0
			{

				

						struct fb::network::Secure::PasswordHash passwordHash;                     // this+0x48
				unsigned char * challengeResponse;                     // this+0x5C
				unsigned int challengeResponseSize;                     // this+0x60
								virtual void * __vecDelDtor(unsigned int);	// V: 0x0

			}; // CustomChallengeResponseEvent

			enum fb::network::Secure::Commands m_pendingCommand;                     // this+0x94
			class eastl::list<fb::network::Secure::Event *,fb::eastl_arena_allocator> m_events;                     // this+0x98
			class eastl::map<unsigned int,eastl::basic_string<char,fb::eastl_arena_allocator>,eastl::less<unsigned int>,fb::eastl_arena_allocator> m_hostInfos;                     // this+0xA4
			class fb::OutBitStream m_outStream;                     // this+0xBC
			class fb::InBitStream m_inStream;                     // this+0xD8
			class ChallengeState
			{

				unsigned int state;                     // this+0x0
				float timeout;                     // this+0x4
				struct fb::network::IChallengeMemento * memento;                     // this+0x8

			}; // ChallengeState

			class PasswordState
			{

				float timeout;                     // this+0x0
				unsigned int salt;                     // this+0x4

			}; // PasswordState

			class eastl::fixed_map<fb::ISocketAddress,fb::network::Secure::ChallengeState,64,1,eastl::less<fb::ISocketAddress>,fb::eastl_arena_allocator> m_challengeStateMap;                     // this+0xF4
			class eastl::fixed_map<fb::ISocketAddress,fb::network::Secure::PasswordState,64,1,eastl::less<fb::ISocketAddress>,fb::eastl_arena_allocator> m_passwordStateMap;                     // this+0x187C
		
		}; // fb::network::Secure

		class Packet
		{
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			unsigned int m_maxOctets;                     // this+0x4
			unsigned char * m_data;                     // this+0x8
			unsigned int m_voiceDataSize;                     // this+0xC
			unsigned int m_type;                     // this+0x10
			unsigned int m_lostPacketCount;                     // this+0x14
			class fb::InBitStream * m_inStream;                     // this+0x18
			class fb::OutBitStream * m_outStream;                     // this+0x1C
				

		}; // fb::network::Packet

		class PacketBuffer
		{
			unsigned int m_packetCount;                     // this+0x0
			unsigned int m_maxPacketCount;                     // this+0x4
			unsigned int m_headIndex;                     // this+0x8
			unsigned int m_tailIndex;                     // this+0xC
			unsigned int m_maxPacketOctetSize;                     // this+0x10
			class fb::network::Packet * m_packets;                     // this+0x14
			unsigned char * m_memoryPool;                     // this+0x18
	
		}; // fb::network::PacketBuffer

		enum PacketDeliveryStatus
		{

			 PacketDeliveryFailed,                     // constant 0x0
			 PacketDeliverySucceeded,                     // constant 0x1
			 PacketDeliveryDiscarded                     // constant 0x2

		}; // fb::network::PacketDeliveryStatus

		enum PacketType
		{

			 DataPacket,                     // constant 0x0
			 FakeDataPacket,                     // constant 0x1
			 PingRequest,                     // constant 0x2
			 PingResponse,                     // constant 0x3
			 PacketTypeCount                     // constant 0x4

		}; // fb::network::PacketType

		class PacketNotification
		{

			class eastl::fixed_list<enum fb::network::PacketDeliveryStatus,16,1,fb::eastl_arena_allocator> m_packetNotificationQueue;                     // this+0x4
			unsigned int m_packetNotificationBits;                     // this+0xF0
			unsigned int m_lastSequenceNumberThatPeerHasReceived;                     // this+0xF4
			unsigned int m_lastProcessedSequenceNumber;                     // this+0xF8
			unsigned int m_windowSize;                     // this+0xFC
			unsigned int m_sequenceNumberBits;                     // this+0x100
			unsigned int m_sequenceNumberMask;                     // this+0x104
			unsigned int m_sendSequenceNumber;                     // this+0x108
			unsigned int m_deferredLastReceivedByRemote;                     // this+0x10C
			unsigned int m_deferredSequenceNumber;                     // this+0x110
			unsigned int m_deferredNotificationBits;                     // this+0x114
			bool m_deferredWaiting;                     // this+0x118
			bool m_lastSentWasReliable;                     // this+0x119
			bool m_lastReadPacketHeaderWasValid;                     // this+0x11A
			unsigned int m_packetQueueStart;                     // this+0x11C
			//virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::network::PacketNotification



		class IPacketStatusNotification // Inherited class at offset 0x4
		{

			virtual void onPacketDrop(unsigned int);	// V: 0x0
			virtual void onPacketLag(float);	// V: 0x4
			virtual void onPacketSent(unsigned int);	// V: 0x8
			virtual void onPacketReceived(unsigned int);	// V: 0xC
			virtual void onRemotePacketDrop(unsigned int);	// V: 0x10
						
		}; // fb::network::IPacketStatusNotification

		class ConnectionManager
			:public Secure::IHandler // Inherited class at offset 0x0
		{
			class Stats
			{

				int octetsSentPerSecond;                     // this+0x0
				int octetsReceivedPerSecond;                     // this+0x4
				int packetsSentPerSecond;                     // this+0x8
				int packetsReceivedPerSecond;                     // this+0xC

			}; // Stats

			/*class fb::Thread * */void*m_thread;                     // this+0x4
			/*struct eastl::rbtree_iterator<eastl::pair<unsigned short const ,fb::network::Connection *>,eastl::pair<unsigned short const ,fb::network::Connection *> *,eastl::pair<unsigned short const ,fb::network::Connection *> &> */ DWORD m_connectionIterator;                     // this+0x8
			/*class eastl::map<unsigned short,fb::network::Connection *,eastl::less<unsigned short>,fb::eastl_arena_allocator> */DWORD m_connections;                     // this+0xC
			class eastl::set<fb::ISocketAddress,eastl::less<fb::ISocketAddress>,fb::eastl_arena_allocator> m_banList;                     // this+0x24
			class fb::network::Secure * m_secure;                     // this+0x3C
			bool m_isPaused;                     // this+0x40
			unsigned int m_maxNumberOfConnections;                     // this+0x44
			float m_time;                     // this+0x48
			double m_timeAdjust;                     // this+0x50
			double m_gameTime;                     // this+0x58
			float m_connectionTimeout;                     // this+0x60
			class fb::Timer m_timer;                     // this+0x68
			class fb::network::Secure::IHandler * m_mainHandler;                     // this+0x90
			bool m_isInitialized;                     // this+0x94
		
		}; // fb::network::ConnectionManager

	

		class Connection
			:public Secure::IConnectionHandler // Inherited class at offset 0x0
		{
		public:
			class Stats
			{

				double lifeTime;                     // this+0x0
				int bytesSent;                     // this+0x8
				int bytesReceived;                     // this+0xC
				int packetsSent;                     // this+0x10
				int packetsReceived;                     // this+0x14
				int pingsSent;                     // this+0x18
				int pingsReceived;                     // this+0x1C
				int forceNotifyPacketsReceived;                     // this+0x20
				int forceNotifyPacketsSent;                     // this+0x24
				int packetsAccepted;                     // this+0x28
				int packetsLost;                     // this+0x2C
				int packetsNotifiedLost;                     // this+0x30

			}; // Stats

			class PacketInfo
			{

				/*enum fb::network::PacketType*/DWORD m_packetType;                     // this+0x0

			}; // PacketInfo

			class fb::network::PacketBuffer * m_receiveQueue;                     // this+0x4
			class fb::network::PacketBuffer * m_sendBuffer;                     // this+0x8
			class fb::network::Packet * m_currentWritePacket;                     // this+0xC
			class eastl::fixed_list<fb::network::Connection::PacketInfo,128,1,fb::eastl_arena_allocator> m_packetInfos;                     // this+0x10
			class fb::network::Secure * m_secure;                     // this+0x63C
			class fb::network::PacketNotification * m_packetNotificator;                     // this+0x640
			struct fb::network::Connection::Stats m_stats;                     // this+0x648
			struct fb::network::Connection::Stats m_publicStats;                     // this+0x680
			int m_timesWindowFull;                     // this+0x6B8
			double m_resetTime;                     // this+0x6C0
			double m_lastReceivedTime;                     // this+0x6C8
			double m_lastAcceptedTime;                     // this+0x6D0
			double m_lastPingSentTime;                     // this+0x6D8
			double m_lastPacketSentTime;                     // this+0x6E0
			double m_lastFakeDataSentTime;                     // this+0x6E8
			double m_lastStatTime;                     // this+0x6F0
			double m_lastResendTime;                     // this+0x6F8
			double m_latency;                     // this+0x700
			double m_minimumLatency;                     // this+0x708
			double m_mediumLatency;                     // this+0x710
			double m_maximumLatency;                     // this+0x718
			double m_latencyPercentage20;                     // this+0x720
			double m_latencyPercentage50;                     // this+0x728
			double m_latencyPercentage80;                     // this+0x730
			double m_timeOutTime;                     // this+0x738
			int m_numberOfPings;                     // this+0x740
			unsigned short m_connectionId;                     // this+0x744
			unsigned short m_peerConnectionId;                     // this+0x746
			double m_keepAliveInterval;                     // this+0x748
			double m_timeSyncInterval;                     // this+0x750
			double m_responseInterval;                     // this+0x758
			double m_statInterval;                     // this+0x760
			double m_tinyEventResendInterval;                     // this+0x768
			bool m_isTimeSyncEnabled;                     // this+0x770
			bool m_isTimeSyncEstablished;                     // this+0x771
			bool m_wasTimeSyncEstablishedBefore;                     // this+0x772
			bool m_isPaused;                     // this+0x773
			double m_timeSyncTolerance;                     // this+0x778
			double m_timeAdjust;                     // this+0x780
			float m_timeSyncTries;                     // this+0x788
			bool m_latencyTableIsFilled;                     // this+0x78C
			double * m_latencyTable;                     // this+0x790
			unsigned int m_latencyTableIndex;                     // this+0x794
			bool m_statsEnabled;                     // this+0x798
			enum fb::network::PacketType m_lastPacketType;                     // this+0x79C
			bool m_iAmServer;                     // this+0x7A0
			bool m_isConnected;                     // this+0x7A1
			bool m_isAlive;                     // this+0x7A2
			bool m_hasTimedOut;                     // this+0x7A3
			bool m_error;                     // this+0x7A4
			class fb::network::Secure::IConnectionHandler * m_handler;                     // this+0x7A8
			class fb::network::ConnectionManager * m_manager;                     // this+0x7AC
			class eastl::list<unsigned char,fb::eastl_arena_allocator> m_tinyEvents;                     // this+0x7B0
			class eastl::list<unsigned char,fb::eastl_arena_allocator> m_receivedTinyEvents;                     // this+0x7BC
			unsigned int m_pendingTinyEvent;                     // this+0x7C8
			unsigned int m_pendingTinyEventSequenceNumber;                     // this+0x7CC
			unsigned int m_lastProcessedTinyEventSequenceNumber;                     // this+0x7D0
			double m_connectionTimeout;                     // this+0x7D8
			unsigned int m_maxPacketDataSize;                     // this+0x7E0
			bool m_hasReportedError;                     // this+0x7E4
		
		}; // fb::network::Connection



		class EngineConnection 
			:public Secure::IConnectionHandler, // Inherited class at offset 0x0
					IPacketStatusNotification // Inherited class at offset 0x4
		{

		

			bool m_isConnected;                     // this+0x8
			class fb::network::Connection * m_connection;                     // this+0xC
			/*class fb::network::StreamControl*/void* m_streamControl;                     // this+0x10
			/*class fb::network::StreamManagerMessage*/void* m_messageManager;                     // this+0x380
			/*class fb::network::StreamManagerEngine*/void* m_streamManager;                     // this+0x1778
			class fb::ISocketAddress m_connectAddress;                     // this+0x17A0
			enum fb::SecureReason m_reason;                     // this+0x17E4
			class eastl::basic_string<char,fb::eastl_arena_allocator> m_reasonText;                     // this+0x17E8
			//virtual void * __vecDelDtor(unsigned int);	// V: 0x38

		}; // fb::network::EngineConnection


		
		class IScopeFetcher // 
		{

			enum SendStatus
			{

				 DoNotSend,                     // constant 0x0
				 SendAll,                    // constant 0x1
				 SendNone                     // constant 0x2

			}; // SendStatus

			virtual enum fb::network::IScopeFetcher::SendStatus getSendStatus();	// V: 0x0
			virtual void readCompressionVector(/*class fb::IBitStreamRead */void*);	// V: 0x4
			virtual void writeCompressionVector(/*class fb::IBitStreamWrite*/void *);	// V: 0x8
				
		}; // fb::network::IScopeFetcher

		class IGhostCreator // Inherited class at offset 0x1804
		{

			virtual class fb::network::ClientGhost * onCreateGhost(/*class fb::IBitStreamRead*/void *, unsigned int);	// V: 0x0
			virtual void onDeleteGhost(class fb::network::ClientGhost *);	// V: 0x4
			virtual void onForceDeleteGhost(class fb::network::ClientGhost *);	// V: 0x8
			virtual void onSynchronizeGame();	// V: 0xC
			virtual void onWriteGhostCreateHeader(class fb::network::ServerGhost *, /*class fb::IBitStreamWrite*/void *);	// V: 0x10
				
		}; // fb::network::IGhostCreator

		class EngineConnectionPeer
			:public  EngineConnection, // Inherited class at offset 0x0
			IScopeFetcher, // Inherited class at offset 0x1800
			IGhostCreator // Inherited class at offset 0x1804
		{

			/*class fb::network::StreamManagerFrame*/void * m_frameManager;                     // this+0x1808
			/*class fb::network::StreamManagerGhost*/void * * m_ghostManager;                     // this+0x18B8
			/*class fb::network::InterpolationManager **/void * m_interpolationManager;                     // this+0x18BC
			bool m_isSyncEstablished;                     // this+0x18C0
			//virtual void * __vecDelDtor(unsigned int);	// V: 0x38

		}; // fb::network::EngineConnectionPeer

		class IChatMessageHandler // Inherited class at offset 0x18D4
		{

			virtual void handleChatMessage(/*const class fb::network::ChatMessage &*/ void*);	// V: 0x4
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // fb::network::IChatMessageHandler


		class EnginePeer 
			:public fb::network::Secure::IHandler // Inherited class at offset 0x0
		{

			

			virtual enum fb::SecureReason onCreateConnection(const class fb::ISocketAddress &, class fb::network::EngineConnectionPeer * *,/* class fb::network::ICompress*/void  * *, const unsigned char *, unsigned int);	// V: 0x20
			virtual void onHostInfo(const class fb::ISocketAddress &, unsigned int, const char *);	// V: 0x0
			class fb::network::ConnectionManager m_connectionMgr;                     // this+0x8
			class fb::network::Secure m_secure;                     // this+0xA0
			struct fb::ISocket * m_socket;                     // this+0x2FA0
			class fb::ISocketManager * m_socketMgr;                     // this+0x2FA4
			struct eastl::rbtree_iterator<eastl::pair<unsigned short const ,fb::network::EngineConnectionPeer *>,eastl::pair<unsigned short const ,fb::network::EngineConnectionPeer *> const *,eastl::pair<unsigned short const ,fb::network::EngineConnectionPeer *> const &> m_connectionIterator;                     // this+0x2FA8
			class eastl::map<unsigned short,fb::network::EngineConnectionPeer *,eastl::less<unsigned short>,fb::eastl_arena_allocator> m_connections;                     // this+0x2FAC
			unsigned int m_titleId;                     // this+0x2FC4
			unsigned int m_titleProtocolId;                     // this+0x2FC8
			unsigned char * m_temporaryBuffer;                     // this+0x2FCC
			int m_temporaryBufferSize;                     // this+0x2FD0
			class fb::ISocketDebug * m_socketDebug;                     // this+0x2FD4
			bool m_connectionDebug;                     // this+0x2FD8
			bool m_useFrameManager;                     // this+0x2FD9
			unsigned int m_sendPulseCounter;                     // this+0x2FDC
			//	virtual void * __vecDelDtor(unsigned int);	// V: 0x18

		}; // fb::network::EnginePeer

		class ServerGhostFilter
		{

			virtual bool onGhost(class ServerGhost *, /*class fb::network::EngineConnectionPeer **/ void*);	// V: 0x0
		
		}; // fb::network::ServerGhostFilter

		class IControlObject // Inherited class at offset 0x0
		{

			enum ExecuteFlags
			{

				 FirstInFrame,                    // constant 0x1
				 LastInFrame                    // constant 0x2

			}; // ExecuteFlags

			virtual void executeMove(/*class fb::network::IMoveObject*/void *, enum fb::network::IControlObject::ExecuteFlags);	// V: 0x0
			virtual void deleteMove(/*class fb::network::IMoveObject*/void  *);	// V: 0x4
			virtual void PAD3();//class fb::network::IMoveObject * cloneMove(const class fb::network::IMoveObject *);	// V: 0x8
						
		}; // fb::network::IControlObject

		class IControlObjectClient // Inherited class at offset 0x18D0
			:public IControlObject // Inherited class at offset 0x0
		{

			

			virtual void setPrediction(bool);	// V: 0xC
			virtual bool readControlObjectState(/*class fb::IBitStreamRead **/void *, /*class fb::network::IMoveObject **/void *, /*const class fb::network::IControlObjectState **/void *, /*class fb::network::IControlObjectState **/void * *);	// V: 0x10
			virtual void readTimeSyncInfo(/*class fb::IBitStreamRead **/void *,/* class fb::network::IMoveObject **/void *);	// V: 0x14
				
		}; // fb::network::IControlObjectClient

		class IServerNetworkable
		{

			class INetworkable // Inherited class at offset 0x0
			{
				virtual void * __vecDelDtor(unsigned int);	// V: 0x0
				unsigned int m_networkableDescriptorSize;                     // 0x4
			}; // fb::network::INetworkable
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0
			virtual unsigned int ghostWrite(unsigned int, /*class fb::IBitStreamWrite **/ void*, /*const struct fb::network::ServerNetworkableWriteParameters &*/ void*);	// V: 0x10
			ServerGhost * m_parentGhost;                     // 0x8
			unsigned int m_maskInfo;                     // 0xC
		}; // fb::network::IServerNetworkable




		class InterpolationObject
		{
		public:
			PAD(0x14);
		}; // 0x14

		template <typename T>
		class Interpolator
			: public InterpolationObject		// 0x00
		{
		public:
			eastl::deque<T,64> m_states;			// 0x14
		}; // 0x40

		class INetworkable
		{
		public:
			LPVOID vftable;						// 0x00
			DWORD m_networkableDescriptorSize;	// 0x04
		}; // 0x08

		class IClientNetworkable
			: public INetworkable		// 0x00
		{
		}; // 0x08

		class IClientNetworkableGroupMember
			: public IClientNetworkable		// 0x00
		{
		}; // 0x08

		class ClientNetworkableGroup
			: public IClientNetworkable
		{
		public:
			eastl::fixed_vector<IClientNetworkableGroupMember*, 32, 1> m_networkables;	// 0x00
		}; // 0x98
	};


};

#endif
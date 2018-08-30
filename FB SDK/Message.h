class Message;
class UINetworkPlayerKillsTextMessage;

namespace fb
{
	class Message
		: public fb::ITypedObject
	{
	public:
		const int category;                     // this+0x4
		const int type;                     // this+0x8
		char pad[4];                        // this+0xC
		double m_dispatchTime;                     // this+0x10
		const class fb::Message * m_next;                     // this+0x18
		int m_postedAtProcessMessageCounter;                     // this+0x1C
		UINetworkPlayerKillsTextMessage* m_ownedByMessageManager;                     // this+0x20
	}; // fb::Message

	class UINetworkPlayerKillsTextMessage
		: public Message
	{
	public:
		//fb::Message size 0x20
		char pad[0x18]; //0x24
		//char /*struct fb::UINetworkTextInfo*/ m_textInfo[8]; //0x38
		unsigned int a;
		unsigned int b;
		unsigned int m_killedId; //0x40
		unsigned int m_victimId; //0x44
		bool m_isHeadshot;         //0x48
		DWORD m_weaponType;         //0x4C
		//weaponUnlock
		//vehicleData
	};

	enum ChatChannelType
	{
		CctSayAll,                     // constant 0x0
		CctTeam,                     // constant 0x1
		CctSquad,                     // constant 0x2
		CctSquadLeader,                     // constant 0x3
		CctAdmin,                     // constant 0x4
		CctSize,                     // constant 0x5
	}; // fb::ChatChannelType
}
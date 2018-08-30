#ifndef _ISOCKET_H
#define _ISOCKET_H


namespace fb
{

	class ISocket
	{
		enum Result
		{

			 Success,                     // constant 0x0
			 CatalogNotResponding,                     // constant 0x1
			 EntryNotExisting                     // constant 0x2

		}; // Result

		class PacketInfo
		{

			int minSize;                     // this+0x0
			int maxSize;                     // this+0x4
			int recommendedSize;                     // this+0x8
			int overheadWhenAligned;                     // this+0xC
			int alignment;                     // this+0x10

		}; // PacketInfo
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual bool send(const unsigned char *, int, int);	// V: 0x4
		virtual int receiveFrom(unsigned char *, int, int *);	// V: 0x8
		virtual bool setBroadcast(unsigned short);	// V: 0xC
		virtual void setPeerAddress(const class fb::ISocketAddress &);	// V: 0x10
		virtual class fb::ISocketAddress getPeerAddress();	// V: 0x14
		virtual bool getPacketInfo(struct fb::ISocket::PacketInfo *);	// V: 0x18
		virtual bool getBlockingMode();	// V: 0x1C
		virtual bool setBlockingMode(bool);	// V: 0x20
		virtual void receivePulse();	// V: 0x24
		virtual void pulse(float);	// V: 0x28
		virtual void sendPulse();	// V: 0x2C
		virtual int nativeSocket();	// V: 0x30
		virtual int port();	// V: 0x34
		virtual const class fb::ISocketAddress * getAddress();	// V: 0x38
		virtual void addReceiveCallback(/*function*/void  *);	// V: 0x3C
		

	}; // fb::ISocket



	class ISocketAddress
	{
		unsigned char address[0x40];                     // this+0x0
		unsigned char lengthUsed;                     // this+0x40

	}; // fb::ISocketAddress

	class ISocketManager
	{

		virtual void destroy();	// V: 0x0
		virtual struct fb::ISocket * connect(const char *, bool, bool, bool);	// V: 0x4
		virtual struct fb::ISocket * listen(const char *, bool, bool, bool);	// V: 0x8
		virtual struct fb::ISocket * createSocket(bool, bool);	// V: 0xC
		virtual void sleep(float);	// V: 0x10
		virtual void * __vecDelDtor(unsigned int);	// V: 0x14

	}; // fb::ISocketManager

	class ISocketDebug
	{

		virtual void setSpikeFrequency(float);	// V: 0x0
		virtual void setSpikeDuration(float, float);	// V: 0x4
		virtual void setCorruptRatio(float);	// V: 0x8
		virtual void setSpoofingRatio(float);	// V: 0xC
		virtual void setLatencyRange(float, float);	// V: 0x10
		virtual void setIncomingLatencyRange(float, float);	// V: 0x14
		virtual void setDuplicateRatio(float);	// V: 0x18
		virtual void setDropRatio(float);	// V: 0x1C
		virtual void setSizeRatio(float);	// V: 0x20
		virtual void setCatalogRatio(float);	// V: 0x24
		virtual void setReorderRatio(float);	// V: 0x28
		virtual void init(struct fb::ISocket *);	// V: 0x2C
		virtual float getLatency();	// V: 0x30
		
	}; // fb::ISocketDebug

	class ISocketManagerFactory
	{

		virtual ISocketManager * createSocketManager();	// V: 0x0
		
	}; // fb::ISocketManagerFactory

};

#endif
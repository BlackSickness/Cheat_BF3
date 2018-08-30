#ifndef _ClientCallbacks_H
#define _ClientCallbacks_H

namespace fb
{
		class ClientCallbacks
	{

		virtual unsigned int spawnServer(/*struct fb::ServerSpawnInfo &*/void);	// V: 0x0
		virtual void restartLevel(const unsigned char *, unsigned int);	// V: 0x4
		virtual void exitServer();	// V: 0x8
		virtual void onClientLevelLinked();	// V: 0xC
		virtual void setServerPauseState(bool);	// V: 0x10
		virtual bool isPaused();	// V: 0x14
		virtual void joinServerJob(bool);	// V: 0x18
		virtual void setClientTitle(const char *);	// V: 0x1C
		virtual void setClientStatus(const class eastl::list<eastl::pair<eastl::basic_string<char,fb::eastl_arena_allocator>,eastl::basic_string<char,fb::eastl_arena_allocator> >,fb::eastl_arena_allocator> &);	// V: 0x20
		virtual bool isServerStarted();	// V: 0x24
		virtual bool isServerLoaded();	// V: 0x28
		virtual bool canServerExit();	// V: 0x2C
		virtual void clientHasEnteredLoadingScreen();	// V: 0x30
		virtual void clientHasLoadedLevel();	// V: 0x34
		virtual void createWindow();	// V: 0x38
		virtual void onNetworkInitialized(/*const struct fb::ClientInitNetworkInfo &*/void);	// V: 0x3C
		
	}; // fb::ClientCallbacks

};

#endif
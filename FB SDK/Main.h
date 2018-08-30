#ifndef _Main_H
#define _Main_H

namespace fb
{
		class Main
	{
	public:
		PAD(0xA0);
		bool m_isDedicatedServer;
		bool m_isDedicatedServerData;
		bool m_isPaused;
		BYTE _Main_unused_1;
		void* m_fileLogHandler;
		void* m_debugRendererLogHandler;
		void* m_demoControl;
		void* m_server;
		Client* m_client; // this+0xD4
		//new try to access Screenshotmodule
		PAD(0x7C);
		unsigned int m_buildId;                     // this+0x154
		const char * m_buildTime;                     // this+0x158
		PAD(0xC);
		JuiceScreenshotModule* m_juiceScreenshotModule; // 0x168
		bool m_createdOk;  
		bool m_playerHasEntered;
		DWORD m_quitHelper;                    
		DWORD m_settingsManagerService;                     
	public:
		static Main* Singleton()
		{
			return *(Main**)0x22EA120;
		}
	};

};

#endif
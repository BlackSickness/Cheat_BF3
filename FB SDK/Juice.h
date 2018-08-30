#ifndef _JUICE_H
#define _JUICE_H

//////////////////////////////////////////////////////////////////////////
// Juice classes
// 
// 
//////////////////////////////////////////////////////////////////////////

class Juice
{
public:
	class ScreenshotPlugin
	{
		class Plugin // Inherited class at offset 0x0
		{

			virtual char * GetVersion();	// V: 0x8
			virtual char * GetName();	// V: 0xC
			void *mCore;                     // 0x4
			void *mCom;                     // 0x8
			unsigned int mConsolePluginId;                     // 0xC
			unsigned int mServerPluginId;                     // 0x10
			bool mServerEnabled;                     // 0x14
			bool mHasRequestedServerEnable;                     // 0x15
			virtual void * __vecDelDtor(unsigned int);	// V: 0x0

		}; // Juice::Plugin

		virtual char * GetName();	// V: 0x0
		virtual char * GetVersion();	// V: 0x0
		virtual void DoScreenshot();	// V: 0x40
		virtual void Dummy ();//OnMessage(int, int, class Juice::JuiceMsgReader *);	// V: 0x0
		virtual void OnServerEnable();	// V: 0x0
		DWORD mScreenshotFormat;                     // 0x18
		bool mIsAsync;                     // 0x1C
		bool mIsTakingScreenshot;                     // 0x1D
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // Juice::ScreenshotPlugin
};




#endif
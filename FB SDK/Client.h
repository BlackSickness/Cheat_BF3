#ifndef _Client_H
#define _Client_H


#include "FB SDK/ClientCallbacks.h"

namespace fb
{
	class Client
	{
	public:
		PAD(12);//char _Client_skipped_0[12]; //0x0000  
		ClientGameContext* m_gameContext; //0x000C  
		void* m_gameSettings; //0x0010  
		ClientSettings* m_clientSettings; //0x0014  
		PAD(4);//char _Client_skipped_1[4]; //0x0018  
//class fb::ScopedPtr<fb::ClientPlayerManager> m_playerManager;                    
		ClientPlayerManager* m_playerManager; //0x001C  
		void* m_destructionManager; //0x0020 fb::WeakPtr<fb::ClientDestructionManager>
//  ScopedPtr<fb::ClientGameView> m_gameView;
		WeakPtr<ClientGameView>* m_gameView; //0x0024 fb::ClientGameView 
		void* m_fileSystem; //0x0028 fb::VirtualFileSystem 
		GameTime* m_gameTime; //0x002C  
		BorderInputNode* m_inputNode; //0x0030 //Shown as fb::InputNode but holds fb::BorderInputNode
		Rumble* m_rumble; //0x0034 fb::Rumble 
//class fb::SmartRef<fb::ClientLevel> m_level; 
		ClientLevel* m_level; //0x0038  
		IUISystem * m_ui; //0x003C fb::IUISystem 
		UISystemType m_uiSystem; //0x0040 enum fb::UISystemType 
		ISocketManagerFactory * m_socketManagerFactory; //0x0044 fb::ISocketManagerFactory 
		void* m_interpolationManager; //0x0048 fb::network::InterpolationManager 
		WeakPtr<Timer2> m_inputTimer; //0x004C fb::Timer2 
		WeakPtr<TimeDemoBase> m_timeDemo; //0x0050 fb::TimeDemoBase 
		PAD(252);//char _Client_skipped_2[252]; //0x0054  
		ClientState m_state; //0x0150 enum fb::ClientState 


		PAD(132);//char _Client_skipped_3[132]; //0x0154  
		ClientGameType m_gameType; //0x01D8  
		byte m_quit; //0x01DC  
		byte m_wantsToQuit; //0x01DD  
		byte m_pauseOnStartup; //0x01DE  
		byte m_keepResources; //0x01DF  
		byte m_shouldConnectToServer; //0x01E0  
		byte m_startServerLocal; //0x01E1  
		byte m_startServerInCoop; //0x01E2  
		byte m_consoleClient; //0x01E3  
		byte m_threadedWinProc; //0x01E4  
		byte m_inSimulationUpdate; //0x01E5  
		byte m_mayPerformStateChange; //0x01E6  
		BYTE _unused; //0x01E7  
		ClientCallbacks * m_clientCallbacks;  //0x01E8 
		PAD(4);//char _Client_skipped_4[4]; //0x01EC  
		//char _Client_skipped_4[8]; //0x01EC  

	//class fb::ClientCallbacks * m_clientCallbacks;                     // this+0x124
	//class eastl::queue<fb::LevelSetup,eastl::deque<fb::LevelSetup,fb::eastl_arena_allocator,8> > m_pendingLoads;                     // this+0x128
	//class fb::ScopedPtr<fb::Profiler> m_profiler;                     // this+0x154
	//class fb::online::OnlineManager * m_onlineManager; 


		float m_visualFrameUpdateTime; //0x01F0  


		PAD(12);//char _Client_skipped_5[12]; //0x01F4  


		BYTE m_readyForAutoSpawn; //0x0200  
		BYTE m_debugAutoSpawnWaitForControllable; //0x0201  
		PAD(2);//char _Client_unused_0[2]; //0x0202  
		__int32 m_autoSpawnFailCount; //0x0204  
		void* m_debugFramePrmiitive; //0x0208 fb::SmartRef<fb::IDebugRenderPrimitive> 
		void* m_clientNetSwitboard; //0x020C fb::ClientNetSwitchboard 
		DWORD m_pendingBundleOp; //0x0210 fb::AsyncResultHandle 
	};//Size=0x0214(532)



};

#endif
#ifndef _GameContext_H
#define _GameContext_H

namespace fb
{
	class GameContext
	{
	public:
		PAD(8);											// 0x00
		PlayerManager* m_playerManager;					// 0x08
		GameTime* m_gameTime;							// 0x0C
		//Level* m_level;								// 0x10
		fb::ClientLevel* m_level;						// 0x10
		MaterialGridManager* m_materialGridManager;		// 0x14
		DWORD m_animationManager;						// 0x18 ant::AnimationManager
		DWORD m_modelAnimationManager;					// 0x1C ModelAnimationManager
		DWORD m_blueprintBundleManager;					// 0x20 BlueprintBundleManager
		DWORD m_dlcManager;								// 0x24 DLCManager
		DWORD m_demoControl;							// 0x28 DemoControl
		INT m_realm;									// 0x2C
	}; // 0x30
};

#endif
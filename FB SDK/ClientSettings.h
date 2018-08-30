#ifndef _ClientSettings_H
#define _ClientSettings_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/SystemSettings.h"
namespace fb
{
	
	class ClientSettings
		:public SystemSettings // Inherited class at offset 0x0
	{
		float m_loadedTimeout;                     // 0x14
		unsigned int m_outgoingRate;                     // 0x18
		float m_loadingTimeout;                     // 0x1C
		float m_incomingFrequency;                     // 0x20
		unsigned int m_incomingRate;                     // 0x24
		float m_duplicationChance;                     // 0x28
		unsigned int m_team;                     // 0x2C
		float m_maxDropDuration;                     // 0x30
		float m_reorderingChance;                     // 0x34
		float m_dropSpikeChance;                     // 0x38
		float m_minDropDuration;                     // 0x3C
		float m_maxIncomingLatency;                     // 0x40
		float m_packetDrops;                     // 0x44
		float m_maxLatency;                     // 0x48
		float m_minIncomingLatency;                     // 0x4C
		float m_aimScale;                     // 0x50
		float m_pcPadDeadZone;                     // 0x54
		float m_corruptionChance;                     // 0x58
		String m_serverIp;                     // 0x5C
		float m_minLatency;                     // 0x60
		String m_screenshotFilename;                     // 0x64
		String m_screenshotSuffix;                     // 0x68
		int m_spawnPointIndex;                     // 0x6C
		String m_secondaryServerIp;                     // 0x70
		float m_ingameTimeout;                     // 0x74
		bool m_skipFastLevelLoad;                     // 0x78
		bool m_screenshotToFile;                     // 0x79
		bool m_loadMenu;                     // 0x7A
		bool m_isPresenceEnabled;                     // 0x7B
		bool m_inputEnable;                     // 0x7C
		bool m_ignoreClientFireRateMultiplier;                     // 0x7D
		bool m_invertPitch;                     // 0x7E
		bool m_occludersEnabled;                     // 0x7F
		bool m_debugMenuOnLThumb;                     // 0x80
		bool m_pauseGameOnStartUp;                     // 0x81
		bool m_scheme2FlipY;                     // 0x82
		bool m_invertYaw;                     // 0x83
		bool m_invertFreeCamera;                     // 0x84
		bool m_lipSyncEnabled;                     // 0x85
		bool m_isInternetSimulationEnabled;                     // 0x86
		bool m_onDamageSpottingEnabled;                     // 0x87
		bool m_emittersEnabled;                     // 0x88
		bool m_padRumbleEnabled;                     // 0x89
		bool m_overgrowthEnabled;                     // 0x8A
		bool m_effectsEnabled;                     // 0x8B
		bool m_terrainEnabled;                     // 0x8C
		bool m_waterPhysicsEnabled;                     // 0x8D
		bool m_vegetationEnabled;                     // 0x8E
		bool m_worldRenderEnabled;                     // 0x8F
		bool m_renderTags;                     // 0x90
		bool m_debrisClusterEnabled;                     // 0x91
		bool m_havokVisualDebugger;                     // 0x92
		bool m_havokVDBShowsEffectsWorld;                     // 0x93
		bool m_havokCaptureToFile;                     // 0x94
		bool m_useMouseAndKeyboardSystem;                     // 0x95
		bool m_useGlobalGamePadInput;                     // 0x96
		bool m_threadedLoadingEnable;                     // 0x97
		bool m_showBuildId;                     // 0x98
		bool m_extractPersistenceInformation;                     // 0x99
		bool m_enableRestTool;                     // 0x9A
		bool m_localVehicleSimulationEnabled;                     // 0x9B
		bool m_asyncClientBulletEntity;                     // 0x9C
		bool m_autoUnspawnDynamicObjects;                     // 0x9D
		bool m_vsyncEnable;                     // 0x9E
		bool m_visualFrameInterpolation;                     // 0x9F
		bool m_invertPadPcRightStick;                     // 0xA0
		bool m_scheme0FlipY;                     // 0xA1
		bool m_isSpectator;                     // 0xA2
		bool m_scheme1FlipY;                     // 0xA3
		bool m_quitGameOnServerDisconnect;                     // 0xA4
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::ClientSettings

};

#endif
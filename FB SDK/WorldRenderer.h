#ifndef _WorldRenderer_H
#define _WorldRenderer_H

//#include "../Frostbite_classes.h"

namespace fb
{
	class VegetationManager 
	{ 
	public: 
		char _0x0000[4]; // Unknown 
		float m_time; 
		float m_updateTime; 
		float m_updateGhostTime; 
		__int32 m_frameCounter; 
		__int32 m_currentLocalInfluenceId; 
		__int32 m_number_fActiveInstances; 
		__int32 m_simulationMemoryInUse; 
		char _0x0020[96]; 
		__int32 m_currentInstanceIndex; 
		char _0x0084[652]; 
		VegetationSystemSettings* m_settings;
	};

	// new stuff
	 class ClientVegetationManager
	{
	public:
	char _0x0000[4];
		float m_time; //0x0004 
		float m_updateTime; //0x0008 
		float m_updateGhostTime; //0x000C 
		int m_frameCounter; //0x0010 
		int m_currentLocalInfluenceID; //0x0014 
		int m_number_fActiveInstances; //0x0018 
		int m_symulationMemoryInUse; //0x001C 
	char _0x0020[96];
		int m_currentInstanceIndex; //0x0080 
	char _0x0084[652];
		VegetationSystemSettings* m_settings; //0x0310 
	char _0x0314[40];

	};//Size=0x033C

	class VegetationSystemSettings
	{
	public:
	char _0x0000[8];
		float m_windVariation; //0x0008 
		float m_windVariationRate; //0x000C 
		float m_windStrength; //0x0010 
		float m_jointTentionLimit; //0x0014 
		int m_forceShadowLod; //0x0018 
		int m_maxPreSimsPerJob; //0x001C 
		int m_simulationMemKbServer; //0x0020 
		float m_maxActiveDistance; //0x0024 
		int m_simulationMemKbClient; //0x0028 
		float m_timeScale; //0x002C 
		int m_jobCount; //0x0030 
		int m_jointTentionLimitIndex; //0x0034 
		bool m_simulateServerSide; //0x0038 
		bool m_localInfluenceEnable; //0x0039 
		bool m_useShadowLodOffset; //0x003A 
		bool m_destructionEnabled; //0x003B 
		bool m_enableJobs; //0x003C 
		bool m_enable; //0x003D 
		bool m_drawNodes; //0x003E 
		bool m_batchDrawEnable; //0x003F 
		bool m_drawEnable; //0x0040 
		bool m_dissolveEnable; //0x0041 
		bool m_shadowMeshEnable; //0x0042 

	};//Size=0x0043

	class EmitterManager
	{
	public:
	char _0x0000[4];
		int m_refCount; //0x0004 
	char _0x0008[124];
		int m_jobCountPerStage; //0x0084 
	char _0x0088[440];
		bool m_enable; //0x0240 
		bool m_fixedDeltaEnable; //0x0241 
	char _0x0242[2];
		float m_globalResetStartTimeInterval; //0x0244 
		float m_timeScale; //0x0248 
		float m_globalResetStartTime; //0x024C 

	};//Size=0x0250

	class DebrisSystemSettings
	{
	public:
	char _0x0000[8];
		int m_meshDrawCountLimit; //0x0008 
		float m_timeScale; //0x000C 
		float m_meshCullingDistance; //0x0010 
		int m_drawStats; //0x0014 
	char _0x0018[4];
		float m_meshStreamingPriorityMultiplier; //0x001C 
		bool m_meshRenderingEnable; //0x0020 
		bool m_enable; //0x0021 
		bool m_meshShadowEnable; //0x0022 
		bool m_meshDrawBoundingBoxes; //0x0023 
		bool m_meshViewCullingEnable; //0x0024 
		bool m_meshHavocRenderingEnable; //0x0025 
		bool m_enableJobs; //0x0026 
		bool m_meshDrawTransforms; //0x0027 

	};//Size=0x0028 




	class EnlightenComponentData
	{
		Vec3 m_skyBoxSkyColor;                     // 0x60
		Vec3 m_skyBoxBackLightColor;                     // 0x70
		Vec3 m_skyBoxGroundColor;                     // 0x80
		Vec3 m_terrainColor;                     // 0x90
		Vec3 m_skyBoxSunLightColor;                     // 0xA0
		float m_bounceScale;                     // 0xB0
		float m_cullDistance;                     // 0xB4
		float m_sunScale;                     // 0xB8
		Realm m_realm;                     // 0xBC
		float m_skyBoxBackLightRotationY;                     // 0xC0
		float m_skyBoxSunLightColorSize;                     // 0xC4
		float m_skyBoxBackLightColorSize;                     // 0xC8
		float m_skyBoxBackLightRotationX;                     // 0xCC
		bool m_skyBoxEnable;                     // 0xD0
		bool m_enable;                     // 0xD1
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::EnlightenComponentData

	class WorldRenderer
    {
    public:
        class RootView
        {
        public:
            DWORD    index;
            /*WorldDrawViewInfo*   */void* viewInfo;
        };
        void*    m_vtable;
		char _0x0004[32];
			DWORD m_viewWidth; //0x0024 
			DWORD m_viewHeight; //0x0028 
		char _0x002C[35164];
			WorldRenderSettings* m_worldRenderSettings; //0x8988 
    };

	class WorldRenderModule
    {
	public:
		/*unsigned char pad[0x18];				//0000
//		IWorldRenderer* m_worldRenderer;       // 0x18
		bool m_fmvPlaying;                     // 0x1C
		bool m_worldEnable;                     // 0x1D*/
		char _0x0000[24]; // Inheritance 
		WorldRenderer* m_worldRenderer; 
		bool m_fmvPlaying; 
		bool m_worldEnable;

	}; // fb::WorldRenderModule


	class WorldRenderSettings
{

	public:
    char _0x0000[16];
        float m_dynamicEnvmapDefaultPosition_0; //0x0010 
        float m_dynamicEnvmapDefaultPosition_1; //0x0014 
        float m_dynamicEnvmapDefaultPosition_2; //0x0018 
        float m_dynamicEnvmapDefaultPosition_3; //0x001C 
        float m_subSurfaceColor_0; //0x0020 
        float m_subSurfaceColor_1; //0x0024 
        float m_subSurfaceColor_2; //0x0028 
        float m_subSurfaceColor_3; //0x002C 
        float m_viewportScale; //0x0030 
        float m_shadowMinScreenArea; //0x0034 
        float m_shadowViewportScale; //0x0038 
        DWORD m_fxaaQuality; //0x003C 
        float m_cullScreenAreaScale; //0x0040 
        float m_planarReflectionCullFOV; //0x0044 
        DWORD m_planarReflectionWidth; //0x0048 
        float m_shadowmapSizeZScale; //0x004C 
        DWORD m_shadowmapResolution; //0x0050 
        DWORD m_shadowmapQuality; //0x0054 
    char _0x0058[8];
        float m_shadowmapSliceSchemeWeight; //0x0060 
        float m_shadowmapFirstSliceScale; //0x0064 
        float m_shadowViewDistance; //0x0068 
    char _0x006C[68];
        float m_motionBlurScale; //0x00B0 
        float m_motionBlurMax; //0x00B4 
        float m_motionBlurNoiseScale; //0x00B8 
        DWORD m_motionBlurQuality; //0x00BC 
        DWORD m_dynamicEnvmapResolution; //0x00C0 
        DWORD m_maxDecalVolumeCount; //0x00C4 
        DWORD m_motionBlurMaxSampleCount; //0x00C8 
        DWORD m_motionBlurFrameAverageCount; //0x00CC 
        float m_motionBlurMaxFrameTime; //0x00D0 
        float m_forceMotionBlurDepthCutoff; //0x00D4 
        float m_forceMotionBlurCutoffGradientScale; //0x00D8 
        DWORD m_multisampleCount; //0x00DC 
        float m_multisampleThreshold; //0x00E0 
        DWORD m_maxSpotLightShadowCount; //0x00E4 
        DWORD m_reflectionEnvmapSize; //0x00E8 
        float m_spotLightNearPlane; //0x00EC 
        float m_subSurfaceRolloff; //0x00F0 
    char _0x00F4[4];
        DWORD m_maxSpotLightCount; //0x00F8 
        DWORD m_spotLightShadowmapResolution; //0x00FC 
        DWORD m_spotLightShadowmapQuality; //0x0100 
    char _0x0104[150];
        bool m_drawFirstPersonModel; //0x019A 
    char _0x019B[6];
        bool m_enlightenGlass; //0x01A1 
        bool m_drawDebugSkyEnvmap; //0x01A2 
        bool m_debugDrawEmitters; //0x01A3 
    char _0x01A4[1];
        bool m_depthOfField; //0x01A5 
    char _0x01A6[7];
        bool m_debugDrawDepth; //0x01AD 
    char _0x01AE[1];
        bool m_lightBrightMap; //0x01AF 
    char _0x01B0[1];
        bool m_debugDrawSkyboxAndMask; //0x01B1 
    char _0x01B2[4];
        bool m_debugDrawSkyviewBoxes; //0x01B6 
        bool m_skyEnable; //0x01B7 
    char _0x01B8[6];
        bool m_sunEnabled; //0x01BE 
    char _0x01BF[7];
        bool m_fluorescentBloom; //0x01C6 
    char _0x01C7[6];
        bool m_drawFoliage; //0x01CD 
    char _0x01CE[4];
        bool m_drawLight; //0x01D2 
        bool m_unlitEnable; //0x01D3 
    char _0x01D4[1];
        bool m_spotLightEnable_0; //0x01D5 
    char _0x01D6[3];
        bool m_spotLightEnable_1; //0x01D9 
    char _0x01DA[3];
        bool m_lightShadows; //0x01DD 
    char _0x01DE[17];
        bool m_clearBuffer; //0x01EF 
    char _0x01F0[10];
        bool m_softenSmoke; //0x01FA 
    char _0x01FB[1];
        bool m_somethingLighting; //0x01FC 
        bool m_drawReflection; //0x01FD 
        bool m_fadeDecals; //0x01FE 
    char _0x01FF[5];
        bool m_debugDrawMovementOrSomething; //0x0204 
        bool m_debugChristmasAcidTrip; //0x0205 
    char _0x0206[1];
        bool m_debugMultiView; //0x0207 Has color map, fullbright, shadow, everything!
    char _0x0208[8];
        bool m_lightEnabledAgain; //0x0210 
        bool m_drawShadows; //0x0211 
    char _0x0212[3];
        bool m_drawNothingButGround; //0x0215 
    char _0x0216[10];
        bool m_debugDrawShadowBoxes; //0x0220 
    char _0x0221[2];
        bool m_moreShadows; //0x0223 
        bool DONTFUCKINGCHANGEME; //0x0224 
    char _0x0225[5];
        bool m_smokeShadows; //0x022A 
    char _0x022B[7];
        bool m_comeBackToMe2; //0x0232 
        bool m_softenLighting; //0x0233
}; // fb::WorldRenderSettings

};

#endif
#ifndef __ENUMERATIONS_H__
#define __ENUMERATIONS_H__


namespace fb
{
	enum MeshType
	{

		 MeshType_Rigid,                    // constant 0x0
		 MeshType_Skinned,                     // constant 0x1
		 MeshType_Composite                     // constant 0x2

	}; // fb::MeshType

	enum WeaponClassification
	{

		 WCNone,                    // constant 0x0
		 WCPrimary,                    // constant 0x1
		 WCSecondary                    // constant 0x2

	}; // fb::WeaponClassification

	enum EnlightenType
	{

		 EnlightenType_Dynamic,                    // constant 0x0
		 EnlightenType_LightProbe,                    // constant 0x1
		 EnlightenType_Static                     // constant 0x2

	}; // fb::EnlightenType

	enum EnlightenResolution
	{

		 EnlightenResolution_Low,                     // constant 0x0
		 EnlightenResolution_Medium,                     // constant 0x1
		 EnlightenResolution_High,                     // constant 0x2
		 EnlightenResolution_Higher,                     // constant 0x3
		 EnlightenResolution_Max                     // constant 0x4

	}; // fb::EnlightenResolution
	enum MeshDestructionMaterial
	{

		 MeshDestructionMaterial_None,                     // constant 0x0
		 MeshDestructionMaterial_Material1,                     // constant 0x1
		 MeshDestructionMaterial_Material2,                     // constant 0x2
		 MeshDestructionMaterial_Material3,                     // constant 0x3
		 MeshDestructionMaterial_Material4,                     // constant 0x4
		 MeshDestructionMaterial_Material5,                     // constant 0x5
		 MeshDestructionMaterial_Material6,                     // constant 0x6
		 MeshDestructionMaterial_Material7,                     // constant 0x7
		 MeshDestructionMaterial_Material8                    // constant 0x8

	}; // fb::MeshDestructionMaterial


	enum UpdatePass
	{

		 UpdatePass_PreSim,                     // constant 0x0
		 UpdatePass_PostSim,                     // constant 0x1
		 UpdatePass_PostFrame,                     // constant 0x2
		 UpdatePass_Frameerpolation,                     // constant 0x3
		 UpdatePass_PreInput,                     // constant 0x4
		 UpdatePass_Count                    // constant 0x5

	}; // fb::UpdatePass
	enum GameplayBones
	{

		 GameplayBones_UndefinedBone,                     // constant 0x0
		 GameplayBones_HeadBone,                     // constant 0x1
		 GameplayBones_AimBone,                     // constant 0x2
		 GameplayBones_RootBone,                     // constant 0x3
		 GameplayBones_WeaponBone,                     // constant 0x4
		 GameplayBones_ConnectBone,                     // constant 0x5
		 GameplayBones_RootMeshBone,                     // constant 0x6
		 GameplayBones_MagazineBone,                     // constant 0x7
		 GameplayBones_Count                     // constant 0x8

	}; // fb::GameplayBones
	enum SpotType
	{

			SpotType_None ,                 // constant 0x0
			SpotType_Active,				// constant 0x1
			SpotType_Passive,               // constant 0x2
			SpotType_Radar,                 // constant 0x3
			SpotType_Unspottable,           // constant 0x4
			SpotType_Count                  // constant 0x5

	}; // fb::SpotType
	enum ClientGameType
	{

		 ClientGameType_SinglePlayer,                    // constant 0x0
		 ClientGameType_Hosted,                     // constant 0x1
		 ClientGameType_Joined                     // constant 0x2

	}; // fb::ClientGameType

		enum UISystemType
	{

		 UISystem_None,                   // constant 0x0
		 UISystem_Standard                     // constant 0x1

	}; // fb::UISystemType

		 enum SquadId
    {
        Squad1 = 0x0,
        Squad2 = 0x1,
        Squad3 = 0x2,
        Squad4 = 0x3,
        Squad5 = 0x4,
        Squad6 = 0x5,
        Squad7 = 0x6,
        Squad8 = 0x7,
        SquadNone = 0x8,
        SquadIdCount = 0x9,
    };


		enum MaterialFlag
	{
		MfPenetrable = 0x1000000,
		MfClientDestructible = 0x2000000,
		MfBashable = 0x4000000,
		MfSeeThrough = 0x8000000,
		MfNoCollisionResponse = 0x10000000,
		MfNoCollisionResponseCombined = 0x20000000,
		MfIndexMask = 0xFFFFFF
	};

	enum PhysicsWorldType
	{

		 PhysicsWorldType_Client,                     // constant 0x0
		 PhysicsWorldType_ClientEffect,                     // constant 0x1
		 PhysicsWorldType_Server,                     // constant 0x2
		 PhysicsWorldType_Unknown                     // constant 0x64

	}; // fb::PhysicsWorldType

	enum ShaderProgram
	{

		ShaderProgram_DebugRender_Font2d,                     // constant 0x0
		ShaderProgram_DebugRender_FontShadow2d,                     // constant 0x1
		ShaderProgram_DebugRender_Color2d,                     // constant 0x2
		ShaderProgram_DebugRender_Color3d,                     // constant 0x3
		ShaderProgram_DebugRender_Lit3d,                     // constant 0x4
		ShaderProgram_DebugRender_LitGrid3d,                     // constant 0x5
		ShaderProgram_SimpleWhite,                     // constant 0x6
		ShaderProgram_MaterialID,                     // constant 0x7
		ShaderProgram_DownsampleQuarter,                     // constant 0x8
		ShaderProgram_DownsampleQuarterZ,                     // constant 0x9
		ShaderProgram_DownsampleHalf,                     // constant 0xA
		ShaderProgram_DownsampleDepthHalfSingleSample,                     // constant 0xB
		ShaderProgram_DownsampleHalfGrayscaleLog,                     // constant 0xC
		ShaderProgram_DownsampleCubeHalfPoisson13,                     // constant 0xD
		ShaderProgram_DownsampleCubeHalfPoisson13Clamped,                     // constant 0xE
		ShaderProgram_SeperableFilter,                     // constant 0xF
		ShaderProgram_GaussianBlurRgb15HCube,                     // constant 0x10
		ShaderProgram_GaussianBlurRgb15VCube,                     // constant 0x11
		ShaderProgram_FastGaussian9H,                     // constant 0x12
		ShaderProgram_FastGaussian9V,                     // constant 0x13
		ShaderProgram_GreyscaleGaussian9H,                     // constant 0x14
		ShaderProgram_GreyscaleGaussian9V,                     // constant 0x15
		ShaderProgram_CosineBlurRgbHCube,                     // constant 0x16
		ShaderProgram_CosineBlurRgbVCube,                     // constant 0x17
		ShaderProgram_GaussianBlurRgba15HCube,                     // constant 0x18
		ShaderProgram_GaussianBlurRgba15VCube,                     // constant 0x19
		ShaderProgram_CosineBlurRgbaHCube,                     // constant 0x1A
		ShaderProgram_CosineBlurRgbaVCube,                     // constant 0x1B
		ShaderProgram_Tex2d,                     // constant 0x1C
		ShaderProgram_Tex2dConstantAlpha,                     // constant 0x1D
		ShaderProgram_Tex2dSaturateAlpha,                     // constant 0x1E
		ShaderProgram_Tex2dAlpha,                     // constant 0x1F
		ShaderProgram_Tex2dAlphaOverlayAdd,                     // constant 0x20
		ShaderProgram_Tex2dAlphaOverlayLerp,                     // constant 0x21
		ShaderProgram_Tex2dPow,                     // constant 0x22
		ShaderProgram_Tex2dPowAlpha,                     // constant 0x23
		ShaderProgram_Tex2dMrt2,                     // constant 0x24
		ShaderProgram_Tex2dMrt3,                     // constant 0x25
		ShaderProgram_Tex2dMrt4,                     // constant 0x26
		ShaderProgram_Tex2dGrayscaleLog,                     // constant 0x27
		ShaderProgram_Tex3d,                     // constant 0x28
		ShaderProgram_TexCube,                     // constant 0x29
		ShaderProgram_TexCubeAlpha,                     // constant 0x2A
		ShaderProgram_TexCubeAlphaOverlayAdd,                     // constant 0x2B
		ShaderProgram_TexCubeAlphaOverlayLerp,                     // constant 0x2C
		ShaderProgram_Color,                     // constant 0x2D
		ShaderProgram_Tonemap,                     // constant 0x2E
		ShaderProgram_Dof,                     // constant 0x2F
		ShaderProgram_UnprojectDepthBuffer,                     // constant 0x30
		ShaderProgram_UnprojectDepthBufferHalf,                     // constant 0x31
		ShaderProgram_UnprojectDepthBufferMsaa,                     // constant 0x32
		ShaderProgram_SingleDepthSampleMsaa,                     // constant 0x33
		ShaderProgram_MaxDepthSampleMsaa,                     // constant 0x34
		ShaderProgram_TexYCrCb,                     // constant 0x35
		ShaderProgram_CombineTextures2,                     // constant 0x36
		ShaderProgram_CombineTextures3,                     // constant 0x37
		ShaderProgram_CombineTextures4,                     // constant 0x38
		ShaderProgram_CombineTextures5,                     // constant 0x39
		ShaderProgram_CombineTextures6,                     // constant 0x3A
		ShaderProgram_CombineTextures2Bilinear,                     // constant 0x3B
		ShaderProgram_CombineTextures3Bilinear,                     // constant 0x3C
		ShaderProgram_CombineTextures4Bilinear,                     // constant 0x3D
		ShaderProgram_CombineTextures5Bilinear,                     // constant 0x3E
		ShaderProgram_CombineTextures6Bilinear,                     // constant 0x3F
		ShaderProgram_CombineOpaqueAndTrans2d,                     // constant 0x40
		ShaderProgram_CombineOpaqueAndTransCube,                     // constant 0x41
		ShaderProgram_CombineOpaqueAndTrans2dSpecial,                     // constant 0x42
		ShaderProgram_CombineOpaqueAndTransCubeSpecial,                     // constant 0x43
		ShaderProgram_CrtHudFx,                     // constant 0x44
		ShaderProgram_CrtAnalogLinkHudFx,                     // constant 0x45
		ShaderProgram_RadialBlur,                     // constant 0x46
		ShaderProgram_PoissonRadialBlur,                     // constant 0x47
		ShaderProgram_ChromaticAberrationWithRadialBlend,                     // constant 0x48
		ShaderProgram_FLIR,                     // constant 0x49
		ShaderProgram_ColorTint,                     // constant 0x4A
		ShaderProgram_WriteZ,                     // constant 0x4B
		ShaderProgram_WriteHalfResZ,                     // constant 0x4C
		ShaderProgram_WriteHalfResZFat,                     // constant 0x4D
		ShaderProgram_WriteHalfResZAverage,                     // constant 0x4E
		ShaderProgram_LinearZ,                     // constant 0x4F
		ShaderProgram_ParticleVertexShadows,                     // constant 0x50
		ShaderProgram_HalfResUpsampleBilateral,                     // constant 0x51
		ShaderProgram_HalfResUpsampleBilateralTiled,                     // constant 0x52
		ShaderProgram_HalfResUpsampleBilinearTiled,                     // constant 0x53
		ShaderProgram_HalfResCategorize,                     // constant 0x54
		ShaderProgram_HalfResCategorizeDownsample,                     // constant 0x55
		ShaderProgram_DigitalDistortion,                     // constant 0x56
		ShaderProgram_MotionBlur,                     // constant 0x57
		ShaderProgram_CalcVelocityFromZBuffer,                     // constant 0x58
		ShaderProgram_FXAA,                     // constant 0x59
		ShaderProgram_HorizonBasedAO,                     // constant 0x5A
		ShaderProgram_HorizonBasedAO_BlurPS,                     // constant 0x5B
		ShaderProgram_HorizonBasedAO_BlurCS,                     // constant 0x5C
		ShaderProgram_HorizonBasedAO_Composite,                     // constant 0x5D
		ShaderProgram_HorizonBasedAO_CompositeTemporal,                     // constant 0x5E
		ShaderProgram_HorizonBasedAO_NoiseDetection,                     // constant 0x5F
		ShaderProgram_SSAO,                     // constant 0x60
		ShaderProgram_LightTileDownsampleHalf,                     // constant 0x61
		ShaderProgram_LightTileDownsampleHalfStage2,                     // constant 0x62
		ShaderProgram_LightTileDownsampleHalfStage3,                     // constant 0x63
		ShaderProgram_TiledLightVisibility_Point,                     // constant 0x64
		ShaderProgram_TiledLightVisibility_Spot,                     // constant 0x65
		ShaderProgram_TiledLightVisibility_Line,                     // constant 0x66
		ShaderProgram_TiledLightVisibility_CalcTileFrustaData,                     // constant 0x67
		ShaderProgram_DeferredGBufferSimpleFixup,                     // constant 0x68
		ShaderProgram_MsaaClassify,                     // constant 0x69
		ShaderProgram_DeferredPointLight,                     // constant 0x6A
		ShaderProgram_DeferredPointLightCS,                     // constant 0x6B
		ShaderProgram_DeferredPointLightTile,                     // constant 0x6C
		ShaderProgram_DeferredPointLightZ,                     // constant 0x6D
		ShaderProgram_DeferredLineLight,                     // constant 0x6E
		ShaderProgram_DeferredLineLightTile,                     // constant 0x6F
		ShaderProgram_DeferredSpotLight,                     // constant 0x70
		ShaderProgram_DeferredSpotLightZ,                     // constant 0x71
		ShaderProgram_DeferredConeLight,                     // constant 0x72
		ShaderProgram_DeferredConeLightTile,                     // constant 0x73
		ShaderProgram_DeferredOutdoorLight,                     // constant 0x74
		ShaderProgram_DeferredOutdoorLightTile,                     // constant 0x75
		ShaderProgram_Sky,                     // constant 0x76
		ShaderProgram_HeightfieldTessellation,                     // constant 0x77
		ShaderProgram_XenonMemCopy,                     // constant 0x78
		ShaderProgram_XenonFastUntile,                     // constant 0x79
		ShaderProgram_XenonFastDepthStencilFill,                     // constant 0x7A
		ShaderProgram_XenonFastDepthStencilFill_ZOnly,                     // constant 0x7B
		ShaderProgram_XenonJobEnable,                     // constant 0x7C
		ShaderProgram_Ui_Textured,                     // constant 0x7D
		ShaderProgram_Ui_Textured2,                     // constant 0x7E
		ShaderProgram_Ui_Textured3,                     // constant 0x7F
		ShaderProgram_Ui_Scaleform_StripSolidColor,                     // constant 0x80
		ShaderProgram_Ui_Scaleform_StripCxformTextureMultiply,                     // constant 0x81
		ShaderProgram_Ui_Scaleform_StripCxformTexture,                     // constant 0x82
		ShaderProgram_Ui_Scaleform_StripCxformGauraudNoAddAlpha,                     // constant 0x83
		ShaderProgram_Ui_Scaleform_StripCxformGauraud,                     // constant 0x84
		ShaderProgram_Ui_Scaleform_StripCxformGauraudTexture,                     // constant 0x85
		ShaderProgram_Ui_Scaleform_StripCxform2Texture,                     // constant 0x86
		ShaderProgram_Ui_Scaleform_StripCxformGauraudMultiply,                     // constant 0x87
		ShaderProgram_Ui_Scaleform_StripCxformGauraudMultiplyNoAddAlpha,                     // constant 0x88
		ShaderProgram_Ui_Scaleform_StripCxformGauraudMultiplyTexture,                     // constant 0x89
		ShaderProgram_Ui_Scaleform_StripCxformMultiply2Texture,                     // constant 0x8A
		ShaderProgram_Ui_Scaleform_XY16iC32SolidColor,                     // constant 0x8B
		ShaderProgram_Ui_Scaleform_XY16iC32CxformTextureMultiply,                     // constant 0x8C
		ShaderProgram_Ui_Scaleform_XY16iC32CxformTexture,                     // constant 0x8D
		ShaderProgram_Ui_Scaleform_XY16iC32CxformGauraudNoAddAlpha,                     // constant 0x8E
		ShaderProgram_Ui_Scaleform_XY16iC32CxformGauraud,                     // constant 0x8F
		ShaderProgram_Ui_Scaleform_XY16iC32CxformGauraudTexture,                     // constant 0x90
		ShaderProgram_Ui_Scaleform_XY16iC32Cxform2Texture,                     // constant 0x91
		ShaderProgram_Ui_Scaleform_XY16iC32CxformGauraudMultiply,                     // constant 0x92
		ShaderProgram_Ui_Scaleform_XY16iC32CxformGauraudMultiplyNoAddAlpha,                     // constant 0x93
		ShaderProgram_Ui_Scaleform_XY16iC32CxformGauraudMultiplyTexture,                     // constant 0x94
		ShaderProgram_Ui_Scaleform_XY16iC32CxformMultiply2Texture,                     // constant 0x95
		ShaderProgram_Ui_Scaleform_XY16iCF32SolidColor,                     // constant 0x96
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformTextureMultiply,                     // constant 0x97
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformTexture,                     // constant 0x98
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformGauraudNoAddAlpha,                     // constant 0x99
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformGauraud,                     // constant 0x9A
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformGauraudTexture,                     // constant 0x9B
		ShaderProgram_Ui_Scaleform_XY16iCF32Cxform2Texture,                     // constant 0x9C
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformGauraudMultiply,                     // constant 0x9D
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformGauraudMultiplyNoAddAlpha,                     // constant 0x9E
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformGauraudMultiplyTexture,                     // constant 0x9F
		ShaderProgram_Ui_Scaleform_XY16iCF32CxformMultiply2Texture,                     // constant 0xA0
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2SolidColor,                     // constant 0xA1
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformTextureMultiply,                     // constant 0xA2
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformTexture,                     // constant 0xA3
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformGauraudNoAddAlpha,                     // constant 0xA4
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformGauraud,                     // constant 0xA5
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformGauraudTexture,                     // constant 0xA6
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2Cxform2Texture,                     // constant 0xA7
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformGauraudMultiply,                     // constant 0xA8
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformGauraudMultiplyNoAddAlpha,                     // constant 0xA9
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformGauraudMultiplyTexture,                     // constant 0xAA
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2CxformMultiply2Texture,                     // constant 0xAB
		ShaderProgram_Ui_Scaleform_GlyphTextTextureAlpha,                     // constant 0xAC
		ShaderProgram_Ui_Scaleform_GlyphTextTextureColorMultiply,                     // constant 0xAD
		ShaderProgram_Ui_Scaleform_GlyphTextTextureColor,                     // constant 0xAE
		ShaderProgram_Ui_Scaleform_StripFilterBlur,                     // constant 0xAF
		ShaderProgram_Ui_Scaleform_StripFilterShadow,                     // constant 0xB0
		ShaderProgram_Ui_Scaleform_XY16iC32FilterBlur,                     // constant 0xB1
		ShaderProgram_Ui_Scaleform_XY16iC32FilterShadow,                     // constant 0xB2
		ShaderProgram_Ui_Scaleform_XY16iCF32FilterBlur,                     // constant 0xB3
		ShaderProgram_Ui_Scaleform_XY16iCF32FilterShadow,                     // constant 0xB4
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2FilterBlur,                     // constant 0xB5
		ShaderProgram_Ui_Scaleform_XY16iCF32_T2FilterShadow,                     // constant 0xB6
		ShaderProgram_Ui_Scaleform_GlyphFilterBlur,                     // constant 0xB7
		ShaderProgram_Ui_Scaleform_GlyphFilterShadow,                     // constant 0xB8
		ShaderProgram_Ui_Minimap,                     // constant 0xB9
		ShaderProgram_Ui_MinimapIcon,                     // constant 0xBA
		ShaderProgram_Ui_CombatArea,                     // constant 0xBB
		ShaderProgram_ExperimentShader_A,                     // constant 0xBC
		ShaderProgram_ExperimentShader_B,                     // constant 0xBD
		ShaderProgram_TextureCompress_A,                     // constant 0xBE
		ShaderProgram_TextureCompress_DXT1,                     // constant 0xBF
		ShaderProgram_TextureCompress_DXT5,                     // constant 0xC0
		ShaderProgram_ErrorDifferenceSurface_RGB,                     // constant 0xC1
		ShaderProgram_ErrorDifferenceSurface_Alpha,                     // constant 0xC2
		ShaderProgram_XenonEncodeDXT5MemExport,                     // constant 0xC3
		ShaderProgram_TerrainEncodeSurface_A,                     // constant 0xC4
		ShaderProgram_TerrainEncodeSurface_B,                     // constant 0xC5
		ShaderProgram_TerrainPatchVertexYFetch,                     // constant 0xC6
		ShaderProgram_TerrainMeshScatteringYFetch,                     // constant 0xC7
		ShaderProgram_TexYCrCbA,                     // constant 0xC8
		ShaderProgram_RgbSeparation,                     // constant 0xC9
		ShaderProgram_Distort,                     // constant 0xCA
		ShaderProgramCount,                     // constant 0xCB

	}; // fb::ShaderProgram

		enum RenderBlendMode
	{

		RenderBlendMode_Zero,                     // constant 0x0
		RenderBlendMode_One,                     // constant 0x1
		RenderBlendMode_SourceColor,                     // constant 0x2
		RenderBlendMode_InvSourceColor,                     // constant 0x3
		RenderBlendMode_SourceAlpha,                     // constant 0x4
		RenderBlendMode_InvSourceAlpha,                     // constant 0x5
		RenderBlendMode_DestColor,                     // constant 0x6
		RenderBlendMode_InvDestColor,                     // constant 0x7
		RenderBlendMode_DestAlpha,                     // constant 0x8
		RenderBlendMode_InvDestAlpha,                     // constant 0x9
		RenderBlendMode_SourceAlphaSaturate                  // constant 0xA

	}; // fb::RenderBlendMode

	enum RenderCullMode
{

		 RenderCullMode_None,                     // constant 0x0
		 RenderCullMode_Front,                     // constant 0x1
		 RenderCullMode_Back,                     // constant 0x2

	};// fb::RenderCullMode

		enum RenderFillMode
	{

		 RenderFillMode_Solid,                     // constant 0x0
		 RenderFillMode_Wireframe,                     // constant 0x1

	}; // fb::RenderFillMode

		enum RenderBlendOp
	{

		 RenderBlendOp_Add,                     // constant 0x0
		 RenderBlendOp_Subtract,                     // constant 0x1
		 RenderBlendOp_RevSubtract,                     // constant 0x2
		 RenderBlendOp_Min,                     // constant 0x3
		 RenderBlendOp_Max                     // constant 0x4

	}; // fb::RenderBlendOp

		enum RenderDepthMode
	{

		 RenderDepthMode_Disabled,                     // constant 0x0
		 RenderDepthMode_ReadOnly,                     // constant 0x1
		 RenderDepthMode_ReadAndWrite,                     // constant 0x2
		 RenderDepthMode_WriteOnly                     // constant 0x3

	}; // fb::RenderDepthMode
		enum PrimitiveType
	{

		 PrimitiveType_PointList,                     // constant 0x0
		 PrimitiveType_LineList,                     // constant 0x1
		 PrimitiveType_LineStrip,                     // constant 0x2
		 PrimitiveType_TriangleList,                     // constant 0x3
		 PrimitiveType_TriangleStrip,                     // constant 0x5
		 PrimitiveType_QuadList,                     // constant 0x7
		 PrimitiveType_XenonRectList                   // constant 0x8

	}; // fb::PrimitiveType

	enum SecureReason
	{

		 SecureReason_Ok,                     // constant 0x0
		 SecureReason_WrongProtocolVersion,                     // constant 0x1
		 SecureReason_WrongTitleVersion,                     // constant 0x2
		 SecureReason_ServerFull,                     // constant 0x3
		 SecureReason_KickedOut,                     // constant 0x4
		 SecureReason_Banned,                     // constant 0x5
		 SecureReason_GenericError,                     // constant 0x6
		 SecureReason_WrongPassword,                     // constant 0x7
		 SecureReason_KickedOutDemoOver,                     // constant 0x8
		 SecureReason_RankRestricted,                     // constant 0x9
		 SecureReason_ConfigurationNotAllowed,                     // constant 0xA
		 SecureReason_ServerReclaimed,                     // constant 0xB
		 SecureReason_MissingContent,                     // constant 0xC
		 SecureReason_NotVerified,                     // constant 0xD
		 SecureReason_TimedOut,                     // constant 0xE
		 SecureReason_ConnectFailed,                     // constant 0xF
		 SecureReason_NoReply,                     // constant 0x10
		 SecureReason_AcceptFailed,                     // constant 0x11
		 SecureReason_MismatchingContent                    // constant 0x12

	}; // fb::SecureReason

	
	enum RayCastFlags
    {
            CheckDetailMesh                 = 0x1,
            IsAsyncRaycast                  = 0x2,
            DontCheckWater                  = 0x4,
            DontCheckTerrain                = 0x8,
            DontCheckRagdoll                = 0x10,
            DontCheckCharacter              = 0x20,
            DontCheckGroup                  = 0x40,
			DontCheckPhantoms				= 0x80,
            FORCE32BIT                      = 0x7FFFFFFF
    };

	enum WeaponClassEnum
	{

		 wcAssault,                     // constant 0x0
		 wcShotgun,                     // constant 0x1
		 wcSmg,                     // constant 0x2
		 wcLmg,                     // constant 0x3
		 wcSniper,                     // constant 0x4
		 wcUgl,                     // constant 0x5
		 wcHgr,                     // constant 0x6
		 wcAt,                     // constant 0x7
		 wcATMine,                     // constant 0x8
		 wcAutoInjector,                     // constant 0x9
		 wcC4,                     // constant 0xA
		 wcKnife,                     // constant 0xB
		 wcLaserDesignator,                     // constant 0xC
		 wcLaserPaer,                     // constant 0xD
		 wcMedKit,                     // constant 0xE
		 wcMortarStrike,                     // constant 0xF
		 wcPowerTool,                     // constant 0x10
		 wcTracerDart,                     // constant 0x11
		 wcRadioBeacon,                     // constant 0x12
		 wcEodBot,                     // constant 0x13
		 wcReconMav,                     // constant 0x14
		 wcUGS,                     // constant 0x15
		 wcCount,                     // constant 0x16
		 wcNone                     // constant 0x17

	}; // fb::WeaponClassEnum

	enum Realm
	{
		Realm_Client,
		Realm_Server,
		Realm_ClientAndServer,
		Realm_None,
		Realm_Pipeline,
	};

	enum ResourceCompartment
	{
		ResourceCompartment_First_,
		ResourceCompartment_Static,
		ResourceCompartment_Frontend,
		ResourceCompartment_LoadingScreen,
		ResourceCompartment_Game,
		ResourceCompartment_HUD,
		ResourceCompartment_Debug,
		ResourceCompartment_Dynamic_Begin_,
		ResourceCompartment_Dynamic_Synchronized_Begin_,
		ResourceCompartment_Dynamic_Synchronized_End_,
		ResourceCompartment_Dynamic_ClientOnly_Begin_,
		ResourceCompartment_Dynamic_ClientOnly_End_,
		ResourceCompartment_Dynamic_End_,
		ResourceCompartment_Count_,
		ResourceCompartment_Forbidden,
	};

	enum InputDeviceKeys
	{

		 IDK_None,                     // constant 0x0
		 IDK_Escape,                     // constant 0x1
		 IDK_1,                     // constant 0x2
		 IDK_2,                     // constant 0x3
		 IDK_3,                     // constant 0x4
		 IDK_4,                     // constant 0x5
		 IDK_5,                     // constant 0x6
		 IDK_6,                     // constant 0x7
		 IDK_7,                     // constant 0x8
		 IDK_8,                     // constant 0x9
		 IDK_9,                     // constant 0xA
		 IDK_0,                     // constant 0xB
		 IDK_Minus,                     // constant 0xC
		 IDK_Equals,                     // constant 0xD
		 IDK_Backspace,                     // constant 0xE
		 IDK_Tab,                     // constant 0xF
		 IDK_Q,                     // constant 0x10
		 IDK_W,                     // constant 0x11
		 IDK_E,                     // constant 0x12
		 IDK_R,                     // constant 0x13
		 IDK_T,                     // constant 0x14
		 IDK_Y,                     // constant 0x15
		 IDK_U,                     // constant 0x16
		 IDK_I,                     // constant 0x17
		 IDK_O,                     // constant 0x18
		 IDK_P,                     // constant 0x19
		 IDK_LeftBracket,                     // constant 0x1A
		 IDK_RightBracket,                     // constant 0x1B
		 IDK_Enter,                     // constant 0x1C
		 IDK_LeftCtrl,                     // constant 0x1D
		 IDK_A,                     // constant 0x1E
		 IDK_S,                     // constant 0x1F
		 IDK_D,                     // constant 0x20
		 IDK_F,                     // constant 0x21
		 IDK_G,                     // constant 0x22
		 IDK_H,                     // constant 0x23
		 IDK_J,                     // constant 0x24
		 IDK_K,                     // constant 0x25
		 IDK_L,                     // constant 0x26
		 IDK_Semicolon,                     // constant 0x27
		 IDK_Apostrophe,                     // constant 0x28
		 IDK_Grave,                     // constant 0x29
		 IDK_LeftShift,                     // constant 0x2A
		 IDK_Backslash,                     // constant 0x2B
		 IDK_Z,                     // constant 0x2C
		 IDK_X,                     // constant 0x2D
		 IDK_C,                     // constant 0x2E
		 IDK_V,                     // constant 0x2F
		 IDK_B,                     // constant 0x30
		 IDK_N,                     // constant 0x31
		 IDK_M,                     // constant 0x32
		 IDK_Comma,                     // constant 0x33
		 IDK_Period,                     // constant 0x34
		 IDK_Slash,                     // constant 0x35
		 IDK_RightShift,                     // constant 0x36
		 IDK_Multiply,                     // constant 0x37
		 IDK_LeftAlt,                     // constant 0x38
		 IDK_Space,                     // constant 0x39
		 IDK_Capital,                     // constant 0x3A
		 IDK_F1,                     // constant 0x3B
		 IDK_F2,                     // constant 0x3C
		 IDK_F3,                     // constant 0x3D
		 IDK_F4,                     // constant 0x3E
		 IDK_F5,                     // constant 0x3F
		 IDK_F6,                     // constant 0x40
		 IDK_F7,                     // constant 0x41
		 IDK_F8,                     // constant 0x42
		 IDK_F9,                     // constant 0x43
		 IDK_F10,                     // constant 0x44
		 IDK_Numlock,                     // constant 0x45
		 IDK_ScrollLock,                     // constant 0x46
		 IDK_Numpad7,                     // constant 0x47
		 IDK_Numpad8,                     // constant 0x48
		 IDK_Numpad9,                     // constant 0x49
		 IDK_Subtract,                     // constant 0x4A
		 IDK_Numpad4,                     // constant 0x4B
		 IDK_Numpad5,                     // constant 0x4C
		 IDK_Numpad6,                     // constant 0x4D
		 IDK_Add,                     // constant 0x4E
		 IDK_Numpad1,                     // constant 0x4F
		 IDK_Numpad2,                     // constant 0x50
		 IDK_Numpad3,                     // constant 0x51
		 IDK_Numpad0,                     // constant 0x52
		 IDK_Decimal,                     // constant 0x53
		 IDK_OEM_102,                     // constant 0x56
		 IDK_F11,                     // constant 0x57
		 IDK_F12,                     // constant 0x58
		 IDK_F13,                     // constant 0x64
		 IDK_F14,                     // constant 0x65
		 IDK_F15,                     // constant 0x66
		 IDK_Kana,                     // constant 0x70
		 IDK_Convert,                     // constant 0x79
		 IDK_NoConvert,                     // constant 0x7B
		 IDK_Yen,                     // constant 0x7D
		 IDK_NumpadEquals,                     // constant 0x8D
		 IDK_PrevTrack,                     // constant 0x90
		 IDK_At,                     // constant 0x91
		 IDK_Colon,                     // constant 0x92
		 IDK_Underline,                     // constant 0x93
		 IDK_Kanji,                     // constant 0x94
		 IDK_Stop,                     // constant 0x95
		 IDK_Ax,                     // constant 0x96
		 IDK_Unlabeled,                     // constant 0x97
		 IDK_NextTrack,                     // constant 0x99
		 IDK_NumpadEnter,                     // constant 0x9C
		 IDK_RightCtrl,                     // constant 0x9D
		 IDK_Mute,                     // constant 0xA0
		 IDK_Calculator,                     // constant 0xA1
		 IDK_PlayPause,                     // constant 0xA2
		 IDK_MediaStop,                     // constant 0xA4
		 IDK_VolumeDown,                     // constant 0xAE
		 IDK_VolumeUp,                     // constant 0xB0
		 IDK_WebHome,                     // constant 0xB2
		 IDK_NumpadComma,                     // constant 0xB3
		 IDK_Divide,                     // constant 0xB5
		 IDK_PrintScreen,                     // constant 0xB7
		 IDK_RightAlt,                     // constant 0xB8
		 IDK_Home,                     // constant 0xC7
		 IDK_ArrowUp,                     // constant 0xC8
		 IDK_PageUp,                     // constant 0xC9
		 IDK_ArrowLeft,                     // constant 0xCB
		 IDK_ArrowRight,                     // constant 0xCD
		 IDK_End,                     // constant 0xCF
		 IDK_ArrowDown,                     // constant 0xD0
		 IDK_PageDown,                     // constant 0xD1
		 IDK_Insert,                     // constant 0xD2
		 IDK_Delete,                     // constant 0xD3
		 IDK_LeftWin,                     // constant 0xDB
		 IDK_RightWin,                     // constant 0xDC
		 IDK_AppMenu,                     // constant 0xDD
		 IDK_Power,                     // constant 0xDE
		 IDK_Sleep,                     // constant 0xDF
		 IDK_Wake,                     // constant 0xE3
		 IDK_WebSearch,                     // constant 0xE5
		 IDK_WebFavorites,                     // constant 0xE6
		 IDK_WebRefresh,                     // constant 0xE7
		 IDK_WebStop,                     // constant 0xE8
		 IDK_WebForward,                     // constant 0xE9
		 IDK_WebBack,                     // constant 0xEA
		 IDK_MyComputer,                     // constant 0xEB
		 IDK_Mail,                     // constant 0xEC
		 IDK_MediaSelect,                     // constant 0xED
		 IDK_Pause,                     // constant 0xC5
		 IDK_Undefined                  // constant 0xFF

	}; // fb::InputDeviceKeys



	enum InputConceptIdentifiers
	{
		ConceptMoveFB, // 0
		ConceptMoveLR, // 1
		ConceptMoveForward,
		ConceptMoveBackward,
		ConceptMoveLeft,
		ConceptMoveRight,
		ConceptYaw,
		ConceptPitch,
		ConceptRoll,
		ConceptRecenterCamera,
		ConceptFire, // 10
		ConceptAltFire,
		ConceptFireCountermeasure,
		ConceptReload,
		ConceptZoom,
		ConceptToggleCamera,
		ConceptSprint,
		ConceptCrawl,
		ConceptToggleWeaponLight,
		ConceptJump,
		ConceptCrouch, // 20
		ConceptCrouchOnHold,
		ConceptProne,
		ConceptInteract,
		ConceptPickUp,
		ConceptDrop,
		ConceptBreathControl,
		ConceptParachute,
		ConceptSwitchInventoryItem,
		ConceptSelectInventoryItem1,
		ConceptSelectInventoryItem2, // 30
		ConceptSelectInventoryItem3,
		ConceptSelectInventoryItem4,
		ConceptSelectInventoryItem5,
		ConceptSelectInventoryItem6,
		ConceptSelectInventoryItem7,
		ConceptSelectInventoryItem8,
		ConceptSelectInventoryItem9,
		ConceptSwitchToPrimaryWeapon,
		ConceptSwitchToGrenadeLauncher,
		ConceptSwitchToStaticGadget, // 40
		ConceptSwitchToDynamicGadget1,
		ConceptSwitchToDynamicGadget2,
		ConceptMeleeAttack,
		ConceptThrowGrenade,
		ConceptCycleFireMode,
		ConceptChangeVehicle,
		ConceptBrake,
		ConceptHandBrake,
		ConceptClutch,
		ConceptGearUp, // 50
		ConceptGearDown,
		ConceptGearSwitch,
		ConceptNextPosition,
		ConceptSelectPosition1,
		ConceptSelectPosition2,
		ConceptSelectPosition3,
		ConceptSelectPosition4,
		ConceptSelectPosition5,
		ConceptSelectPosition6,
		ConceptSelectPosition7, // 60
		ConceptSelectPosition8,
		ConceptCameraPitch,
		ConceptCameraYaw,
		ConceptMapZoom,
		ConceptMapInnerZoom,
		ConceptMapSize,
		ConceptMapThreeDimensional,
		ConceptScoreboard,
		ConceptMenu,
		ConceptSpawnMenu, // 70
		ConceptCancel,
		ConceptCommMenu1,
		ConceptCommMenu2,
		ConceptCommMenu3,
		ConceptAccept,
		ConceptDecline,
		ConceptSelect,
		ConceptBack,
		ConceptActivate,
		ConceptDeactivate, // 80
		ConceptEdit,
		ConceptView,
		ConceptParentNavigateLeft,
		ConceptParentNavigateRight,
		ConceptMenuZoomIn,
		ConceptMenuZoomOut,
		ConceptPanX,
		ConceptPanY,
		ConceptVoiceFunction1,
		ConceptSayAllChat, // 90
		ConceptTeamChat,
		ConceptSquadChat,
		ConceptSquadLeaderChat,
		ConceptQuicktimeInteractDrag,
		ConceptQuicktimeFire,
		ConceptQuicktimeBlock,
		ConceptQuicktimeFastMelee,
		ConceptQuicktimeJumpClimb,
		ConceptQuicktimeCrouchDuck,
		ConceptFreeCameraMoveUp, // 100
		ConceptFreeCameraMoveDown,
		ConceptFreeCameraMoveLR,
		ConceptFreeCameraMoveFB,
		ConceptFreeCameraRotateX,
		ConceptFreeCameraRotateY,
		ConceptFreeCameraIncreaseSpeed,
		ConceptFreeCameraDecreaseSpeed,
		ConceptFreeCameraFOVModifier,
		ConceptFreeCameraChangeFOV,
		ConceptFreeCameraSwitchSpeed, // 110
		ConceptFreeCameraTurboSpeed,
		ConceptFreeCameraActivator1,
		ConceptFreeCameraActivator2,
		ConceptFreeCameraActivator3,
		ConceptFreeCameraMayaInputActivator,
		ConceptTargetedCameraDistance,
		ConceptTargetedCameraRotateX,
		ConceptTargetedCameraRotateY,
		ConceptTargetedCameraChangeSpeed,
		ConceptLThumb, // 120
		ConceptRThumb,
		ConceptUndefined,
		ConceptSize, // 123
	};

	enum InputActionMapSlot
	{
		InputActionMapSlot_Undefined,
		InputActionMapSlot_Root1,
		InputActionMapSlot_Root2,
		InputActionMapSlot_Root3,
		InputActionMapSlot_Root4,
		InputActionMapSlot_Root5,
		InputActionMapSlot_Root6,
		InputActionMapSlot_Root7,
		InputActionMapSlot_Root8,
		InputActionMapSlot_Root9,
		InputActionMapSlot_Root10,
		InputActionMapSlot_Root11,
		InputActionMapSlot_Root12,
		InputActionMapSlot_Root13,
		InputActionMapSlot_Root14,
		InputActionMapSlot_Root15,
		InputActionMapSlot_Root16,
		InputActionMapSlot_Sticks1,
		InputActionMapSlot_Sticks2,
		InputActionMapSlot_Sticks3,
		InputActionMapSlot_Sticks4,
		InputActionMapSlot_Buttons1,
		InputActionMapSlot_Buttons2,
		InputActionMapSlot_Buttons3,
		InputActionMapSlot_Buttons4,
		InputActionMapSlot_Sticks1Buttons1,
		InputActionMapSlot_Sticks1Buttons2,
		InputActionMapSlot_Sticks1Buttons3,
		InputActionMapSlot_Sticks1Buttons4,
		InputActionMapSlot_Sticks2Buttons1,
		InputActionMapSlot_Sticks2Buttons2,
		InputActionMapSlot_Sticks2Buttons3,
		InputActionMapSlot_Sticks2Buttons4,
		InputActionMapSlot_Sticks3Buttons1,
		InputActionMapSlot_Sticks3Buttons2,
		InputActionMapSlot_Sticks3Buttons3,
		InputActionMapSlot_Sticks3Buttons4,
		InputActionMapSlot_Sticks4Buttons1,
		InputActionMapSlot_Sticks4Buttons2,
		InputActionMapSlot_Sticks4Buttons3,
		InputActionMapSlot_Sticks4Buttons4,
		InputActionMapSlot_Count,
	};

	enum CameraIds
	{
		NoCameraId,
		FreeCameraId,
		EntryCameraId,
		CameraIdCount,
	};

	enum StreamRealm
	{
		StreamRealm_None,
		StreamRealm_Client,
		StreamRealm_Both,
	};

	enum PersonViewEnum
	{
		FirstPerson,
		ThirdPerson,
		PersonViewCount,
	};

	enum PlayerSpawnType
	{
		PlayerSpawnType_HumanPlayer,
		PlayerSpawnType_AiPlayer,
		PlayerSpawnType_Actor,
	};

	enum PersonViewMode
	{
		PersonViewMode_FirstPerson,
		PersonViewMode_ThirdPerson,
	};

	enum CharacterPoseType
	{
		CharacterPoseType_Stand,
		CharacterPoseType_Crouch,
		CharacterPoseType_Prone,
		CharacterPoseTypeCount,
	};

	enum CharacterPoseCollisionType
	{
		CharacterPoseCollisionType_Capsule,
		CharacterPoseCollisionType_Pencil,
	};

	enum CharacterStateType
	{
		CharacterStateType_OnGround,
		CharacterStateType_Jumping,
		CharacterStateType_InAir,
		CharacterStateType_Climbing,
		CharacterStateType_Falling,
		CharacterStateType_User_0,
		CharacterStateType_User_1,
		CharacterStateType_User_2,
		CharacterStateType_User_3,
		CharacterStateType_User_4,
		CharacterStateType_User_5,
		CharacterStateType_StateCount,
		CharacterStateType_Parachute,
		CharacterStateType_Swimming,
		CharacterStateType_AnimationControlled,
		CharacterStateType_Sliding,
	};

	enum TeamId
	{

		TeamNeutral  ,                // constant 0x0
		Team1,                     // constant 0x1
		Team2,                     // constant 0x2
		Team3,                     // constant 0x3
		Team4,                     // constant 0x4
		Team5,                     // constant 0x5
		Team6,                     // constant 0x6
		Team7,                     // constant 0x7
		Team8,                     // constant 0x8
		Team9,                     // constant 0x9
		Team10,                     // constant 0xA
		Team11,                     // constant 0xB
		Team12,                     // constant 0xC
		Team13,                     // constant 0xD
		Team14,                     // constant 0xE
		Team15,                     // constant 0xF
		Team16,                     // constant 0x10
		TeamIdCount                     // constant 0x11

	}; // fb::TeamId

	enum SoldierEntityActionState
	{
		Jumping,
		Walking,
		Sliding,
		Air,
		Falling,
		Parachute,
		Swim,
		Climb,
		AnimationDriven,
		NumberOfBits,
	};

	enum HitReactionType
	{
		HRT_Body,
		HRT_Head,
		HRT_RightArm,
		HRT_LeftArm,
		HRT_RightLeg,
		HRT_LeftLeg,
		HRT_Count,
	};

	enum EntryInputActionEnum
	{
		EIAThrottle,
		EIAStrafe,
		EIABrake,
		EIASwitchPrimaryInventory,
		EIAYaw,
		EIAPitch,
		EIARoll,
		EIAFire,
		EIACameraPitch,
		EIACameraYaw,
		EIAFireCountermeasure,
		EIAZoom,
		EIAJump,
		EIAChangePose,
		EIAProne,
		EIAReload,
		EIASelectWeapon1,
		EIASelectWeapon2,
		EIASelectWeapon3,
		EIASelectWeapon4,
		EIASelectWeapon5,
		EIASelectWeapon6,
		EIASelectWeapon7,
		EIASelectWeapon8,
		EIASelectWeapon9,
		EIASwitchPrimaryWeapon,
		EIAGrenadeLauncher,
		EIAStaticGadget,
		EIADynamicGadget1,
		EIADynamicGadget2,
		EIAMeleeAttack,
		EIAThrowGrenade,
		EIASprint,
		EIACrawlSpeed,
		EIACycleFireMode,
		EIAInteract,
		EIAToggleParachute,
		EIACycleRadioChannel,
		EIAToggleCamera,
		EIAScoreboardMenu,
		EIAGearUp,
		EIAGearUpOrToggleWeaponLight,
		EIAGearDown,
		EIAGearDownOrExitSupportedShooting,
		EIAClutch,
		EIAHandBrake,
		EIAGiveOrder,
		EIABreathControl,
		EIAMapZoom,
		EIAChangeVehicle,
		EIAChangeEntry,
		EIAChangeEntry1,
		EIAChangeEntry2,
		EIAChangeEntry3,
		EIAChangeEntry4,
		EIAChangeEntry5,
		EIAChangeEntry6,
		EIAChangeEntry7,
		EIAChangeEntry8,
		EIAThreeDimensionalMap,
		EIAShowCommoRose,
		EIAShowLeaderCommoRose,
		EIAQuicktimeInteractDrag,
		EIAQuicktimeFire,
		EIAQuicktimeBlock,
		EIAQuicktimeFastMelee,
		EIAQuicktimeJumpClimb,
		EIAQuicktimeCrouchDuck,
		EIAUndefined,
		EIANoInput,
	};

	enum WeaponAnimType
	{
		WeaponAnimType_NoAddon,
		WeaponAnimType_Bipod,
		WeaponAnimType_Foregrip,
		WeaponAnimType_40mm_GL,
		WeaponAnimType_40mm_GL_Fire,
		WeaponAnimType_Underslung_Shotgun,
		WeaponAnimType_Underslung_Shotgun_Fire,
		WeaponAnimType_Straight_Pull_Bolt,
	};

	enum AnimatedFireEnum
	{
		 AnimatedFireAutomatic,                     // constant 0x0
		 AnimatedFireSingle,                     // constant 0x1
		 AnimatedFireHoldAndRelease,                     // constant 0x2
		 AnimatedFireDelayedSingleShot,                     // constant 0x3
		 AnimatedFireSimple                    // constant 0x4
	}; // fb::AnimatedFireEnum

	enum ZoomLevelActivateEventType
	{
		ZoomLevelActivateEventType_Disable,
		ZoomLevelActivateEventType_Enable,
		ZoomLevelActivateEventType_ToggleOnLightSwitch,
	};

	enum LockType
	{
		LockAlways,
		LockOnRadar,
		LockOnHeat,
		LockOnLaserPainted,
		LockNever,
		LockTypeCount,
	};

	enum WeaponFiringEvent
	{
		WeaponFiringEvent_Push,
		WeaponFiringEvent_Pop,
		WeaponFiringEvent_PrimaryStartedFiringCallback,
		WeaponFiringEvent_PrimaryFireCallback,
		WeaponFiringEvent_PrimaryFireReleaseCallback,
		WeaponFiringEvent_PrimaryFireShotSpawnedCallback,
		WeaponFiringEvent_PrimaryFireAutomaticBeginCallback,
		WeaponFiringEvent_PrimaryFireAutomaticEndCallback,
		WeaponFiringEvent_PrimaryStoppedFiringCallback,
		WeaponFiringEvent_ReloadPrimaryCallback,
		WeaponFiringEvent_ReloadPrimaryEndCallback,
		WeaponFiringEvent_BoltActionCallback,
		WeaponFiringEvent_BoltActionEndCallback,
		WeaponFiringEvent_DetonationSwitchCallback,
		WeaponFiringEvent_HoldAndReleaseReleaseCallback,
		WeaponFiringEvent_UpdateRequired,
	};

	enum FireLogicType
	{
		fltSingleFire,
		fltSingleFireWithBoltAction,
		fltAutomaticFire,
		fltBurstFire,
		fltHoldAndRelease,
		fltDetonatedFiring,
		fltCount,
	};

	enum ReloadLogic
	{
		rlWeaponSwitchCancelsUnfinishedReload,
		rlReloadUnaffectedByWeaponSwitch,
	};

	enum ReloadType
	{
		rtSingleBullet,
		rtMagazine,
		rtMagazineWithPossibleShorterReload,
	};

	typedef enum ClientState
    {
        ClientState_WaitingForStaticBundleLoad        = 0x0,
        ClientState_LoadProfileOptions                = 0x1,
        ClientState_Startup                            = 0x2,
        ClientState_StartServer                        = 0x3,
        ClientState_WaitingForLevel                    = 0x4,
        ClientState_StartLoadingLevel                = 0x5,
        ClientState_WaitingForLevelLoaded            = 0x6,
        ClientState_WaitingForLevelLink                = 0x7,
        ClientState_LevelLinked                        = 0x8,
        ClientState_WaitingUIIngame                    = 0x9,
        ClientState_WaitingForLoadingScreenUnLoad    = 0xA,
        ClientState_Ingame                            = 0xB,
        ClientState_ConnectToServerRequest            = 0xC,
        ClientState_ConnectToServer                    = 0xD,
        ClientState_WaitingForFrontEndUnLoad        = 0xE,
        ClientState_WaitingUILoading                = 0xF,
        ClientState_WaitingUIUnload                    = 0x10,
        ClientState_None                            = 0x11,
    } tClientState;


	enum PlayerBones 
	{
		Reference, //0
		AITrajectory, //1
		Trajectory, //2
		TrajectoryEnd, //3
		Hips, //4
		Spine, //5
		Spine1, //6
		Spine2, //7
		LeftShoulder, //8
		LeftArm, //9
		LeftArmRoll, //10
		LeftForeArm, //11
		LeftForeArmRoll, //12
		LeftForeArmRoll1, //13
		LeftHand, //14
		LeftHandMiddle0, //15
		LeftHandMiddle1, //16
		LeftHandMiddle2, //17
		LeftHandMiddle3, //18
		LeftHandMiddle4, //19
		LeftHandRing0, //20
		LeftHandRing1, //21
		LeftHandRing2, //22
		LeftHandRing3, //23
		LeftHandRing4, //24
		LeftHandPinky0, //25
		LeftHandPinky1, //26
		LeftHandPinky2, //27
		LeftHandPinky3, //28
		LeftHandPinky4, //29
		LeftHandIndex0, //30
		LeftHandIndex1, //31
		LeftHandIndex2, //32
		LeftHandIndex3, //33
		LeftHandIndex4, //34
		LeftHandThumb1, //35
		LeftHandThumb2, //36
		LeftHandThumb3, //37
		LeftHandThumb4, //38
		LeftForeArmCloth, //39
		LeftElbowRoll, //40
		LeftArmCloth, //41
		LeftShoulderPhys1, //42
		Neck, //43
		Neck1, //44
		Head, //45
		HeadEnd, //46
		Face, //47
		Offset_Jaw, //48
		Jaw, //49
		Offset_LeftLowerLip, //50
		LeftLowerLip, //51
		Offset_LowerLip, //52
		LowerLip, //53
		Offset_RightLowerLip, //54
		RightLowerLip, //55
		Offset_Tongue, //56
		Tongue, //57
		Offset_TongueTip, //58
		TongueTip, //59
		Offset_Chin, //60
		Chin, //61
		Offset_LeftEye, //62
		LeftEye, //63
		Offset_RightEye, //64
		RightEye, //65
		Offset_LeftUpCheek, //66
		LeftUpCheek, //67
		Offset_LeftUpInnerCheek, //68
		LeftUpInnerCheek, //69
		Offset_RightUpInnerCheek, //70
		RightUpInnerCheek, //71
		Offset_RightUpCheek, //72
		RightUpCheek, //73
		Offset_LeftCheek, //74
		LeftCheek, //75
		Offset_RightCheek, //76
		RightCheek, //77
		Offset_LeftMouth, //78
		LeftMouth, //79
		Offset_LeftUpperLip, //80
		LeftUpperLip, //81
		Offset_UpperLip, //82
		UpperLip, //83
		Offset_RightUpperLip, //84
		RightUpperLip, //85
		Offset_RightMouth, //86
		RightMouth, //87
		Offset_LeftUpEyelid, //88
		LeftUpEyelid, //89
		Offset_RightUpEyelid, //90
		RightUpEyelid, //91
		Offset_LeftLowEyelid, //92
		LeftLowEyelid, //93
		Offset_RightLowEyelid, //94
		RightLowEyelid, //95
		Offset_LeftInnerEyebrow, //96
		LeftInnerEyebrow, //97
		Offset_LeftOuterEyebrow, //98
		LeftOuterEyebrow, //99
		Offset_RightInnerEyebrow, //100
		RightInnerEyebrow, //101
		Offset_RightOuterEyebrow, //102
		RightOuterEyebrow, //103
		Offset_LeftNose, //104
		LeftNose, //105
		Offset_RightNose, //106
		RightNose, //107
		Offset_LeftCrease, //108
		LeftCrease, //109
		Offset_RightCrease, //110
		RightCrease, //111
		Offset_LeftMiddleEyebrow, //112
		LeftMiddleEyebrow, //113
		Offset_RightMiddleEyebrow, //114
		RightMiddleEyebrow, //115
		HeadCloth, //116
		Throat, //117
		Spine2Phys1, //118
		Spine2Cloth, //119
		RightShoulder, //120
		RightArm, //121
		RightArmRoll, //122
		RightForeArm, //123
		RightForeArmRoll, //124
		RightForeArmRoll1, //125
		RightHand, //126
		RightHandMiddle0, //127
		RightHandMiddle1, //128
		RightHandMiddle2, //129
		RightHandMiddle3, //130
		RightHandMiddle4, //131
		RightHandRing0, //132
		RightHandRing1, //133
		RightHandRing2, //134
		RightHandRing3, //135
		RightHandRing4, //136
		RightHandPinky0, //137
		RightHandPinky1, //138
		RightHandPinky2, //139
		RightHandPinky3, //140
		RightHandPinky4, //141
		RightHandIndex0, //142
		RightHandIndex1, //143
		RightHandIndex2, //144
		RightHandIndex3, //145
		RightHandIndex4, //146
		RightHandThumb1, //147
		RightHandThumb2, //148
		RightHandThumb3, //149
		RightHandThumb4, //150
		RightForeArmCloth, //151
		RightElbowRoll, //152
		RightArmCloth, //153
		RightShoulderPhys1, //154
		Wep_Root, //155
		Wep_Extra1, //156
		Wep_Trigger, //157
		Wep_Slide, //158
		Wep_Grenade1, //159
		Wep_Grenade2, //160
		Wep_Mag, //161
		Wep_Mag_Ammo, //162
		Wep_Physic1, //163
		Wep_Physic2, //164
		Wep_Physic3, //165
		Wep_Belt1, //166
		Wep_Belt2, //167
		Wep_Belt3, //168
		Wep_Belt4, //169
		Wep_Belt5, //170
		Wep_Bipod1, //171
		Wep_Bipod2, //172
		Wep_Bipod3, //173
		IK_Joint_LeftHand, //174
		IK_Joint_RightHand, //175
		Wep_Extra2, //176
		Wep_Extra3, //177
		Wep_Aim, //178
		LeftSpine1Phys1, //179
		RightSpine1Phys1, //180
		LeftUpLeg, //181
		LeftUpLegRoll, //182
		LeftLeg, //183
		LeftFoot, //184
		LeftToeBase, //185
		LeftToe, //186
		LeftLegCloth, //187
		LeftKneeRoll, //188
		LeftHipsRoll, //189
		LeftUpLegCloth, //190
		HipsCenterPhys, //191
		HipsCloth, //192
		LeftHipsFrontPhys, //193
		LeftHipsBackPhys, //194
		LeftHipsSidePhys, //195
		RightUpLeg, //196
		RightUpLegRoll, //197
		RightLeg, //198
		RightFoot, //199
		RightToeBase, //200
		RightToe, //201
		RightLegCloth, //202
		RightKneeRoll, //203
		RightHipsRoll, //204
		RightUpLegCloth, //205
		RightHipsFrontPhys, //206
		RightHipsBackPhys, //207
		RightHipsSidePhys, //208
		CameraBase, //209
		CameraJoint, //210
		Connect, //211
		ConnectEnd, //212
		totalBones
	};

	enum PhysicsEntityType
	{

		 PhysicsEntityTypeInvalid,                     // constant 0x0
		 PhysicsEntityTypeGroup,                     // constant 0x1
		 PhysicsEntityTypeRagdoll,                     // constant 0x2
		 PhysicsEntityTypeCharacter,                     // constant 0x3
		 PhysicsEntityTypeTerrain,                     // constant 0x4
		 PhysicsEntityTypeWater,                     // constant 0x5
		 PhysicsEntityTypeStatic,                     // constant 0x6
		 PhysicsEntityTypeDynamic,                     // constant 0x7
		 PhysicsEntityTypePhantom,                     // constant 0x8
		 PhysicsEntityTypePhantomEntity,                     // constant 0x9
		 PhysicsEntityTypeBreakable,                     // constant 0xA

	}; // PhysicsEntityType

	enum SimulationType
	{

		 SimulationTypeInvalid,                     // constant 0x0
		 SimulationTypeDynamic,                     // constant 0x1
		 SimulationTypeStatic,                     // constant 0x2
		 SimulationTypeClientDynamic,                     // constant 0x3
		 SimulationTypeLightDynamic,                     // constant 0x4
		 SimulationTypeKeyframed,                     // constant 0x5

	}; // SimulationType

	enum Flags
	{

		 IsDebrisPartBit,						// constant 0x10000
		 NoCollisionResponseCombined,			// constant 0x20000
		 IsBulletBit,							// constant 0x40000
		 IsVehicleBit,							// constant 0x80000
		 NoCharacterCollisionBit,               // constant 0x100000
		 LowestCollisionQualityBit,             // constant 0x200000
		 NoCollisionBit,						// constant 0x400000
		 ClientDestructible,                    // constant 0x800000
		 RBMeshBit,								// constant 0x1000000
		 IsForestBit,							// constant 0x2000000
		 IsWaterBit,							// constant 0x4000000
		 ClientSimulationAllowed,               // constant 0x8000000
		 FastDebrisBit,							// constant 0x10000000
		 ClientControlledBit,                   // constant 0x20000000
		 IsEntityPartBit,						// constant 0x40000000
		 HasMovableParts,						// constant 0x80000000
		 PhysicsEntityTypeShift,                // constant 0x0
		 SimulationTypeShift,					// constant 0x4
		 PhysicsEntityTypeMask,                 // constant 0xF
		 SimulationTypeMask,                    // constant 0xF0
		 FORCE_32_BIT,							// constant 0x7FFFFFFF

	};// Flags

	enum AnimationTransformMode
	{

		AnimationTransformMode_NotUsed,                   // constant 0x0
		AnimationTransformMode_MoveRendering,                     // constant 0x1
		AnimationTransformMode_MoveRenderingInterpolated,                     // constant 0x2
		AnimationTransformMode_Force,                     // constant 0x3
		AnimationTransformMode_MoveRenderingAndForce                     // constant 0x4

	}; // fb::AnimationTransformMode

	enum PhysicsManagerType
    {
        PmtClient = 0,
        PmtServer
    };

	enum WeaponAnimBaseSetEnum
	{

		  wabsRif,                     // constant 0x0
		  wabsPstl,                     // constant 0x1
		  wabsHgr,                     // constant 0x2
		  wabsAT,                     // constant 0x3
		  wabsShg,                     // constant 0x4
		  wabsLMG,                     // constant 0x5
		  wabsBag,                     // constant 0x6
		  wabsSnp,                     // constant 0x7
		  wabsCount,                     // constant 0x8
		  wabsNone                    // constant 0x9

	}; // fb::WeaponAnimBaseSetEnum

	enum QuickThrowTypeEnum
	{

		 QttHand,                   // constant 0x0
		 QttBag                    // constant 0x1

	}; // fb::QuickThrowTypeEnu

	
	
	};
	#endif

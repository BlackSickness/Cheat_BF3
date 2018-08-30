#ifndef _ScreenRenderer_H
#define _ScreenRenderer_H

//#include "../Frostbite_classes.h"

namespace fb
{


	class ScreenRenderer
	{
 
			class HudFxParams
			{
 
					enum Type
					{
 
							Crt,                    // constant 0x0
							CrtAnalogLink                     // constant 0x1
 
					}; // Type
 
					enum fb::ScreenRenderer::HudFxParams::Type type;                     // 0x0
					float segmentHeight;                     // 0x4
					/*const struct fb::ITexture*/void * originalBackBufferTexture;                     // 0x8
					/*const struct fb::ITexture*/void * noiseTexture;                     // 0xC
					bool noiseTextureFilter;                     // 0x10
					struct fb::Tuple2<float> noiseTextureSTScale;                     // 0x14
					struct fb::Tuple2<float> noiseTextureSTOffset;                     // 0x1C
/*					class eastl::vector<float,fb::eastl_arena_allocator> */void *noiseTextureIntensities;                     // 0x24
					/*const struct fb::ITexture*/void * scanLineTexture;                     // 0x34
					bool scanLineTextureFilter;                     // 0x38
					struct fb::Tuple2<float> scanLineTextureSTScale;                     // 0x3C
					struct fb::Tuple2<float> scanLineTextureSTOffset;                     // 0x44
					float scanLineStrength;                     // 0x4C
					LinearTransform colorMatrix;                     // 0x50
					struct Vec3 ghostStrengths;                     // 0x90
					struct Tuple2<float> ghost0Displacement;                     // 0xA0
					struct Tuple2<float> ghost1Displacement;                     // 0xA8
					struct Tuple2<float> ghost2Displacement;                     // 0xB0
					struct fb::Vec3 ghostSubValues;                     // 0xC0
					float rollingBarStrength;                     // 0xD0
					const struct fb::ITexture * rollingBarTexture;                     // 0xD4
					struct fb::Tuple2<float> rollingBarTextureSTScale;                     // 0xD8
					struct fb::Tuple2<float> rollingBarTextureSTOffset;                     // 0xE0
					/*class eastl::vector<float,fb::eastl_arena_allocator>*/DWORD interpolatedBrightnessValues;                     // 0xE8
					bool stencilMaskEnable;                     // 0xF8
					unsigned char stencilRef;                     // 0xF9
                                               
			}; // HudFxParams
 
			class LensChromaticAberrationParams
			{
 
					const struct fb::ITexture * blurredTexture;                     // 0x0
					struct fb::Vec2 blurCenter;                     // 0x4
					struct fb::Vec3 aberrationColor1;                     // 0x10
					struct fb::Vec3 aberrationColor2;                     // 0x20
					struct fb::Vec2 aberrationDisplacement1;                     // 0x30
					struct fb::Vec2 aberrationDisplacement2;                     // 0x38
					struct fb::Vec2 radialBlendDistanceCoefficients;                     // 0x40
					struct fb::Vec4 invColorScale;                     // 0x50
					class  LinearTransform colorTransform;                     // 0x60
 
			}; // LensChromaticAberrationParams
 
			class TonemapParams
			{
 
									const struct fb::ITexture * hdrTexture;                     // 0x0
					const struct fb::ITexture * bloomTexture;                     // 0x4
					struct fb::Vec3 bloomScale;                     // 0x10
					struct fb::Vec3 invGamma;                     // 0x20
					float colorScale;                     // 0x30
					struct fb::Tuple2<float> vignetteScale;                     // 0x34
					float vignetteExponent;                     // 0x3C
					struct fb::Vec4 vignetteColor;                     // 0x40
					class LinearTransform colorTransform;                     // 0x50
					unsigned int tonemapMethod;                     // 0x90
					float chromostereopsisScale;                     // 0x94
					float chromostereopsisOffset;                     // 0x98
					bool dofEnable;                     // 0x9C
					const struct fb::ITexture * blurTexture;                     // 0xA0
					const struct fb::ITexture * depthTexture;                     // 0xA4
					float nearPlane;                     // 0xA8
					float farPlane;                     // 0xAC
					float focusDistance;                     // 0xB0
					float nearFocusRange;                     // 0xB4
					float farFocusRange;                     // 0xB8
					float blurAdd;                     // 0xBC
					const struct fb::ITexture * filmGrainTexture;                     // 0xC0
					const struct fb::ITexture * colorGradingTexture;                     // 0xC4
					struct fb::Vec3 filmGrainColorScale;                     // 0xD0
					struct fb::Vec4 filmGrainTextureScaleAndOffset;                     // 0xE0
					bool filmGrainLinearFilteringEnable;                     // 0xF0
 
			}; // TonemapParams
 
			class DofParams
			{
 
					const struct fb::ITexture * mainTexture;                     // 0x0
					const struct fb::ITexture * blurTexture;                     // 0x4
					const struct fb::ITexture * depthTexture;                     // 0x8
					struct fb::Tuple2<float> vignetteBlurScale;                     // 0xC
					float vignetteBlurExponent;                     // 0x14
					float nearPlane;                     // 0x18
					float farPlane;                     // 0x1C
					float focusDistance;                     // 0x20
					float nearFocusRange;                     // 0x24
					float farFocusRange;                     // 0x28
					float blurAdd;                     // 0x2C
               
			}; // DofParams
 
			class ParticleShadowParams
			{
 
					class ShadowParams
					{
 
							const struct fb::ITexture * shadowTexture;                     // 0x0
							class LinearTransform shadowTransform;                     // 0x10
 
					}; // ShadowParams
 
					unsigned int shadowParamsCount;                     // 0x0
					/*struct fb::ScreenRenderer::ParticleShadowParams::ShadowParams[0x4] */ DWORD shadowParams;                     // 0x10
					class LinearTransform viewTransform;                     // 0x150
					const struct fb::ITexture * posAndSizeTexture;                     // 0x190
					const struct fb::ITexture * prevShadowTexture;                     // 0x194
					const struct fb::ITexture * prevPosAndSizeIndirectionTexture;                     // 0x198
					unsigned int width;                     // 0x19C
					unsigned int height;                     // 0x1A0
					unsigned int count;                     // 0x1A4
 
			}; // ParticleShadowParams
 
			class EnlightenShadowParams
			{
 
					class ShadowParams
					{
 
							const struct fb::ITexture * shadowTexture;                     // 0x0
							class LinearTransform shadowTransform;                     // 0x10
							float farPlane;                     // 0x50
                       
					}; // ShadowParams
 
					class LinearTransform viewTransform;                     // 0x0
					/*struct fb::ScreenRenderer::EnlightenShadowParams::ShadowParams[0x4]*/DWORD shadowParams;                     // 0x40
					const struct fb::ITexture * posTexture;                     // 0x1C0
					unsigned int shadowParamsCount;                     // 0x1C4
					unsigned int width;                     // 0x1C8
					unsigned int height;                     // 0x1CC
               
			}; // EnlightenShadowParams
 
			class UnprojectDepthBufferParams
			{
 
					const struct fb::ITexture * depthTexture;                     // 0x0
					float nearPlane;                     // 0x4
					float farPlane;                     // 0x8
					bool downsampleHalf;                     // 0xC
 
			}; // UnprojectDepthBufferParams
 
			class MotionBlurParams
			{
 
					const struct fb::ITexture * sourceTexture;                     // 0x0
					const struct fb::ITexture * velocityTexture;                     // 0x4
					const struct fb::ITexture * randomTexture;                     // 0x8
					float velocityScale;                     // 0xC
					float velocityMax;                     // 0x10
					float noiseScale;                     // 0x14
					unsigned int quality;                     // 0x18
					unsigned int maxSampleCount;                     // 0x1C
					bool stencilPassEnable;                     // 0x20
 
			}; // MotionBlurParams
 
			class VelocityFromZBufferParams
			{
 
					const struct fb::ITexture * depthTexture;                     // 0x0
					struct fb::Vec3 viewPosition;                     // 0x10
					class LinearTransform invViewProjectionMatrix;                     // 0x20
					class LinearTransform prevViewProjectionMatrix;                     // 0x60
					float scale;                     // 0xA0
					float nearPlane;                     // 0xA4
					float farPlane;                     // 0xA8
					float depthCutoff;                     // 0xAC
					float cutoffGradientScale;                     // 0xB0
 
			}; // VelocityFromZBufferParams
 
			enum HalfResZMethod
			{
 
				HalfResZMethod_Default,                   // constant 0x0
					HalfResZMethod_Default_Linear,                     // constant 0x1
					HalfResZMethod_Fat,          // constant 0x2
					 HalfResZMethod_Fat_Linear,                     // constant 0x3
					HalfResZMethod_Average,                     // constant 0x4
					 HalfResZMethod_Average_Linear                     // constant 0x5
 
			}; // HalfResZMethod
 
			class HalfResZParams
			{
 
					const struct fb::ITexture * zBufferTex;                     // 0x0
					enum fb::ScreenRenderer::HalfResZMethod method;                     // 0x4
					float nearPlane;                     // 0x8
					float farPlane;                     // 0xC
 
			}; // HalfResZParams
 
			class HalfResCompositeParams
			{
 
					const struct fb::ITexture * halfResTex;                     // 0x0
					const struct fb::ITexture * halfResZBufferTex;                     // 0x4
					const struct fb::ITexture * zBufferTex;                     // 0x8
 
			}; // HalfResCompositeParams
 
			class HorizonBasedAOFilterParams
			{
 
					const struct fb::ITexture * linearDepthTexture;                     // 0x0
					const struct fb::ITexture * randomDirTexture;                     // 0x4
					class LinearTransform worldViewMatrix;                     // 0x10
					unsigned int quality;                     // 0x50
					float stepCount;                     // 0x54
					float dirCount;                     // 0x58
					float radius;                     // 0x5C
					float angleBias;                     // 0x60
					float attenuation;                     // 0x64
					float contrast;                     // 0x68
					float maxScreenFraction;                     // 0x6C
					float angleClamping;                     // 0x70
					unsigned int randomTextureWidth;                     // 0x74
					float fovX;                     // 0x78
					float fovY;                     // 0x7C
					bool blendEnable;                     // 0x80
					bool vectorizedEnable;                     // 0x81
 
			}; // HorizonBasedAOFilterParams
 
			class HorizonBasedAOBlurParams
			{
 
					enum Type
					{
 
							Horizontal,                  // constant 0x0
							 Vertical                    // constant 0x1
 
					}; // Type
 
					Type type;                     // 0x0
					const struct fb::ITexture * sourceTexture;                     // 0x4
					const struct fb::ITexture * linearDepthTexture;                     // 0x8
					float blurRadius;                     // 0xC
					float sharpness;                     // 0x10
					float powerExponent;                     // 0x14
					bool blendEnable;                     // 0x18
					bool temporalFilterEnable;                     // 0x19
 
			}; // HorizonBasedAOBlurParams
 
			class HorizonBasedAOBlurCSParams
			{
 
					enum Type
					{
 
							Horizontal,                   // constant 0x0
							Vertical                   // constant 0x1
 
					}; // Type
 
					Type type;                     // 0x0
					ITexture * sourceTexture;                     // 0x4
					ITexture * linearDepthTexture;                     // 0x8
					float radius;                     // 0xC
					float sharpness;                     // 0x10
 
			}; // HorizonBasedAOBlurCSParams
 
			class HorizonBasedAONoiseDetectionParams
			{
 
					const struct fb::ITexture * rawAOTexture;                     // 0x0
					float threshold;                     // 0x4
 
			}; // HorizonBasedAONoiseDetectionParams
 
			class HorizonBasedAOBlurCSCompositeParams
			{
 
					const struct fb::ITexture * sourceTexture;                     // 0x0
					float powerExponent;                     // 0x4
					bool blendEnable;                     // 0x8
 
			}; // HorizonBasedAOBlurCSCompositeParams
 
			class HorizonBasedAOBlurCSCompositeTemporalParams
			{
 
			/*		class fb::ScreenRenderer::HorizonBasedAOBlurCSCompositeParams // Inherited class at offset 0x0
					{
 
							const struct fb::ITexture * sourceTexture;                     // 0x0
							float powerExponent;                     // 0x4
							bool blendEnable;                     // 0x8
 
					}; // fb::ScreenRenderer::HorizonBasedAOBlurCSCompositeParams*/
 
					const struct fb::ITexture * prevAOZTexture;                     // 0xC
					const struct fb::ITexture * prevNTexture;                     // 0x10
					const struct fb::ITexture * hardwareDepthTexture;                     // 0x14
					const struct fb::ITexture * halfResMaskTexture;                     // 0x18
					float threshold;                     // 0x1C
					unsigned int maxNumFrames;                     // 0x20
					unsigned int debugMode;                     // 0x24
					class LinearTransform curInvViewProjectionMatrix;                     // 0x30
					class LinearTransform curViewMatrix;                     // 0x70
					class LinearTransform prevViewProjectionMatrix;                     // 0xB0
					class LinearTransform prevViewMatrix;                     // 0xF0
					struct fb::Vec3 curViewTranslation;                     // 0x130
					struct fb::Vec3 prevViewTranslation;                     // 0x140
 
			}; // HorizonBasedAOBlurCSCompositeTemporalParams
 
			class SSAOFilterParams
			{
 
					const struct fb::ITexture * linearDepthTexture;                     // 0x0
					const struct fb::ITexture * normalTexture;                     // 0x4
					const struct fb::ITexture * randomDirTexture;                     // 0x8
					float radiusOuter;                     // 0xC
					float radiusInner;                     // 0x10
					float maxDistanceInner;                     // 0x14
					float maxDistanceOuter;                     // 0x18
					class LinearTransform worldViewMatrix;                     // 0x20
					class LinearTransform projectionMatrix;                     // 0x60
					class LinearTransform invProjectionMatrix;                     // 0xA0
					float nearPlane;                     // 0xE0
					float farPlane;                     // 0xE4
 
			}; // SSAOFilterParams
 
			class SSAOBlurParams
			{
 
									enum Type
					{
 
							Horizontal ,                   // constant 0x0
							Vertical                   // constant 0x1
 
					}; // Type
 
					enum fb::ScreenRenderer::SSAOBlurParams::Type type;                     // 0x0
					const struct fb::ITexture * sourceTexture;                     // 0x4
					const struct fb::ITexture * linearDepthTexture;                     // 0x8
					bool blendEnable;                     // 0xC
 
			}; // SSAOBlurParams
 
			class ViewFxParams
			{
 
					/*const class fb::ViewFxData */void * data;                     // 0x0
					const struct fb::ITexture * mainTexture;                     // 0x4
					const struct fb::ITexture * halfResTexture;                     // 0x8
					const struct fb::ITexture * flirTexture;                     // 0xC
					/*struct fb::IRenderTargetView */ void * mainTarget;                     // 0x10
					/*struct fb::IRenderTargetView */ void * halfResTarget;                     // 0x14
					/*struct fb::IRenderTargetView */ void * flirTarget;                     // 0x18
 
			}; // ViewFxParams
 
			class RgbSeperationParams
			{
 
					const struct fb::ITexture * mainTexture;                     // 0x0
					const struct fb::ITexture * amplitudeTexture;                     // 0x4
					float time;                     // 0x8
					struct fb::Vec3 frequency;                     // 0x10
					struct fb::Vec3 amplitude;                     // 0x20
					struct fb::Vec3 ydifference;                     // 0x30
               
			}; // RgbSeperationParams
 
			class DistortParams
			{
 
					const struct fb::ITexture * mainTexture;                     // 0x0
					const struct fb::ITexture * noiseTexture;                     // 0x4
					float time;                     // 0x8
					float distortion;                     // 0xC
					float xPower;                     // 0x10
					float yPower;                     // 0x14
					float power;                     // 0x18
					float highlightThreshold;                     // 0x1C
					float highlight;                     // 0x20
					float rshift;                     // 0x24
					float gshift;                     // 0x28
					float bshift;                     // 0x2C
 
			}; // DistortParams
 
			enum ShaderParam
			{
 
					 SpInvPixelSize,                     // constant 0x0
					 SpRadialBlurScales,                     // constant 0x1
					 SpRadialBlurCenter,                     // constant 0x2
					 SpRadialBlendCenter,                     // constant 0x3
					 SpRadialBlendScale,                     // constant 0x4
					 SpColor,                     // constant 0x5
					 SpMaexture,                     // constant 0x6
					 SpMaexture2,                     // constant 0x7
					 SpMaexture3,                     // constant 0x8
					 SpMaexture4,                     // constant 0x9
					 SpMaexture5,                     // constant 0xA
					 SpMaexture6,                     // constant 0xB
					 SpMaexture7,                     // constant 0xC
					 SpMaexture8,                     // constant 0xD
					 SpMaextureMsaa,                     // constant 0xE
					 SpMaextureU,                     // constant 0xF
					 SpMipmap,                     // constant 0x10
					 SpMipLevelSource,                     // constant 0x11
					 SpLuminanceVector,                     // constant 0x12
					 SpColorMatrix0,                     // constant 0x13
					 SpColorMatrix1,                     // constant 0x14
					 SpColorMatrix2,                     // constant 0x15
					 SpColorGradingTexture,                     // constant 0x16
					 SpInvGamma,                     // constant 0x17
					 SpExponent,                     // constant 0x18
					 SpColorScale,                     // constant 0x19
					 SpBloomScale,                     // constant 0x1A
					 SpTonemapBloomTexture,                     // constant 0x1B
					 SpDofBlurTexture,                     // constant 0x1C
					 SpDepthTexture,                     // constant 0x1D
					 SpDepthTextureMsaa,                     // constant 0x1E
					 SpDepthScaleFactors,                     // constant 0x1F
					 SpDofParams,                     // constant 0x20
					 SpInvTexelSize,                     // constant 0x21
					 SpBackbufferTexture,                     // constant 0x22
					 SpVelocityTexture,                     // constant 0x23
					 SpYTexture,                     // constant 0x24
					 SpCrTexture,                     // constant 0x25
					 SpCbTexture,                     // constant 0x26
					 SpATexture,                     // constant 0x27
					 SpZBuffer,                     // constant 0x28
					 SpZBufferHalfRes,                     // constant 0x29
					 SpTileCategory,                     // constant 0x2A
					 SpPixelSize,                     // constant 0x2B
					 SpDepthFactors,                     // constant 0x2C
					 SpFadeParams,                     // constant 0x2D
					 SpSeperableKernelWeights,                     // constant 0x2E
					 SpCombineTextureWeights,                     // constant 0x2F
					 SpSampleCount,                     // constant 0x30
					 SpFilterWidth,                     // constant 0x31
					 SpPoissonRadialBlurConstants,                     // constant 0x32
					 SpBlendFactor,                     // constant 0x33
					 SpGhostStrengths,                     // constant 0x34
					 SpGhost0Displacement,                     // constant 0x35
					 SpGhost1Displacement,                     // constant 0x36
					 SpGhost2Displacement,                     // constant 0x37
					 SpGhostSubValues,                     // constant 0x38
					 SpAberrationColor0,                     // constant 0x39
					 SpAberrationColor1,                     // constant 0x3A
					 SpAberrationColor2,                     // constant 0x3B
					 SpAberrationDisplacement1,                     // constant 0x3C
					 SpAberrationDisplacement2,                     // constant 0x3D
					 SpRadialBlendDistanceCoefficients,                     // constant 0x3E
					 SpVignetteParams,                     // constant 0x3F
					 SpVignetteColor,                     // constant 0x40
					 SpShadowTransform0,                     // constant 0x41
					 SpShadowTransform1,                     // constant 0x42
					 SpShadowTransform2,                     // constant 0x43
					 SpShadowTransform3,                     // constant 0x44
					 SpViewTransform,                     // constant 0x45
					 SpShadowFarPlane0,                     // constant 0x46
					 SpShadowFarPlane1,                     // constant 0x47
					 SpShadowFarPlane2,                     // constant 0x48
					 SpShadowFarPlane3,                     // constant 0x49
					 SpHalfResZPixelOffset,                     // constant 0x4A
					 SpDownsampleQuarterZOffset,                     // constant 0x4B
					 SpFilmGraexture,                     // constant 0x4C
					 SpFilmGraextureScaleAndOffset,                     // constant 0x4D
					 SpFilmGrainColorScale,                     // constant 0x4E
					 SpChromostereopsisParams,                     // constant 0x4F
					 SpPosAndSizeTexture,                     // constant 0x50
					 SpPrevShadowTexture,                     // constant 0x51
					 SpPrevShadowIndirectionTexture,                     // constant 0x52
					 SpShadowTexture,                     // constant 0x53
					 SpShadowTexture0,                     // constant 0x54
					 SpShadowTexture1,                     // constant 0x55
					 SpShadowTexture2,                     // constant 0x56
					 SpShadowTextureArray,                     // constant 0x57
					 SpDistortionParams0,                     // constant 0x58
					 SpDistortionParams1,                     // constant 0x59
					 SpDistortionParams2,                     // constant 0x5A
					 SpUniformParams0,                     // constant 0x5B
					 SpUniformParams1,                     // constant 0x5C
					 SpUniformParams2,                     // constant 0x5D
					 SpUniformParams3,                     // constant 0x5E
					 SpRandomTexture,                     // constant 0x5F
					 SpNormalTexture,                     // constant 0x60
					 SpAOTexture,                     // constant 0x61
					 SpGeometryTexture2,                     // constant 0x62
					 SpGeometryTexture3,                     // constant 0x63
					 SpLightTexture1,                     // constant 0x64
					 SpLightTexture2,                     // constant 0x65
					 SpInvViewProjectionMatrix,                     // constant 0x66
					 SpPrevViewProjectionMatrix,                     // constant 0x67
					 SpMotionBlurParams,                     // constant 0x68
					 SpCameraPosAndDepthCutoff,                     // constant 0x69
					 SpCutoffGradientScale,                     // constant 0x6A
					 SpRcpFrame,                     // constant 0x6B
					 SpRcpFrameOpt,                     // constant 0x6C
					 SpRcpFrameOpt2,                     // constant 0x6D
					 SpFxaaXenonConstDir,                     // constant 0x6E
					 SpSsaoBInvResolution,                     // constant 0x6F
					 SpSsaoBBlurRadius,                     // constant 0x70
					 SpSsaoBBlurFalloff,                     // constant 0x71
					 SpSsaoBSharpness,                     // constant 0x72
					 SpSsaoPower,                     // constant 0x73
					 SpSsaoScale,                     // constant 0x74
					 SpViewMatrix,                     // constant 0x75
					 SpProjectionMatrix,                     // constant 0x76
					 SpOcclusionSphereScale,                     // constant 0x77
					 SpRandomTextureTileFactor,                     // constant 0x78
					 SpKernelSize,                     // constant 0x79
					 SpMaxOcclusionDistance,                     // constant 0x7A
					 SpSSAORadius,                     // constant 0x7B
					 SpSSAOMaxDistance,                     // constant 0x7C
					 SpSSAOSamplePos1,                     // constant 0x7D
					 SpSSAOSamplePos2,                     // constant 0x7E
					 SpSSAOSamplePos3,                     // constant 0x7F
					 SpCount                    // constant 0x80
 
			}; // ShaderParam
 
			class Vertex2d
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
					struct fb::Color32 color;                     // 0x8
					struct fb::Tuple2<float> texCoord;                     // 0xC
               
			}; // Vertex2d
 
			class Vertex3d
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
					struct fb::Color32 color;                     // 0x8
					/*struct fb::Tuple3<float>*/DWORD texCoord;                     // 0xC
               
			}; // Vertex3d
 
			class Vertex4d
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
					struct fb::Color32 color;                     // 0x8
					/*struct fb::Tuple3<float>*/DWORD  texCoord;                     // 0xC
                               
			}; // Vertex4d
 
			class VertexTex2d
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
					struct fb::Tuple2<float> texCoord;                     // 0x8
               
			}; // VertexTex2d
 
			class VertexTex4d
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
					/*struct fb::Tuple4<float>*/DWORD  texCoord;                     // 0x8
               
			}; // VertexTex4d
 
			class VertexTex3d
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
							/*struct fb::Tuple3<float>*/DWORD  texCoord;                     // 0x8
                               
			}; // VertexTex3d
 
			class VertexHudFx
			{
 
					struct fb::Tuple2<float> pos;                     // 0x0
					struct fb::Tuple2<float> texCoord0;                     // 0x8
					struct fb::Tuple2<float> texCoord1;                     // 0x10
					struct fb::Tuple2<float> texCoord2;                     // 0x18
					struct fb::Tuple2<float> texCoord3;                     // 0x20
					struct fb::Tuple2<float> interpolant0;                     // 0x28
                               
			}; // VertexHudFx
 
			unsigned intm_params;                     // 0x0  [0x80]
			struct fb::GeometryDeclarationDesc m_geomDescColor3d;                     // 0x200
			struct fb::GeometryDeclarationDesc m_geomDescColor2d;                     // 0x24C
			struct fb::GeometryDeclarationDesc m_geomDescTex2d;                     // 0x298
			struct fb::GeometryDeclarationDesc m_geomDescTex3d;                     // 0x2E4
			struct fb::GeometryDeclarationDesc m_geomDescTex4d;                     // 0x330
			struct fb::GeometryDeclarationDesc m_geomDescHudFx;                     // 0x37C
			struct fb::Tuple2<float> m_targetSize;                     // 0x3C8
			struct fb::Vec4 m_invPixelSize;                     // 0x3D0
			struct fb::Vec4 m_viewport;                     // 0x3E0
			struct fb::IStateRenderer * m_stateRenderer;                     // 0x3F0
			/*class fb::SmartComRef<ID3D11Buffer>*/ void* m_constantBufferHbaoComposite;                     // 0x3F4
			/*class fb::SmartComRef<ID3D11Buffer>*/ void* m_constantBufferHbaoTemporalFilter;                     // 0x3F8
			/*class fb::SmartComRef<ID3D11Buffer>*/ void* m_constantBufferHbaoNoiseDetection;                     // 0x3FC
			/*class fb::SmartComRef<ID3D11SamplerState>*/void* m_pointClampSamplerState;                     // 0x400
			/*class fb::SmartComRef<ID3D11SamplerState>*/ void* m_samplerStateHbaoTemporalFilterAOZ;                     // 0x404
			/*class fb::SmartComRef<ID3D11SamplerState>*/ void* m_samplerStateHbaoTemporalFilterN;                     // 0x408
			/*class fb::SmartComRef<ID3D11BlendState>*/  void* m_blendStateHbaoTemporalFilter;                     // 0x40C
               
	};


};

#endif
#ifndef _MESH_H
#define _MESH_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/RefCountBase.h"
#include "FB SDK/Guid.h"
#include "FB SDK/ArrayTypeInfo.h"

namespace fb
{
		class MeshData
	{

		MemoryArena * arena;                     // 0x0
		/*struct fb::IRenderBuffer * */void* vertexBuffer;                     // 0x4
		/*struct fb::IRenderBuffer * */void *indexBuffer;                     // 0x8
		void * vertexData;                     // 0xC
		void * indexData;                     // 0x10

	}; // fb::MeshData

	class MeshLayout // Inherited class at offset 0x0
	{

		enum Flags
		{

			 IsBaseLod,                   // constant 0x1
			 StreamingEnable,                     // constant 0x40
			 StreamInstancingEnable,                     // constant 0x10
			 VertexAnimationEnable,                     // constant 0x80
			 IsDataAvailable,                     // constant 0x20000000

		}; // Flags

		/*class fb::SmallEnum<enum fb::MeshType,unsigned int>*/void* m_type;                     // 0x0
		unsigned int m_subsetCount;                     // 0x4
	/*	union fb::RelocPtr<fb::MeshSubset>*/void* m_subsets;                     // 0x8
	/*	struct fb::RelocArray<unsigned char>[0x4]*/void*  m_categorySubsetIndices;                     // 0x10
		unsigned int m_flags;                     // 0x40
	/*	class fb::SmallEnum<enum fb::IndexBufferFormat,unsigned int>*/void*  m_indexBufferFormat;                     // 0x44
		unsigned int m_indexDataSize;                     // 0x48
		unsigned int m_vertexDataSize;                     // 0x4C
		unsigned int m_edgePartitionBufferSize;                     // 0x50
	/*	struct fb::Guid */void*m_dataChunkId;                     // 0x54
		unsigned int m_auxVertexIndexDataOffset;                     // 0x64
	/*	union fb::RelocPtr<unsigned char>*/void*  m_embeddedEdgeData;                     // 0x68
	/*	union fb::RelocPtr<char const > */void* m_shaderDebugName;                     // 0x70
	/*	union fb::RelocPtr<char const >*/void*  m_name;                     // 0x78
	/*	union fb::RelocPtr<char const > */void* m_shortName;                     // 0x80
		unsigned int m_nameHash;                     // 0x88
	/*	union fb::RelocPtr<fb::MeshData> */void* m_data;                     // 0x8C
		unsigned int m_boneCount;                     // 0x94
	/*	union fb::RelocPtr<unsigned int>*/void*  m_boneIndexArray;                     // 0x98
	/*	union fb::RelocPtr<unsigned int>*/void*  m_boneShortNameArray;                     // 0xA0
		unsigned int m_partCount;                     // 0x94
	/*	union fb::RelocPtr<fb::AxisAlignedBox>*/void*  m_partBoundingBoxes;                     // 0x98
	/*	union fb::RelocPtr<fb::LinearTransform> */void* m_partTransforms;                     // 0xA0
	/*	union fb::RelocPtr<fb::RelocNonPod<eastl::bitset<192> > > */void* m_subsetPartIndices;                     // 0xA8
		
	}; // fb::MeshLayout

	class MeshSetLayout
	{
		enum Flags
		{

			 StreamingEnable,                     // constant 0x1
			 HalfResRenderEnable,                     // constant 0x2
			 CastDynamicEnvmapEnable,                     // constant 0x4
			 CastPlanarReflectionEnable,                     // constant 0x8
			 StreamInstancingEnable,                     // constant 0x10
			 MovableParts,                     // constant 0x20
			 VertexAnimationEnable                    // constant 0x80

		}; // Flags

		/*class fb::SmallEnum<enum fb::MeshType,unsigned int>*/void* meshType;                     // 0x0
		unsigned int flags;                     // 0x4
		unsigned int lodCount;                     // 0x8
		unsigned int totalSubsetCount;                     // 0xC
		AxisAlignedBox boundingBox;                     // 0x10
/*		RelocPtr<fb::Mesh> */void*lods[0x5];                     // 0x30
/*		RelocPtr<char const > */void*name;                     // 0x58
	/*	RelocPtr<char const > */void*shortName;                     // 0x60
		unsigned int nameHash;                     // 0x68
	
	}; // fb::MeshSetLayout

	class MeshSet
	{
		/*
		class fb::TntObject<fb::IResourceObject> // Inherited class at offset 0x0
		{

			class fb::IResourceObject // Inherited class at offset 0x0
			{

				class fb::ITypedObject // Inherited class at offset 0x0
				{

					virtual const class fb::TypeInfo * getType();	// V: 0x0

				}; // fb::ITypedObject

				virtual int addRef();	// V: 0x4
				virtual int release();	// V: 0x8
						
			}; // fb::IResourceObject

							enum <unnamed-tag>
			{

				int kMemberType;                     // constant 0x1
				int kMemberTypeCategory;                     // constant 0x1
				int kMemberTypeCode;                     // constant 0x3
				int kMemberInfoOtherFlags;                     // constant 0x0

			}; // <unnamed-tag>

			unsigned int m_refCnt;                     // 0x4
		
		}; // fb::TntObject<fb::IResourceObject>
		*/
		PAD (0x8);
		class fb::MemoryArena * m_arena;                     // 0x8
		unsigned short m_handle;                     // 0xC
		MeshSetLayout * m_layout;                     // 0x10
		void * m_rsxData;                     // 0x14
		unsigned int m_cellBlockSize;                     // 0x18
		unsigned char m_minAvailableLodIndex;                     // 0x1C
		float m_lodScale;                     // 0x20
		float m_cullScale;                     // 0x24
/*		struct fb::MeshSubsetGeometryDecls **/void* m_geomDeclArray;                     // 0x28
		struct fb::MeshData m_meshData[0x5];                     // 0x30
		bool m_postLoaded;                     // 0xD0
		unsigned char m_lodGroupBuffer[0x60];                     // 0xD4
		Guid m_meshAssetGuid;                     // 0x134
		Guid m_meshLodGroupGuid;                     // 0x144
		
	}; // fb::MeshSet

	class Mesh
		:public MeshLayout // Inherited class at offset 0x0
	{
	public:
											
	}; // fb::Mesh
	
	class MeshMaterial
		:public DataContainer // Inherited class at offset 0x0
	{
		public:
		

		/*class fb::CtrRefBase*/void* m_shaderInstance;                     // 0x10
		/*struct fb::SurfaceShaderInstanceDataStruct*/void* m_shader;                     // 0x14
		/*class fb::Array<fb::MeshSourceMaterial> */void*m_materials;                     // 0x28
		Array<MeshDestructionMaterial> m_destructionMaterials;                     // 0x2C
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::MeshMaterial

	class MeshMaterialVariation
		:public DataContainer // Inherited class at offset 0x0
	{
	public:
		
		

		/*struct fb::SurfaceShaderInstanceDataStruct */void*m_shader;                     // 0x10
		CtrRefBase m_material;                     // 0x24
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::MeshMaterialVariation

	class MeshVariationSet
		:public RefCountBase // Inherited class at offset 0x0
	{
		class Material
		{
			/*class fb::SurfaceShaderInstance*/void* shader;// 0x0
			MeshMaterial * material;                     // 0x14
			MeshMaterialVariation * materialVariation;   // 0x18
						
		}; // Material

		struct fb::MeshVariationSet::Material * m_materials; // 0x8
		unsigned int m_materialCount;                     // 0xC
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
	}; // fb::MeshVariationSet

	class MeshModel
	{

		enum StreamingOption
		{

			 StreamingEnable,                    // constant 0x1
			 StreamingDisable                    // constant 0x0

		}; // StreamingOption

		/*class fb::ResourceProxy<fb::MeshSet,1>*/void* m_meshSet;                     // 0x0
		SmartRef<fb::MeshVariationSet const > m_meshVariationSet;                     // 0x8
		/*class eastl::bitset<192>*/void* m_partsEnabled;                     // 0xC
		unsigned short m_instanceStreamHandle;                     // 0x24
		unsigned char m_instanceStreamHandleDirty;                     // 0x26
		unsigned char m_partCount;                     // 0x27
		bool m_streamingEnable;                     // 0x28
		bool m_streamingPosUpdated;                     // 0x29
		
	}; // fb::MeshModel

	class MeshSourceMaterial
	{

		class ArrayTypeInfo
			:public fb::ArrayTypeInfo
		{			
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t
			:public fb::ArrayTypeInfo
		{		
		}; // ArrayTypeInfo_t

		
		Vec3 m_debugColor;                     // 0x0
		String m_name;                     // 0x10
	}; // fb::MeshSourceMaterial


	class FileRef
		:public String // Inherited class at offset 0x0
	{			
	}; // fb::FileRef

	class RadiosityMaterial
		:public DataContainer // Inherited class at offset 0x0
	{
	
		Vec3 m_color;                     // 0x10
		String m_name;                     // 0x20
		bool m_emissive;                     // 0x24
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::RadiosityMaterial

	class MeshAsset // Inherited class at offset 0x0
		:public Asset // Inherited class at offset 0x0
	{
		CtrRefBase m_lodGroup;                     // 0x30
		float m_lodScale;                     // 0x34
		float m_cullScale;                     // 0x38
		unsigned int m_nameHash;                     // 0x3C
		EnlightenType m_enlightenType;                     // 0x40
		RefArray<MeshMaterial> m_materials;                     // 0x44
		bool m_occluderHighPriority;                     // 0x48
		bool m_streamingEnable;                     // 0x49
		bool m_occluderMeshEnable;                     // 0x4A
		FileRef m_sourceFile;                     // 0x4C
		String m_rootNode;                     // 0x50
		unsigned int m_lodCount;                     // 0x54
		unsigned int m_skipLods;                     // 0x58
		int m_skipLodsXenon;                     // 0x5C
		int m_skipLodsPs3;                     // 0x60
		bool m_useMostDetailedLodOnly;                     // 0x64
		bool m_onDemandLoaded;                     // 0x65
		Array<String> m_keepZOnlyVertexElements;                     // 0x68
		Array<String> m_excludeZOnlyMaterials;                     // 0x6C
		bool m_zOnlyMesh;                     // 0x70
		bool m_castShadowEnable;                     // 0x71
		bool m_castDynamicEnvmapEnable;                     // 0x72
		bool m_castPlanarReflectionEnable;                     // 0x73
		bool m_halfResRenderEnable;                     // 0x74
		bool m_streamInstancingEnable;                     // 0x75
		bool m_compressPositionsEnable;                     // 0x76
		bool m_manualDrawOrderEnable;                     // 0x77
		bool m_vertexAnimationEnable;                     // 0x78
		int m_streamableLods;                     // 0x7C
		int m_streamableLodsXenon;                     // 0x80
		int m_streamableLodsPs3;                     // 0x84
		bool m_tangentSpaceBasisEnable;                     // 0x88
		bool m_occluderDoubleSided;                     // 0x89
		String m_occluderMeshNode;                     // 0x8C
		bool m_ps3EdgeEnable;                     // 0x90
		bool m_ps3EdgeScoreErrorWorkaroundEnable;                     // 0x91
		bool m_subMaterialEnable;                     // 0x92
		bool m_destructionMaterialEnable;                     // 0x93
		enum fb::EnlightenResolution m_enlightenResolution;                     // 0x94
		RefArray<fb::RadiosityMaterial> m_radiosityMaterials;                     // 0x98
		bool m_obsolete;                     // 0x9C
		String m_sandboxName;                     // 0xA0
		CtrRefBase m_sourceModel;                     // 0xA4
		CtrRefBase m_sourceDataScene;                     // 0xA8
		Guid m_sourceModelHash;                     // 0xAC
		Guid m_sourceDataSceneHash;                     // 0xBC
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::MeshAsset

	class SkinnedMeshAsset
		:public MeshAsset //inefited at 0x0
	{

		Vec3 m_boundingBoxPositionOffset;                     // 0xD0
		Vec3 m_boundingBoxSizeOffset;                     // 0xE0
		CtrRefBase m_skeleton;                     // 0xF0
		virtual void * __vecDelDtor(unsigned int);	// V: 0x4

	}; // fb::SkinnedMeshAsset


};

#endif
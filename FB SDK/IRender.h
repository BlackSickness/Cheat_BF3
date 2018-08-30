#ifndef _IRender_H
#define _IRender_H


#include "Frostbite_Classes.h"

namespace fb
{
	class IRenderResource :public  IResourceObject // Inherited class at offset 0x0
	{

		
		enum RenderResourceUsage
		{

			kMemberType,                 // constant 0x1
			kMemberTypeCategory,                     // constant 0x1
				kMemberTypeCode,                     // constant 0x3
			kMemberInfoOtherFlags                     // constant 0x0

		}; // <unnamed-tag>

		virtual const char * getDebugName();	// V: 0xC
		virtual unsigned int getMemorySize();	// V: 0x10
		virtual unsigned int getMemoryFlags();	// V: 0x14
		virtual enum RenderResourceUsage getUsage();	// V: 0x18
				
	}; // fb::IRenderResource

	class ITexture :public  IRenderResource // Inherited class at offset 0x0
	{

	

		enum 
		{

			kMemberType,                    // constant 0x1
			kMemberTypeCategory,                    // constant 0x1
			kMemberTypeCode,                 // constant 0x3
			kMemberInfoOtherFlags                   // constant 0x0

		}; // <unnamed-tag>

		//virtual enum fb::TextureFormat getFormat();	// V: 0x1C
		//virtual enum fb::TextureType getTextureType();	// V: 0x20
		virtual void *func0();
		virtual void *func1();
		virtual unsigned int getWidth();	// V: 0x24
		virtual unsigned int getHeight();	// V: 0x28
		virtual unsigned int getDepth();	// V: 0x2C
		virtual unsigned int getMipmapCount();	// V: 0x30
		virtual unsigned int getSampleCount();	// V: 0x34
		virtual bool isSrgbGamma();	// V: 0x38
		//virtual const struct fb::TextureHeader * getStreamingHeader();	// V: 0x3C
		virtual void *func3();
		virtual const struct ITexture * * getStreamingSourceSlices();	// V: 0x40
		virtual unsigned short getHandle();	// V: 0x44
		virtual void setHandle(unsigned short);	// V: 0x48
		
	}; // fb::ITexture

	class GeometryDeclarationDesc
	{

		enum 
		{

			MaxElementCount,                   // constant 0x10
			MaxStreamCount                   // constant 0x4

		}; // <unnamed-tag>

		class Element
		{

			/*class fb::SmallEnum<enum fb::VertexElementUsage,unsigned char>*/void* usage;                     // 0x0
			/*class fb::SmallEnum<enum fb::VertexElementFormat,unsigned char>*/void*  format;                     // 0x1
			unsigned char offset;                     // 0x2
			unsigned char streamIndex;                     // 0x3

		}; // Element

		class Stream
		{

			unsigned char stride;                     // 0x0
			/*class fb::SmallEnum<enum fb::VertexElementClassification,unsigned char>*/void*  classification;                     // 0x1

		}; // Stream

		struct Element elements;                     // 0x0 [0x10]
		struct Stream  streams;                     // 0x40 [0x4]
		unsigned char elementCount;                     // 0x48
		unsigned char streamCount;                     // 0x49
		unsigned char  padding_;                     // 0x4A  [0x2]

	}; // fb::GeometryDeclarationDesc

	class ShaderProgramPermutationInfo
	{

		unsigned int psMask;                     // 0x0
		unsigned int vsMask;                     // 0x4
		unsigned int gsMask;                     // 0x8
		unsigned int csMask;                     // 0xC

	}; // fb::ShaderProgramPermutationInfo


};

#endif
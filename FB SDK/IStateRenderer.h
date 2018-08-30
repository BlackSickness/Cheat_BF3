#ifndef _IStateRenderer_H
#define _IStateRenderer_H

namespace fb
{

	
	class IStateRenderer
	{

		virtual void setShaderProgram(enum fb::ShaderProgram, const struct fb::ShaderProgramPermutationInfo &);	// V: 0x0
		virtual void setShaderProgram(enum fb::ShaderProgram);	// V: 0x4
		virtual void setAlphaBlendEnable(bool);	// V: 0x8
		virtual void setBlendMode(enum fb::RenderBlendMode, enum fb::RenderBlendMode, enum fb::RenderBlendMode, enum fb::RenderBlendMode);	// V: 0xC
		virtual void setBlendOp(enum fb::RenderBlendOp, enum fb::RenderBlendOp);	// V: 0x10
		virtual void setDepthMode(enum fb::RenderDepthMode);	// V: 0x14
		virtual void setStencilState(/*const struct fb::StencilState &*/void*);	// V: 0x18
		virtual void setColorWriteMask(unsigned int);	// V: 0x1C
		virtual void setCullMode(enum fb::RenderCullMode);	// V: 0x20
		virtual void setFillMode(enum fb::RenderFillMode);	// V: 0x24
		virtual void setVertexParameter(unsigned int, const struct fb::ITexture *);	// V: 0x28
		virtual void setVertexParameter(unsigned int, const class LinearTransform &);	// V: 0x2C
		virtual void setVertexParameter(unsigned int, const void *, unsigned int);	// V: 0x30
		virtual void setVertexParameter(unsigned int, const union __m128 &);	// V: 0x34
		virtual void setVertexParameter(unsigned int, const struct fb::Vec4 &);	// V: 0x38
		virtual void setVertexParameter(unsigned int, bool);	// V: 0x3C
		virtual void setVertexParameter(unsigned int, int);	// V: 0x40
		virtual void setVertexParameter(unsigned int, float);	// V: 0x44
		virtual void setPixelParameter(unsigned int, const struct fb::ITexture *, /*const struct fb::SamplerState &*/void*);	// V: 0x48
		virtual void setPixelParameter(unsigned int, const class LinearTransform  &);	// V: 0x4C
		virtual void setPixelParameter(unsigned int, const void *, unsigned int);	// V: 0x50
		virtual void setPixelParameter(unsigned int, const union __m128 &);	// V: 0x54
		virtual void setPixelParameter(unsigned int, const struct fb::Vec4 &);	// V: 0x58
		virtual void setPixelParameter(unsigned int, bool);	// V: 0x5C
		virtual void setPixelParameter(unsigned int, int);	// V: 0x60
		virtual void setPixelParameter(unsigned int, float);	// V: 0x64
		virtual void drawVertices(/*const struct fb::NonIndexedDrawCallParams &*/void*);	// V: 0x68
		virtual void drawVertices(const char *, enum fb::PrimitiveType,/* const struct fb::GeometryDeclarationDesc &*/void*, unsigned int, unsigned int, unsigned int, /*const struct fb::IRenderBuffer **/ void*);	// V: 0x6C
		virtual void drawVertices(const char *, enum fb::PrimitiveType,/* const struct fb::GeometryDeclarationDesc &*/void*, unsigned int, unsigned int, const void *);	// V: 0x70
		virtual void drawIndexed(const char *, enum fb::PrimitiveType, /*const struct fb::GeometryDeclarationDesc &*/void*, unsigned int, unsigned int, unsigned int, unsigned int, /*const struct fb::IRenderBuffer **/ void*, /*const struct fb::IRenderBuffer **/ void*);	// V: 0x74
		virtual void drawIndexed(/*const struct fb::IndexedDrawCallParams &*/void*);	// V: 0x78
		
	}; // fb::IStateRenderer


};

#endif
#ifndef _RenderViewDesc_H
#define _RenderViewDesc_H

namespace fb
{
	class RenderViewDesc
	{
	public:
		//D3DXMATRIX transform;
		LinearTransform transform;				// 0x00
		INT type;								// 0x40
		PAD(0x4);								// 0x44
		FLOAT fovY;								// 0x48
		FLOAT defaultFovY;						// 0x4C
		FLOAT nearPlane;						// 0x50
		FLOAT farPlane;							// 0x54
		FLOAT aspect;							// 0x58
		FLOAT orthoWidth;						// 0x5C
		FLOAT orthoHeight;						// 0x60
		FLOAT stereoSeparation;					// 0x64
		FLOAT stereoConvergence;				// 0x68
		Vec2 viewportOffset;					// 0x6C
		Vec2 viewportScale;						// 0x74
	};
};

#endif
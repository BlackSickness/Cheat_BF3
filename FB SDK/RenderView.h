#ifndef _RenderView_H
#define _RenderView_H
#include "FB SDK/RenderViewDesc.h"
#include "FB SDK/DxRenderer.h"

namespace fb
{
	class RenderView
	{
	public:
		RenderViewDesc m_desc;							// 0x00
		PAD(0x4);										// 0x7C
		INT m_dirtyFlags;								// 0x80
		PAD(0x16C);										// 0x84
		FLOAT m_fovX;									// 0x1F0
		FLOAT m_depthToWidthRatio;						// 0x1F4
		FLOAT m_fovScale;								// 0x1F8
		FLOAT m_fovScaleSqr;							// 0x1FC
		LinearTransform m_viewMatrix;					// 0x200
		LinearTransform m_viewMatrixTranspose;			// 0x240
		LinearTransform m_viewMatrixInverse;			// 0x280
		//D3DXMATRIX m_viewMatrixInverse;				// 0x280
		LinearTransform m_projectionMatrix;				// 0x2C0
		LinearTransform m_viewMatrixAtOrigin;			// 0x300
		LinearTransform m_projectionMatrixTranspose;	// 0x340
		LinearTransform m_projectionMatrixInverse;		// 0x380
		LinearTransform m_viewProjectionMatrix;			// 0x3C0
		LinearTransform m_viewProjectionMatrixTranspose;// 0x400
		LinearTransform m_viewProjectionMatrixInverse;	// 0x440

	public:
		BOOL Update()
		{
			DxRenderer* dxRenderer = DxRenderer::Singleton();
			if(dxRenderer == NULL)
				return FALSE;
			DWORD UPDATEMATRICES=0x006C3A90;
			FLOAT screenX = static_cast<FLOAT>(dxRenderer->m_screenInfo.m_nWindowWidth);
			FLOAT screenY = static_cast<FLOAT>(dxRenderer->m_screenInfo.m_nWindowHeight);
			this->m_desc.aspect = screenX / screenY;

			((VOID (__fastcall *)(RenderView*, LPVOID))UPDATEMATRICES)(this, NULL);
			return TRUE;
		}
		BOOL GetOriginFromMatrix(fb::Vec3* vOrigin)
		{
			if(vOrigin)
			{
				memcpy_s(vOrigin,sizeof(fb::Vec3),&(this->m_viewMatrixInverse),sizeof(fb::Vec3));
				return TRUE;
			}
			return FALSE;
		}
	};




};

#endif
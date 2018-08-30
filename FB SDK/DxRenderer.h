#ifndef _DxRenderer_H
#define _DxRenderer_H
#include "FB SDK/DxRenderSettings.h"
#include "FB SDK/RenderScreenInfo.h"
namespace fb
{

	class DxRenderer
	{
	public:
		DxRenderSettings *m_settings;
		BYTE Pad_004[0x4];				// 0x00
		UINT m_nFrameCounter;			// 0x08
		BOOL m_bFrameInProgress;		// 0x0C
		HWND m_hWnd;					// 0x10
		BYTE Pad_014[0x4];				// 0x14
		BYTE m_bFullscreenWanted;		// 0x18
		BYTE m_bFullscreenActive;		// 0x19
		BYTE m_bMinimized;				// 0x1A
		BYTE m_bMinimizing;				// 0x1B
		BYTE m_bResizing;				// 0x1C
		BYTE m_bOccluded;				// 0x1D
		BYTE m_bVSync;					// 0x1E
		PAD(0x1);						// 0x1F
		RenderScreenInfo m_screenInfo;	// 0x20
		PAD(0xA4);						// 0x34
		ID3D11Device* pDevice;			// 0xD8
		ID3D11DeviceContext* pContext;  // 0xDC
		PAD(0x14);						// 0xE0
		IDXGISwapChain* pSwapChain;		// 0xF4

	public:
		static DxRenderer* Singleton()
		{
			DWORD DXRENDERER=0x023577D4;
			return *(DxRenderer**)DXRENDERER;
		}
	};

};

#endif
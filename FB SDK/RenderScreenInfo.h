#ifndef _RenderScreenInfo_H
#define _RenderScreenInfo_H

namespace fb
{
		class RenderScreenInfo
	{
	public:
		UINT m_nWidth;					// 0x0
		UINT m_nHeight;					// 0x4
		UINT m_nWindowWidth;			// 0x8
		UINT m_nWindowHeight;			// 0xC
		FLOAT fRefreshRate;				// 0x10
	};

};

#endif
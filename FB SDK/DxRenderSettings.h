#ifndef _DxRenderSettings_H
#define _DxRenderSettings_H

namespace fb
{
	class DxRenderSettings
	{
	public:
		char unknown0[32]; //0x0000
		__int32 Width; //0x0020 
		__int32 Height; //0x0024 
		char unknown40[48]; //0x0028
		__int32 ResX; //0x0058 
		__int32 RexY; //0x005C 
		char unknown96[120]; //0x0060
		ID3D11Device*m_device; //0x00D8 
		ID3D11DeviceContext*m_deviceContext; //0x00DC 
		char unknown224[20]; //0x00E0
		IDXGISwapChain*m_swapChain; //0x00F4 
		char unknown248[4]; //0x00F8
	};

};

#endif
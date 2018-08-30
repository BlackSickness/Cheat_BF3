#ifndef FB_ScreenshotCroppingParams_H
#define FB_ScreenshotCroppingParams_H

namespace fb
{

	class ScreenshotCroppingParams
	{
	public:
		DWORD width; //0x0000  
		DWORD height; //0x0004  
		DWORD left; //0x0008  
		DWORD top; //0x000C  
		DWORD right; //0x0010  
		DWORD bottom; //0x0014  
	};//Size=0x0018(24)

};

#endif
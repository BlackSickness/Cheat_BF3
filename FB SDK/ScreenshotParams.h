#ifndef FB_ScreenshotParams_H
#define FB_ScreenshotParams_H

#include "ScreenshotSource.h"
#include "ScreenshotCroppingParams.h"
#include "IScreenshotCallback.h"

namespace fb
{

	class ScreenshotParams
	{
	public:
		fb::ScreenshotSource source; //0x0000 enum fb::ScreenshotSource 
		const char* explicitFilename; //0x0004  
		char _ScreenshotParams_string_data[12]; //0x0008  
		fb::ScreenshotCroppingParams croppingParams; //0x0014  
		DWORD resolutionMultiplier; //0x002C  
		DWORD antialiasMultiplier; //0x0030  
		DWORD format; //0x0034 enum fb::ScreenshotFormat 
		BYTE alphaEnable; //0x0038  
		BYTE orthoEnable; //0x0039  
		char _ScreenshotParams_skipped_0[2]; //0x003A  
		fb::IScreenshotCallback* callbacks; //0x003C fb::IScreenshotCallback 
	};//Size=0x0040(64)

};

#endif
#ifndef FB_ScreenshotModule_H
#define FB_ScreenshotModule_H

#include "ScreenshotParams.h"
#include "ScreenshotStatus.h"

namespace fb
{

	class ScreenshotModule
	{
	public:
		char _ScreenshotModule_skip_0[8];		//0x0000  
		int m_delayFrame;						//0x0008 
		__int32 m_resolutionFrameIndex;			//0x000C  
		__int32 m_antialiasFrameIndex;			//0x0010  
		__int32 m_lineCount;					//0x0014  
		const char* m_tempPath;					//0x0018  
		const char* m_outputPath;				//0x001C  
		char _ScreenshotModule_skipped_1[12];	//0x0024  
		DWORD m_counter;						//0x002C
		fb::ScreenshotParams m_params;			//0x0030  
		void* m_stagingTexture;					//0x0070 fb::DxTexture 
		char _ScreenshotModule_skipped_2[160];	//0x0074  
		fb::ScreenshotStatus m_status;			//0x0114  
	};//Size=0x0120(288)

};

#endif

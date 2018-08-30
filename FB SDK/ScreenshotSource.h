#ifndef FB_ScreenshotSource_H
#define FB_ScreenshotSource_H

namespace fb
{

	typedef enum ScreenshotSource
	{
		ScreenshotSource_FrameBuffer = 0x0,
		ScreenshotSource_DepthBuffer = 0x1,
	};

};

#endif
#ifndef FB_ScreenshotStatus_H
#define FB_ScreenshotStatus_H


namespace fb
{

	struct ScreenshotStatus
	{
		bool enable;
		bool firstFrame;
		bool autoRenderEnable;
		bool multiRes;
		fb::Vec2 viewportOffset;
	};

};

#endif
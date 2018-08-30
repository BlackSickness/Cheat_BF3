#ifndef FB_IScreenshotCallback_H
#define FB_IScreenshotCallback_H

namespace fb
{

	class IScreenshotCallback
	{
	public:
		virtual void screenshotDone(unsigned char *, unsigned int);     // V: 0x0
	}; // fb::IScreenshotCallback

};

#endif
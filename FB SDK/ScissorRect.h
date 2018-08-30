#ifndef _SCISSORRECT_H
#define _SCISSORRECT_H

namespace fb
{

	class ScissorRect
	{
	public:
		unsigned long            x;
		unsigned long            y;
		unsigned long            w;
		unsigned long            h;
		unsigned char            _padding[8];
	}; //sizeof() == 0x10



};

#endif
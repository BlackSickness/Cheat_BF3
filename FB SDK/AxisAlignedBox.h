#ifndef _AXISALLIGNEDBOX_H
#define _AXISALLIGNEDBOX_H

namespace fb
{

	class AxisAlignedBox
	{
	public:
		enum Corner
		{

			 MinXMinYMinZ,                     // constant 0x0
			 MinXMinYMaxZ,                     // constant 0x1
			 MinXMaxYMinZ,                     // constant 0x2
			 MinXMaxYMaxZ,                     // constant 0x3
			 MaxXMinYMinZ,                     // constant 0x4
			 MaxXMinYMaxZ,                     // constant 0x5
			 MaxXMaxYMinZ,                     // constant 0x6
			 MaxXMaxYMaxZ                     // constant 0x7

		};// Corner

		enum Side
		{

			 Left,                     // constant 0x0
			 Right,                     // constant 0x1
			 Back,                     // constant 0x2
			 Front,                     // constant 0x3
			 Bottom,                     // constant 0x4
			 Top,                    // constant 0x5

		}; // Side

		enum ZeroInit
		{

			 Zero                  // constant 0x0

		}; // ZeroInit

		__declspec(align(16)) Vec3 min;                     // 0x0
		__declspec(align(16)) Vec3 max;                     // 0x10

	}; // fb::AxisAlignedBox
};

#endif
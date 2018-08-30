#ifndef _FRUSTUM_H
#define _FRUSTUM_H

namespace fb
{

	
	class Frustum
	{

		enum PlaneType
		{

			 Far,                     // constant 0x0
			 Near,                     // constant 0x1
			 Right,                     // constant 0x2
			 Left,                     // constant 0x3
			 Upper,                     // constant 0x4
			 Lower                     // constant 0x5

		}; // PlaneType

		enum PlaneFlag
		{

			 FarFlag,                     // constant 0x1
			 NearFlag,                     // constant 0x2
			 RightFlag,                     // constant 0x4
			 LeftFlag,                     // constant 0x8
			 UpperFlag,                     // constant 0x10
			 LowerFlag,                     // constant 0x20
			 AllFlag                     // constant 0x3F

		}; // PlaneFlag

		enum Corner
		{

			 MinXMinYMinZ,                     // constant 0x0
			 MinXMinYMaxZ,                     // constant 0x1
			 MinXMaxYMinZ,                     // constant 0x2
			 MinXMaxYMaxZ,                     // constant 0x3
			 MaxXMinYMinZ,                     // constant 0x4
			 MaxXMinYMaxZ,                     // constant 0x5
			 MaxXMaxYMinZ,                     // constant 0x6
			 MaxXMaxYMaxZ	                   // constant 0x7

		}; // Corner

		LinearTransform m_transform;                     // 0x0
		AxisAlignedBox m_boundingBox;                     // 0x40
		Vec3/*[0x8]*/ m_corners[8];                     // 0x60
		Vec3 m_center;                     // 0xE0
		Plane/*[0x6]*/ m_planes[6];                     // 0xF0
		float m_radius;                     // 0x150
		float m_radiusSqr;                     // 0x154
		bool m_rightHanded;                     // 0x158

	}; // fb::Frustum


};

#endif
#ifndef _QUATTRANSFORM_H
#define _QUATTRANSFORM_H

namespace fb
{
	class QuatTransform
	{
		public:
		// use Vec3 and skip the reference to quat which is also only a vec
		//Vec4 transAndScale;                     // 0x0
		//Quat rotation;                     // 0x10*/
		Vec3 transAndScale;		// 0x00
		Vec3 rotation;			// 0x10
	}; // fb::QuatTransform

};

#endif
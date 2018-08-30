#ifndef _EA_H
#define _EA_H

namespace EA
{
	namespace Ant
	{
		
		class SQT
		{
			public:
			enum
			{

				 SUBINDEX_S,                    // constant 0x0
				 SUBINDEX_Q,                     // constant 0x1
				 SUBINDEX_T,                     // constant 0x2
				 NUMCOMPONENTS                     // constant 0x3

			}; // <unnamed-tag>

			/*class rw::math::vpu::Vector3*/void* mScale;                     // this+0x0
			/*class rw::math::vpu::Quaternion*/void* mRotation;                     // this+0x10
			/*class rw::math::vpu::Vector3*/void* mTranslation;                     // this+0x20

		}; // EA::Ant::SQT
	};
};
#endif
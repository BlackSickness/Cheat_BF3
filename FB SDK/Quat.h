#ifndef _QUAT_H
#define _QUAT_H

namespace fb
{

	class Quat
	{
		public:
		enum ZeroType
		{
			 Zer                  // constant 0x0
		}; // ZeroType

		enum IdentityType
		{
			Identity                     // constant 0x0
		}; // IdentityType
		Vec4 vec;                     // 0x0
	}; // fb::Quat



};

#endif
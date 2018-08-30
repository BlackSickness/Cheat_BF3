#ifndef _ASSET_H
#define _ASSET_H

#include "Frostbite_Classes.h"

namespace fb
{

	class Asset
		: public DataContainer	// 0x00
	{
	public:
		String m_name;			// 0x08
	}; // 0x0C


};

#endif
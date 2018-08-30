#ifndef _HavokAsset_H
#define _HavokAsset_H
#include "Frostbite_Classes.h"
namespace fb
{
		class HavokAsset
		: public Asset								// 0x00
	{
	public:
		FLOAT m_scale;								// 0x0C
		RefArray<DataContainer> m_externalAssets;	// 0x10
	}; // 0x14

};

#endif
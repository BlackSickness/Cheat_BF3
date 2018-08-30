#ifndef _WorldData_H
#define _WorldData_H

#include "SubWorldData.h"
namespace fb
{
	class WorldData
		: public SubWorldData					// 0x00
	{
	public:
		DataContainer* m_runtimeMaterialGrid;	// 0x2C
	}; // 0x30

};

#endif
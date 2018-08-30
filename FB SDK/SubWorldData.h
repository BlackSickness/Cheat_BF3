#ifndef _SubWorldData_H
#define _SubWorldData_H

#include "SpatialPrefabBlueprint.h"
namespace fb
{
	class SubWorldData
		: public SpatialPrefabBlueprint			// 0x00
	{
	public:
		DataContainer* m_registryContainer;		// 0x24
		BYTE m_isWin32SubLevel;					// 0x28
		BYTE m_isXenonSubLevel;					// 0x29
		BYTE m_isPs3SubLevel;					// 0x2A
		PAD(0x1);								// 0x2B
	}; // 0x2C

};

#endif
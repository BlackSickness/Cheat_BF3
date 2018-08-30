#ifndef _MaterialGridManager_H
#define _MaterialGridManager_H

namespace fb
{
	class MaterialGridManager
	{
	public:
		EntityBusData* m_busData;						// 0x00
		EntityBus* m_entityBus;							// 0x04
		MaterialGridData* m_data;						// 0x08
		MaterialContainerPair* m_defaultMaterialPair;	// 0x0C
		DWORD m_defaultMaterialIndex;					// 0x10
	}; // 0x14
};

#endif
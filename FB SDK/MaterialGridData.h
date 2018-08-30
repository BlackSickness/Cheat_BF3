#ifndef _MESSAGELISTENER_H
#define _MESSAGELISTENER_H

namespace fb
{
	class MaterialGridData
		: public Asset												// 0x00
	{
	public:
		DataContainer* m_defaultMaterial;							// 0x0C
		RefArray<MaterialContainerPair> m_materialPairs;			// 0x10
		Array<UINT> m_materialIndexMap;								// 0x14
		DWORD m_defaultMaterialIndex;								// 0x18
		Array<MaterialRelationPropertyPair> m_materialProperties;	// 0x1C
		Array<MaterialInteractionGridRow> m_interactionGrid;		// 0x20
	}; // 0x24x08

};

#endif
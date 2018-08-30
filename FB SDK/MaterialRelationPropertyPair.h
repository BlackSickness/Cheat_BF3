#ifndef _MaterialRelationPropertyPair_H
#define _MaterialRelationPropertyPair_H

namespace fb
{
	class MaterialRelationPropertyPair
	{
	public:
		RefArray<DataContainer> m_physicsMaterialProperties;		// 0x00
		RefArray<DataContainer> m_physicsPropertyProperties;		// 0x04
	}; // 0x08

};

#endif
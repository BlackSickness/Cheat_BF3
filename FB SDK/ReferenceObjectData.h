#ifndef _ReferenceObjectData_H
#define _ReferenceObjectData_H
#include "Frostbite_Classes.h"
#include "GameObjectData.h"
namespace fb
{
	class ReferenceObjectData
		: public GameObjectData					// 0x00
	{
	public:
		LinearTransform m_bluprintTransform;	// 0x10
		DataContainer* m_blueprint;				// 0x50
		DataContainer* m_objectVariation;		// 0x54
		StreamRealm m_streamRealm;				// 0x58
		INT m_excluded;							// 0x5C
	}; // 0x60

};

#endif
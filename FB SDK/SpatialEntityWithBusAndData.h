#ifndef _SpatialEntityWithBusAndData_H
#define _SpatialEntityWithBusAndData_H
#include "Frostbite_Classes.h"
#include "SpatialEntity.h"
namespace fb
{
	template <class T>
	class SpatialEntityWithBusAndData
		: public SpatialEntity				// 0x00
	{
	public:
		EntityBus* m_entityBus;				// 0x10
		T* m_data;							// 0x14
	}; // 0x18
};

#endif
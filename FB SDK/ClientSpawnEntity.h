#ifndef _ClientSpawnEntity_H
#define _ClientSpawnEntity_H
#include "Frostbite_Classes.h"
#include "SpatialEntityWithBusAndData.h"
namespace fb
{
	
	class ClientSpawnEntity
		: public SpatialEntityWithBusAndData<SpawnReferenceObjectData>,		// 0x00
		network::ClientGhost,												// 0x18
		network::IClientNetworkable											// 0x58
	{
	public:
		class Interpolator
			: public network::Interpolator<LPVOID>	// 0x00
		{
		public:
			ClientSpawnEntity* m_spawnEntity;		// 0x40
		}; // 0x44

		class ControllableListener
		{
		public:
			LPVOID vftable;		// 0x00
		}; // 0x04

		eastl::vector<ClientControllableEntity*> m_spawnedControllables;	// 0x60
		EntityBus* m_peerSubBus;											// 0x70
		DWORD m_controllableTransform;										// 0x74 PropertyWriter<LinearTransform>
		PAD(0x8);															// 0x78
		LinearTransform m_transform;										// 0x80
		Interpolator m_interpolator;										// 0xC0
		INT m_teamId;														// 0xC4
		INT m_enabled;														// 0xC8
		eastl::vector<ControllableListener> m_controllableListeners;		// 0xCC
	}; // 0xDC

};

#endif
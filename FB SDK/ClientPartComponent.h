#ifndef _ClientPartComponent_H
#define _ClientPartComponent_H
#include "Frostbite_Classes.h"
#include "PartComponent.h"
#include "ClientHealthStateEntityManager.h"
namespace fb
{
	class ClientPartComponent
		: public PartComponent<ClientComponent>,						// 0x00
		public network::IClientNetworkableGroupMember					// 0x20
	{
	public:
		DWORD m_meshModel;												// 0x28 MeshModel*
		DWORD m_interpolationObject;									// 0x2C ClientPartComponent::InterpolationObject*
		PAD(0x4);														// 0x30
		ClientHealthStateEntityManager m_healthStateEntityManager;		// 0x34
		PAD(0x8);														// 0x48
	}; // 0x50
};

#endif
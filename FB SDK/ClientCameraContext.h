#ifndef _MESSAGELISTENER_H
#define _MESSAGELISTENER_H
#include "Frostbite_Classes.h"
#include "CameraContext.h"
namespace fb
{
	class ClientCameraContext
		: public network::IClientNetworkable,						// 0x00
		public network::Interpolator<LPVOID>,						// 0x08
		public CameraContext										// 0x48
	{
	public:
		PAD(0x8);													// 0xD8
		DWORD m_weakTokenHolder;									// 0xE0
		WeakPtr<ClientControllableEntity> m_targetObject;			// 0xE4
		WeakPtr<ClientControllableEntity> m_targetControllable;		// 0xE8
		DWORD m_targetEntryId;										// 0xEC
		ClientGameView* m_gameView;									// 0xD0
	}; // 0xD4

};

#endif
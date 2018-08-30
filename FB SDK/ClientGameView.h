#ifndef _ClientGameView_H
#define _ClientGameView_H
#include "Frostbite_Classes.h"
#include "GameView.h"
#include "MessageListener.h"
namespace fb
{
	class ClientGameView
		: public GameView,													// 0x00
		public MessageListener												// 0x08
	{
	public:
		enum FreeCameraMode
		{
			Static,
			Follow,
			LookAt,
		};

		LinearTransform m_cameraTargetOffset;								// 0x10
		Vec3 m_cameraTargetDistance;										// 0x50
		CameraScene* m_freeCameraScene;										// 0x60
		FreeCamera* m_freeCamera;											// 0x64
		FreeCameraMode m_freeCameraMode;									// 0x68
		INT m_freeCameraPriority;											// 0x6C
		PAD(0x8);															// 0x70
		ClientEntryComponent* m_inputTarget;								// 0x78
		EntryComponent::Subscriber* m_inputUnspawnCallback;					// 0x7C
		WeakPtr<ClientGameEntity> m_cameraTarget;							// 0x80
		ClientEntryComponent* m_cameraEntryTarget;							// 0x84
		GameView::EntryUnSpawnCallback* m_targetEntryUnSpawnCallback;		// 0x88
		WeakPtr<ClientCameraContext> m_cameraContext;						// 0x8C
	}; // 0x90


};

#endif
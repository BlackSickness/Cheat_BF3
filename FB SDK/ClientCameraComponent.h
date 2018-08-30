#ifndef _ClientCameraComponent_H
#define _ClientCameraComponent_H
#include "Frostbite_Classes.h"
#include "ClientComponent.h"
#include "CameraComponent.h"
namespace fb
{
	class ClientCameraComponent
		:public ClientComponent,// Inherited class at offset 0x0
		 CameraComponent // Inherited class at offset 0x10
	{
			public:
		enum MeshId
		{

			 MeshId_Normal,                    // constant 0x0
			 MeshId_ScreenMask                  // constant 0x1

		}; // MeshId

		class CharacterCameraTransition
		{
			public:
			enum State
			{

				 State_WaitForEnterEntry,                     // constant 0x0
				 State_Blend                   // constant 0x1

			}; // State

			/*class fb::ClientSoldierCameraComponent **/void*  m_soldierCameraComponent;                     // this+0x0
			/*class fb::VehicleEntryListenerComponent * */void* m_vehicleEntryListenerComponent;                     // this+0x4
			float m_transitionTime;                     // this+0x8
			float m_factor;                     // this+0xC
			enum fb::ClientCameraComponent::CharacterCameraTransition::State m_state;                     // this+0x10
			bool m_required;                     // this+0x14

		}; // CharacterCameraTransition

		class fb::ClientCameraComponent::CharacterCameraTransition m_transition;                     // this+0x14
		struct fb::LinearTransform m_meshTransform;                     // this+0x30
		/*class fb::ScopedPtr<fb::ClientCameraComponentSound>*/void* m_cameraSound;                     // this+0x70
		struct fb::CameraComponent::State m_predictionState;                     // this+0x74
		struct fb::CameraComponent::State m_correctionState;                     // this+0x7C
		struct fb::CameraComponent::State * m_currentState;                     // this+0x84
/*		class fb::TargetCamera **/void* m_camera;                     // this+0x88
		MeshModel* m_meshModel;                     // this+0x8C
		MeshModel*m_maskMeshModel;                     // this+0x90
		MeshModel* m_alternateMeshModel;                     // this+0x94
		MeshModel* m_alternateMaskMeshModel;                     // this+0x98
		/*class fb::PropertyWriter<bool> */void* m_isActiveOutput;                     // this+0x9C
		/*class fb::PropertyWriter<bool> */void* m_alternateViewOutput;                     // this+0xA0
		float m_transitionDelta;                     // this+0xA4
		float m_elapsedTransitionTime;                     // this+0xA8
		float m_recoilFov;                     // this+0xAC
		bool m_isActive;                     // this+0xB0, len(0x1)
		bool m_isVisible;                     // this+0xB1, len(0x1)
		bool m_isKeyFramed;                     // this+0xB2, len(0x1)
		bool m_isEnabled;                     // this+0xB3, len(0x1)
		bool m_fovOverridden;                     // this+0xB4, len(0x1)
		virtual void * __vecDelDtor(unsigned int);	// V: 0x24

	}; // fb::ClientCameraComponent



};

#endif
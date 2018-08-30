#ifndef _ClientEntryComponent_H
#define _ClientEntryComponent_H
#include "Frostbite_Classes.h"
#include "ClientComponent.h"
#include "EntryComponent.h"
namespace fb
{
	class ClientEntryComponent
		: public ClientComponent,								// 0x00
		public EntryComponent,									// 0x10
		public network::IClientNetworkable,						// 0x38
		public network::Interpolator<LPVOID>,					// 0x40
		public MessageListener									// 0x80
	{
	public:
		class Camera
		{
		public:
			DWORD camera;				// 0x00
			DWORD callback;				// 0x04
			CHAR isFirstPerson;			// 0x08
			CHAR receivesImpulses;		// 0x09
			PAD(0x2);					// 0x0A
		}; // 0x0C

		DWORD m_turrentComponent;								// 0x88
		PAD(0x4);												// 0x8C
		eastl::vector<EntryInputActionMap*> m_inputActionMaps;  // 0x90
		EntryInputTranslator* m_inputTranslator;				// 0xA0
		eastl::vector<ClientEntryComponent::Camera> m_cameras;						// 0xA4

		//new stuff
		CameraScene * m_cameraScene;                     // this+0xC8
		eastl::vector<fb::ClientCameraComponent *,fb::eastl_arena_allocator> m_cameraComponents;                     // this+0xCC
		eastl::vector<fb::ClientStanceFilterComponent *,fb::eastl_arena_allocator> m_stanceFilterComponents;                     // this+0xDC
		ClientPlayer * m_player;                     // this+0xEC
		unsigned int m_previousCamera;                     // this+0xF0
		bool m_defaultCameraView;                     // this+0xF4
		EntryComponent::State m_predictionState;                     // this+0xF8
		EntryComponent::State m_correctionState;                     // this+0x104
		EntryComponent::State * m_currentState;                     // this+0x110
		EntryComponent::State m_replicatedState;                     // this+0x114
		ClientEntryComponentSound * m_entryComponentSound; 


	}; // 0xB4

};

#endif
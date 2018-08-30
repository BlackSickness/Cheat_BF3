#ifndef _ClientCharacterEntity_H
#define _ClientCharacterEntity_H
#include "Frostbite_Classes.h"
#include "ClientControllableEntity.h"
#include "CharacterEntity.h"
namespace fb
{
		class ClientCharacterEntity
		: public ClientControllableEntity,			// 0x00
		  public CharacterEntity						// 0xB4
	{
	public:

		//BYTE pad_0B4[0x4];								// 0xB4
		ClientPlayer* m_player;							// 0xB8
		ClientAntAnimatableComponent* m_animatableComponent[2];					// 0xBC
		DWORD m_collisionComponent;						// 0xC4
		DWORD m_healthComponent;						// 0xC8
		WORD m_lightProbeHandle;						// 0xCC
		PAD(0x2);			//ShProbe m_shProbe;							// 0xCE
		eastl::vector<IInputFilter*> m_inputFilters;	// 0xD0
		DWORD m_hasLocalPlayer;							// 0xE0
		PersonViewEnum m_activeView;					// 0xE4
		Entity * * m_ownedEntities;						// 0xE8
		WORD m_ownedEntityCount;						// 0xEC
		CHAR m_mustBeRemotePlayer;						// 0xEE
		PAD(0x1);										// 0xEF
	}; // 0xF0

};

#endif
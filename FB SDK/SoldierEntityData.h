#ifndef _SoldierEntityData_H
#define _SoldierEntityData_H
#include "Frostbite_Classes.h"
#include "CharacterEntityData.h"
namespace fb
{
	class SoldierEntityData
		: public CharacterEntityData			// 0x00
	{
	public:
		PAD(0x10);								// 0x90
		Vec3 m_fLIRKeyColor; 					// 0xA0 
		DataContainer* m_headMaterialPair; 		// 0xB0 
		DataContainer* m_boneFakePhysics; 		// 0xB4 
		DataContainer* m_autoAim; 				// 0xB8 
		DataContainer* m_aimingConstraints; 	// 0xBC 
		DataContainer* m_headCollision; 		// 0xC0 
		DataContainer* m_characterPhysics; 		// 0xC4 
		DataContainer* m_footMaterialPair; 		// 0xC8 
		DataContainer* m_sprintSettings; 		// 0xCC 
		DataContainer* m_meshes1p; 				// 0xD0 
		DataContainer* m_meshes3p; 				// 0xD4 
		DataContainer* m_hidableMeshParts; 		// 0xD8 
		DataContainer* m_sound; 				// 0xDC 
		DataContainer* m_streamGroup1p; 		// 0xE0 
		FLOAT m_impulseReactionTime; 			// 0xE4 
		DataContainer* m_healthModule; 			// 0xE8 
		FLOAT m_maxHealth; 						// 0xEC
		DataContainer* m_collisionInfo; 		// 0xF0 
		DataContainer* m_voiceOverInfo; 		// 0xF4 
		FLOAT m_fLIRValue; 						// 0xF8 
		DataContainer* m_breathControl; 		// 0xFC 
		FLOAT m_explosionDamageModifier; 		// 0x100 
		DataContainer* m_uiParts; 				// 0x104 
		FLOAT m_regenerationDelayModifier; 		// 0x108 
		CHAR m_freeSpaceCheck; 					// 0x10C 
		CHAR m_proximityCheck; 					// 0x10D 
		CHAR m_enableGroundmapLighting; 		// 0x10E 
		CHAR m_showWeaponWhenDead; 				// 0x10F 
		CHAR m_lowerGunOnOwnTeam; 				// 0x110 
		CHAR m_useSpineXRotation; 				// 0x111 
		CHAR m_collisionEnabled; 				// 0x112 
		CHAR m_physicsControlled; 				// 0x113 
		CHAR m_humanPlayerControlled; 			// 0x114 
		CHAR m_interactiveManDownAllowed; 		// 0x115 
		CHAR m_showNametag; 					// 0x116 
	};


};

#endif
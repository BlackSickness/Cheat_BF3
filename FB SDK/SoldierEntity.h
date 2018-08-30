#ifndef _SoldierEntity_H
#define _SoldierEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
	
	class SoldierEntity   // Inherited class at offset 0x170
	{
	public:
		enum DeathType
        {
                Shot,                    
                ShotInVehicleEntry,                    
                InsideExplodingVehicle,                    
                DeathTypeCount,                    
        };
 
        enum SoldierInteractedStatus
        {
                SoldierInteractedStatus_None,                    
                SoldierInteractedStatus_BeingInteracted,                    
                SoldierInteractedStatus_BeingInteractedCancelled,                    
                SoldierInteractedStatus_BeingInteractedFinished,                    
                SoldierInteractedStatus_Count,                    
        };
		
		virtual BoneCollisionComponent * boneCollisionComponent();	// V: 0x0
		virtual LinearTransform & soldierTransform();	// V: 0x4
		virtual bool isManDown();	// V: 0x8
		virtual bool isInteractiveManDown();	// V: 0xC
		virtual bool hasRestrictedMovement();	// V: 0x10
		virtual bool isFiring();	// V: 0x14
		virtual bool isReloading();	// V: 0x18
		virtual void funkyme();
		virtual float getManDownTimeLeft();	// V: 0x1C
		virtual WeaponSway * getWeaponSway();	// V: 0x20
		virtual  WeaponFiring * getCurrentWeaponFiring();	// V: 0x24
		virtual WeaponFiringData * getCurrentWeaponFiringData();	// V: 0x28
		virtual float moveSpeedMultiplier();	// V: 0x2C
		virtual SoldierBoundsChecker* boundsChecker();	// V: 0x30
		virtual DeathType deathType();	// V: 0x34
		virtual SoldierEntityActionState actionState();	// V: 0x40
		/*
        virtual void Function15(); //
        virtual void Function16(); //
        virtual void Function17(); //
        virtual void Function18(); //
        virtual void Function19(); //
        virtual void Function20(); //
        virtual void Function21(); //
        virtual DWORD computeBoundingBoxWorldTransform( fb::LinearTransform* matrix ); //
        virtual DWORD computeBoundingBox( fb::AxisAlignedBox* aabb ); //
        virtual void Function25(); //
		*/
		PAD(0xC);													// 0x04
		SoldierEntityData* m_soldierData;							// 0x10

		
		
		AutoAimData* m_autoAimData[3];								// 0x14
		//changes 
		bool m_overrideLookAt;										// 0x20
		PAD(0xC);													// 0x24
		Vec3 m_lookTarget;											// 0x30
		FLOAT m_headRotationSpeed;									// 0x40
		INT m_allowedToMoveEyes;									// 0x44
		FLOAT m_waterLevelUpdateTimer;								// 0x48
		PAD(0x4);													// 0x4C
		Vec3 m_hitDirection;										// 0x50
		MaterialContainerPair* m_headMaterial;						// 0x60
		Component* m_space;											// 0x64
		SupportedShootingCallback* m_supportedShootingCallback;		// 0x68
		EyePositionCallback* m_eyePositionCallback;					// 0x6C
		FLOAT m_maxHealth;											// 0x70
		CharacterPhysicsEntity* m_characterPhysicsentity;			// 0x74
		PAD(0x8);													// 0x78
		CharacterPhysicsEntity::CharacterInput m_characterInput;	// 0x80
		PAD(0xC);													// 0xD4
		INT m_beingInteractedStatus;								// 0xE0
		FLOAT m_waterLevel;											// 0xE4
		CHAR m_entryPoseEnabled;									// 0xE8
		CHAR m_physicsControlled;									// 0xE9
		CHAR m_isShielded;											// 0xEA
		PAD(0x1);													// 0xEB
		CharacterEntity* m_character;								// 0xEC


	}; // 0xF0

};

#endif
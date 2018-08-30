#ifndef _EntityStuff_H
#define _EntityStuff_H

#include "Frostbite_Classes.h"
#include "CollisionState.h"
namespace fb
{
	class ClientGhostProjectileEntityState // Inherited class at offset 0x0
	{
	public:
		byte transformFlag;      // this+0x0, len(0x1)
		byte detonated;          // this+0x1, len(0x1)
		byte armed;              // this+0x2, len(0x1)
		byte attached;           // this+0x3, len(0x1)
		byte isSleeping;         // this+0x4, len(0x1)
		PAD(0xC);
		Vec3 position;           // this+0x10
		Quat orientation;        // this+0x20

	}; // fb::ClientGhostProjectileEntityState

	class ClientGrenadeEntityState
		:public ClientGhostProjectileEntityState
	{
		public:
		struct fb::Vec3 collisionNormal;                     // this+0x30
		class fb::CollisionState m_collision;                     // this+0x40

	}; // fb::ClientGrenadeEntityState

	class ClientGrenadeEntity 
        : public ClientGameEntity 
    { 
    public: 
        char pad[536];                                    //0020 
        fb::WeakPtr<fb::ClientSoldierEntity> m_shooter;    //0238 
		//ClientGrenadeEntityState m_state;                     // this+0x290
		

        __forceinline int GetTeamID( void ) 
        { 
            if( m_shooter.GetData() ) 
            { 
                fb::ClientSoldierEntity* pShooter = reinterpret_cast< fb::ClientSoldierEntity* >( m_shooter.GetData() ); 
                if( pShooter ) 
                { 
                    fb::ClientPlayer* pShooterI = pShooter->m_player; 
                    if( pShooterI ) 
                        return pShooterI->m_teamId; 
                } 
            } 
            return 0; 
        } 
        __forceinline fb::ClientSoldierEntity* GetShooterSoldier( void ) 
        { 
            if( m_shooter.GetData() ) 
            { 
                fb::ClientSoldierEntity* pShooter = reinterpret_cast< fb::ClientSoldierEntity* >( m_shooter.GetData() ); 
                if( pShooter ) 
                    return pShooter; 
            } 
            return 0; 
        } 
        __forceinline ClientPlayer* GetShooterPlayer( void ) 
        { 
            if( m_shooter.GetData() ) 
            { 
                fb::ClientSoldierEntity* pShooter = reinterpret_cast< fb::ClientSoldierEntity* >( m_shooter.GetData() ); 
                if( pShooter ) 
                    return pShooter->m_player; 
            } 
            return 0; 
        } 
    }; 

	class ClientExplosionPackState
		:public ClientGhostProjectileEntityState
	{
	public:
		Quat offsetOrientation;                     // this+0x30
		Vec3 offsetTrans;                     // this+0x40
		WeakPtr<fb::ClientControllableEntity> attachedToEntity;                     // this+0x50
		Component * attachedToComponent;                     // this+0x54
		byte  attachEntityFlag;                     // this+0x58, len(0x1)
		byte  isAttachedToGhost;                     // this+0x59, len(0x1)
		PAD(0x2);
		int impactMaterial;                     // this+0x5C
		int teamId;                     // this+0x60
	}; // fb::ClientExplosionPackState

	

	class ClientExplosionPackEntity 
        : public ClientGameEntity 
    { 
    public: 
		PAD(0x290);
	// 	ClientExplosionPackState m_state; // this+0x288
	//	float m_spottedTime;              // this+0x28C
		int m_teamId;                     // this+0x290
		int m_damageGiverPlayerId;        // this+0x294
		bool m_isSpotted;                 // this+0x298
    }; 

	class ClientSupplySphereEntity 
		:public ClientExplosionPackEntity
	{
		public:
	};


	class SoldierWeaponBlueprint 
    { 
    public: 
        char unknown0[8];    //0000 
        String m_name;    //0008 

		__forceinline char *GetWeaponName()
        { 
            static char szWeaponName[20] = {0}; 
            bool asdf = false; 
			bool Slash = false;

			char *name = m_name.GetString(); 

			if( name ) 
			{ 
				for( int i = 0, j = 0; i < (int)strlen(name); i++ ) 
				{ 
					if( asdf && name[i] == '_' ) 
					{ 
						szWeaponName[j] = 0; 
						break; 
					} 

					if( name[i] == '/' && !asdf ) 
					{ 
						if(!Slash)
						{
							Slash = true;
							continue;
						}
						asdf = true; 
						continue; 
					} 

					if( asdf )
					{ 
						szWeaponName[j] = name[i]; 
						j++; 
					} 
				} 
			}
			return szWeaponName;
        } 
    }; 

    class PickupEntity 
    { 
    public: 
        class WeaponInfo 
        { 
        public: 
            SoldierWeaponBlueprint *blueprint;    //0000 
            unsigned char pad[132];                    //0004 
            unsigned int weaponSlot;                //0088 
            int altWeaponSlot;                        //008C 
            int linkedToWeaponSlot;                    //0090 
            int clipAmmo;                            //0094 
            int spareAmmo;                            //0098 
            float reloadTimer;                        //009C 
            bool ammoPickup;                        //00A0 
        }; 

        void *m_pickupEntityData;                                    //0000 
        eastl::vector< PickupEntity::WeaponInfo * > m_weapons;    //0004 
        int m_droppedByTeam;                                        //0014 
        void *dummy;//class fb::SmartRef<fb::CharacterCustomizationAsset const > m_droppedByCharacterCustomizationAsset;                     //0018 

    }; 

    class ClientPickupEntity  
        : public ClientGameEntity 
    { 
    public: 
        char padding001[140];                        //0020 
        PickupEntity::WeaponInfo *pWeaponInfo;    //00AC 
    };  

};

#endif
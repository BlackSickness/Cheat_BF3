#ifndef _ClientSoldierEntity_H
#define _ClientSoldierEntity_H
#include "Frostbite_Classes.h"
#include "ClientCharacterEntity.h"
#include "SoldierEntity.h"
#include "CharacterPhysicsEntityCallbacks.h"
#include "IClientSoldierHealthModule.h"
#include "ClientSoldierEntityState.h"
namespace fb
{
    class ClientSoldierEntity /*size 410*/
        : public ClientCharacterEntity,        /*size 0xF0*/         // 0x00  // Inherited class at offset 0x00 
        public SoldierEntity,/*size f0*/                         // 0xF0   // Inherited class at offset 0x170    
        public network::Interpolator<ClientSoldierEntityState>,/*size 40*/        // 0x1E0  // Inherited class at offset 0x280
        public CharacterPhysicsEntityCallbacks     /*size 4*/        // 0x220    // Inherited class at offset 0x2C8
    {
    public:

        //fb::ClassInfo::TypeInfoData fb::ClientSoldierEntity::c_typeinfodata; //0
        //fb::FieldInfo::FieldInfoData c_fieldinfodata; //0
        //fb::ClassInfo fb::ClientSoldierEntity::c_TypeInfo; //0
    

        class PersonView
        {
        public:
            eastl::vector<MeshModel> m_meshModels;    // 0x00 
            DWORD m_weaponBoneIndex;                // 0x10
        }; // 0x14

        class BreathControlHandler
        {
        public:
            BreathControlData* m_data;                    // 0x00
            FLOAT m_breathControlTimer;                    // 0x04
            FLOAT m_breathControlMultiplier;            // 0x08
            FLOAT m_breathControlPenaltyTimer;            // 0x0C
            FLOAT m_breathControlPenaltyMultiplier;        // 0x10
            BYTE m_breathControlActive;                    // 0x14 Lower two bits set if active
            PAD(0x3);                                    // 0x15
        }; // 0x18

        class SprintInputHandler
        {
        public:
            enum State
            {
                WaitForward,
                WaitReleaseForward,
                DoubleTapSprint,
                ButtonSprint,
                WaitReleaseButtonSprint,
                PostSprint,
            };

            State m_currentState;            // 0x00
            FLOAT m_doubleTapTimer;            // 0x04
            FLOAT m_sprintReleaseTimer;        // 0x08
            INT m_waitForSprintRelease;        // 0x0C
        }; // 0x10

        class OrientationCallback
            :public CharacterPhysicsEntity::OrientationCallback 
        {
        public:
            ClientSoldierEntity * m_soldier;                     // 0x4
        }; // OrientationCallback


        enum HiddenBoneType
        {
             HideAlways,                    // constant 0x0
             HideInVehicleEntries,          // constant 0x1
             HideUsingWeaponMesh            // constant 0x2
        }; // HiddenBoneType

        class HiddenBone
        {
            SkinnedMeshAsset * m_mesh; // 0x0
            int m_boneIndex;                     // 0x4
            ClientSoldierEntity::HiddenBoneType m_hideType;  // 0x8
        }; // HiddenBone
        
        //new old pad was 0x10
        PAD(0x4);                                                        // 0x224
        WeakPtr<fb::ClientPlayer> m_previousPlayer;                        // 0x228 
        WeakPtr<fb::ClientPlayer> m_corpse;                                // 0x22C    
        ClientEntryComponent*m_vehicleEntry;                            // 0x230
        PAD(0x10);
        Blueprint* m_blueprint;                                            // 0x234
        ClientSoldierPrediction* m_predictedController;                    // 0x238
        ClientSoldierReplication* m_replicatedController;                // 0x23C
        DWORD m_vegetationInfo;                                            // 0x240
        PAD(0x4);                                                        // 0x244
        FLOAT m_movementPenalty;                                        // 0x248
        FLOAT m_clearMovementTimer;                                        // 0x24C
        ClientCharacterCustomizationComponent * m_customizationComponent;// 0x250
        INT m_received1pHint;                                            // 0x254
        DWORD m_cameraComponent;                                        // 0x258
        MaterialContainerPair* m_footMaterial;                            // 0x25C
        PersonView m_personViews[2];                                    // 0x260
        // Bones when player is in vehicle
        eastl::vector<ClientSoldierEntity::HiddenBone> m_hiddenBones;    // 0x288
        FLOAT m_authorativeYaw;                                            // 0x298
        PAD(0x4);                                                        // 0x29C
        INT m_aimingenabled;                                            // 0x2A0
        FLOAT m_authorativePitch;                                        // 0x2A4
        DWORD m_soldierSound;                                            // 0x2A8
        PAD(0x4);                                                        // 0x2AC
        LinearTransform m_meshTransform;                                // 0x2B0
        SoldierEntityActionState m_oldActionState;                        // 0x2F0
        CharacterPoseType m_previousPose;                                // 0x2F4
        BYTE m_forceInivisble;                                            // 0x2F8
        BYTE m_derivedStatusUpdated;                                    // 0x2F9
        BYTE m_visualTransformUpdated;                                    // 0x2FA
        BYTE pad_2FB[0x1];                                                // 0x2FB
        FLOAT m_lastAnimFrameTime;                                        // 0x2FC
        Vec3 m_lastAnimFramePos;                                        // 0x300
        FLOAT m_orderStatusTime;                                        // 0x310
        FLOAT m_targetTime;                                                // 0x314
        eastl::vector<BoneFakePhysics> m_fakePhysics;                    // 0x318
        FLOAT m_aiDamageHumanCooldown;                                    // 0x328
        FLOAT m_speedPenaltyOnDamageTimer;                                // 0x32C
        FLOAT m_speedPenaltyOnDamage;                                    // 0x330
        ClientProximityHookImpl* m_proximityHook;                        // 0x334
        ClientSoldierEntity::OrientationCallback *m_orientationCallback;// 0x338
        bool m_isUnspawning;                                            // 0x33C
        float m_effectVolumeAccumulated;                                // 0x340
        IClientSoldierHealthModule* m_healthModule;                        // 0x344
        FLOAT m_deathTimer;                                                // 0x348
        ClientSoldierWeaponsComponent* m_soldierWeaponsComponent;        // 0x34C
        ClientSoldierBodyComponent * m_bodyComponent;                    // 0x350
        ClientBoneCollisionComponent* m_boneCollisionComponent;            // 0x354
        ClientRagdollComponent * m_ragdollComponent;                    // 0x358
        ClientAimingReplication * m_replicatedAiming;                    // 0x35C
        BreathControlHandler* m_breathControlHandler;                    // 0x360
        SprintInputHandler* m_sprintInputHandler;                        // 0x364
        EntryInputActionEnum m_sprintInterruptAction;                    // 0x368
        FLOAT m_sprintRecoveryTimer;                                    // 0x36C
        byte m_wasSprinting;                                            // 0x370
        byte m_isOccluded;                                                // 0x371
        ClientSoldierBoundsChecker* m_soldierBoundsChecker;                // 0x372
        PAD(0x2);                                                        // 0x376
        FLOAT m_criticalHealthThreshold;                                // 0x378
        public:

        ClientSoldierWeapon* GetCSW()
        {
            if(m_soldierWeaponsComponent)
                if(m_soldierWeaponsComponent->m_currentAnimatedWeaponHandler)
                    return m_soldierWeaponsComponent->m_currentAnimatedWeaponHandler->m_currentAnimatedWeapon;
            return NULL;
        }

        BOOL Alive()
        {
            if (POINTERCHK((CharacterEntity*)this->isAlive()))
                return this->isAlive();
            return FALSE;
        }
		BOOL IsAlive()
		{
			if (POINTERCHK((CharacterEntity*)this->isAlive()))
			{
				if (this->isAlive() == 34271745)
				{
					return true;
				}
			}
			return false;
		}
        BOOL ManDown()
        {
            //if(m_healthModule)
                return m_healthModule->isManDown();
        //    return FALSE;
        }
        BOOL GetVector(fb::Vec3* posBuffer)
        {
            if(posBuffer)
            {
                memcpy_s(posBuffer, sizeof(fb::Vec3), &(this->m_meshTransform.trans), sizeof(fb::Vec3));
                return TRUE;
            }

            return FALSE;
        }
    

     


        DWORD dwcomputeBoundingBox( AxisAlignedBox *aabb )
        {
            DWORD dwRet;
            DWORD ClientSoldierEntity_computeBoundingBox = 0x010C95F0;// 0x00C67E60 ;//0x53B160;//124B690;
            __asm
            {
                push 0 //wtf ever aabb seems to be at esp+8
                push aabb
                call ClientSoldierEntity_computeBoundingBox
                mov dwRet, eax
                pop eax //pop the 0
            }
            return dwRet;
        }

        DWORD dwcomputeBoundingBoxWorldTransform( LinearTransform *trans )
        {
            DWORD dwRet;
            DWORD ClientSoldierEntity_computeBoundingBoxWorldTransform = 0x010C6610;// 0x1248500;
            __asm
            {
                push trans
                call ClientSoldierEntity_computeBoundingBoxWorldTransform
                mov dwRet, eax
            }
            return dwRet;
        }

        __forceinline bool UpdateBones()
        {
                static DWORD dwUpdateBonesFn = UPDATEBONES;
                typedef void ( __thiscall* UpdateBonesFn )( ClientBoneCollisionComponent*, PVOID, ClientPlayer* );
                UpdateBonesFn UpdateBones = ( UpdateBonesFn ) 0x104B490;
                DWORD dwBoneCollision = ( DWORD )this->m_boneCollisionComponent;
                DWORD dwClassBase = **( DWORD** )( dwBoneCollision + 8 );
                if(dwClassBase)
                {
                    *( BYTE* )( dwClassBase + 475 ) = 0;
                    dwClassBase = *( DWORD* )( dwBoneCollision + 16 );
                    *( BYTE* )( dwClassBase + 40 ) = 1;
                     UpdateBones( this->m_boneCollisionComponent, NULL, this->m_player );
                     return true;
                }
                return false;
        }
        
    }; // 0x37C


};

#endif  
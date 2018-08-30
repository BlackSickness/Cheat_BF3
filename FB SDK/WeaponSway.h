#ifndef _WeaponSway_H
#define _WeaponSway_H
#include "Frostbite_Classes.h"
namespace fb
{
	class WeaponSway
	{
	public:
		struct WeaponFiringUpdateContext
        {
                union Flags
                {
                        struct
                        {
                                unsigned primaryFireTrigger : 1;
                                unsigned orderTrigger : 1;
                                unsigned reloadTrigger : 1;
                        };
 
                        unsigned int data;
                };
 
                Vec3 targetPos; //0x0000
                WeakPtr<ClientSoldierEntity> target; //0x0010
                WeaponSway* weaponSway; //0x0014
                float deltaTime; //0x0018
                float reloadTimeMultiplier; //0x001C
                float damageMultiplier; //0x0020
                float explosiveMultiplier; // 0x0024
                float overheatMultiplier; // 0x0028
                void* characterMelee; //0x002C
                unsigned int ticks; //0x0030
                // unfinished //
        };
 
        struct Random
        {
                unsigned int m_value;
                unsigned int m_tableIndex;
                float m_nextNormal;
                bool m_nextNormalIsValid;
        };

		class AbilityCallback
		{  
		public:
			virtual BOOL isFunctionOn(INT); 
			//LPVOID vftable;		// 0x00
		}; // 0x04

		class SuppressionCallback
		{
		public:
			virtual FLOAT getSuppressionValue();   
			//LPVOID vftable;		// 0x00
		}; // 0x04


		class SoldierAttributesCallback
		{
		public:
			
			    virtual CharacterPoseType getPose();                                                                    // V: 0x0
                virtual CharacterPoseType getChangingToPose();                                                  // V: 0x4
                virtual Vec3 getSoldierSpeed();                                                                  // V: 0x8
                virtual FLOAT getSoldierMaxSpeed();                                                                             // V: 0xC
                virtual BOOL isWeaponZoomed();                                                                                  // V: 0x10
                virtual SoldierEntityActionState actionState();                                                 // V: 0x14
                virtual FLOAT getYawInputLevel();                                                                               // V: 0x18
                virtual FLOAT getPitchInputLevel();                                                                             // V: 0x1C
                virtual FLOAT getStrafeInputLevel();                                                                    // V: 0x20
                virtual FLOAT getThrottleInputLevel();                                                                  // V: 0x24
                virtual UINT getSeed();                                                                                                 // V: 0x28
                virtual BOOL isSupported();                                                                                             // V: 0x2C
                virtual BOOL isWeaponLightEnabled();                                                                    // V: 0x30
                virtual void onDispersionUpdated();                                                                             // V: 0x34
                virtual BOOL isSprinting();                                                                                             // V: 0x38
                virtual AbilityCallback * getAbilityCallback();                         // V: 0x3C
                virtual SuppressionCallback * getSuppressionCallback();         // V: 0x40
    
			
			//LPVOID vftable;		// 0x00
		}; // 0x04

		public:
                virtual void function0(); //
                virtual void function1(); //
                virtual void function2(); //
                virtual void function3(); //
                virtual void function4(); //
                virtual void primaryFireShotSpawnedCallback( float powerModifier, bool trace, WeaponFiringUpdateContext *context); //
				virtual void function6(); //empty
				virtual void function7(); //
				virtual void function8(); //empty
				virtual void function9(); //empty
				virtual void function10(); //empty
				virtual void function11(); //empty
				virtual void function12(); //empty
				virtual void function13(); //empty
				virtual void function14(); //empty
				virtual void function15(); //empty
				virtual void function16(); //empty
				virtual void function17(); //empty
				virtual void function18(); //empty
				virtual void function19(); //empty
				virtual void function20(); //empty
				virtual void function21(); //empty
				virtual void unlockModifiers(const fb::WeaponModifier * wm); //22            // V: 0x60
                virtual void update(float f, const WeaponSway::SoldierAttributesCallback & scb);//23;      // V: 0x64
                virtual void getDispersion(D3DXMATRIX &, bool);   // V: 0x68
                virtual void getRecoil(D3DXMATRIX &, bool);             // V: 0x6C
                virtual void getCameraRecoil(D3DXMATRIX &);        // V: 0x70
                virtual void getLag(D3DXMATRIX &, bool);  // V: 0x74
                virtual float getDispersionFactor();           // V: 0x7C
                virtual float getDispersionAngle();            // V: 0x80
                virtual float getMinDispersionAngle();    // V: 0x84
                virtual float getSuppresionMinDispersionAngleFactor();                // V: 0x88
                virtual float getRecoilPitch();       // V: 0x8C
                virtual float getRecoilYaw();        // V: 0x90

				
                struct Deviation
                {
                        float m_pitch;
                        float m_yaw;
                        float m_roll;
                        float m_transY;
                };
 
                char pad0[168]; //0x0004
                Deviation m_currentRecoilDeviation; // 0x00AC
                float m_timeSinceLastShot; // 0x00BC
                DWORD m_cameraRecoilDeviation; //0x00C0
                float m_SpringPos; //0x00C4
                float m_SpringRestPos; //0x00C8
                float m_SpringVelocity; //0x00CC
                LinearTransform m_cameraRecoilTransform; //0x00D0
                Deviation m_currentLagDeviation; //0x0110
                float m_dispersionAngle; //0x0120
                float m_DeviationPitch; //0x0124
                float m_crossHairDispersionFactor; //0x0128
                Deviation m_currentDispersionDeviation; //0x012C
                float m_currentGameplayDeviationScaleFactor; //0x013C
                float m_currentVisualDeviationScaleFactor; //0x0140
                float m_suppressionMinDispersionAngleFactor; //0x0144
                Random m_Random; //0x0148
                unsigned int m_seed; //0x0158
                float m_randomAngle; //0x015C
                float m_randomRadius; //0x0160
                bool m_fireShot; //0x0164
                unsigned int m_initialFireShot; //0x0168
                bool m_isFiring; //0x016C


		static WeaponSway* Singleton()
		 {
			 return *(WeaponSway**)dwWEAPONSWAY;
		 }
	};


};

#endif
#ifndef _AnimatedWeaponGS_H
#define _AnimatedWeaponGS_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class AnimatedWeaponGS
	{
	public:
		class Read
		{
		public:
			FLOAT DisableZoomToggleWeight;		// 0x00
			INT AIAllowFire;					// 0x04
			INT AIAltFireFromAnt;				// 0x08
		}; // 0x0C

		class Write
		{
		public:
			CHAR Deploy;						// 0x00 
			CHAR AltDeploy;						// 0x01 
			CHAR Undeploy;						// 0x02 
			CHAR QuickSwitch;					// 0x03 
			CHAR Reload;						// 0x04 
			CHAR ReloadShotgun;					// 0x05 
			CHAR Fire;							// 0x06 
			CHAR FireSingle;					// 0x07 
			CHAR FireHoldAndRelease;			// 0x08 
			CHAR FireSimple;					// 0x09 
			CHAR FireShotSpawned;				// 0x0A 
			CHAR BoltAction;					// 0x0B 
			CHAR PumpAction;					// 0x0C 
			CHAR MeleeAttack;					// 0x0D 
			CHAR QuickThrow;					// 0x0E 
			PAD(0x1);							// 0x0F
			INT QuickThrowType;					// 0x10 
			CHAR AimBody;						// 0x14 
			CHAR AlwaysAimHead;					// 0x15 
			CHAR OneHanded;						// 0x16 
			CHAR OneHandedAiming;				// 0x17 
			CHAR AimingEnabled;					// 0x18 
			CHAR LowerGun;						// 0x19 
			CHAR BreathControl;					// 0x1A 
			CHAR RflType;						// 0x1B 
			CHAR PstlType;						// 0x1C 
			CHAR HgrType;						// 0x1D 
			CHAR ATType;						// 0x1E 
			CHAR ShgType;						// 0x1F 
			CHAR LMGType;						// 0x20 
			CHAR BagType;						// 0x21 
			CHAR SnpType;						// 0x22 
			CHAR Zoom;							// 0x23 
			FLOAT AimBodyWeight;				// 0x24 
			FLOAT ZoomParameter;				// 0x28 
			FLOAT ZoomScaleFactor;				// 0x2C 
			FLOAT Dispersion;					// 0x30 
			PAD(0xC);							// 0x34
			Vec3 AimTargetPosBody;				// 0x40 
			FLOAT ZoomOutSpeed;					// 0x50 
			FLOAT ZoomInSpeed;					// 0x54 
			FLOAT UnDeploySpeed;				// 0x58 
			FLOAT DeploySpeed;					// 0x5C 
			CHAR LightEnabled;					// 0x60 
			CHAR FireModeChanged;				// 0x61 Doesn't Update
			PAD(0x2);							// 0x62
			INT AnimType;						// 0x64 
			INT GunDown;						// 0x68 
			FLOAT NumberOfBulletsLeftInGun;		// 0x6C 
			CHAR BulletsLeftInGun;				// 0x70 
			CHAR WeaponActionESIG;				// 0x71 
			CHAR IsSprinting;					// 0x72 
			CHAR PreparingToBash;				// 0x73 
			INT JustStartedSprinting;			// 0x74 
			FLOAT KickBackInIronSight;			// 0x78 
			FLOAT ZoomingTime;					// 0x7C 
			INT TriggerZoomGunTwitch;			// 0x80 
			INT WeaponChooserSignal;			// 0x84 
			INT WeaponClassSignal;				// 0x88 
			FLOAT OffsetX;						// 0x8C 
			FLOAT OffsetY;						// 0x90 
			FLOAT OffsetZ;						// 0x94 
		}; // 0x98

		class Data
		{
		public:
			Read R;		// 0x00
			PAD(0x4);	// 0x0C
			Write W;	// 0x10
		}; // 0xA8

		Data m_data;		// 0x00
	}; // 0xA8

};

#endif
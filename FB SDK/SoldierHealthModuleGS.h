#ifndef _SoldierHealthModuleGS_H
#define _SoldierHealthModuleGS_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class SoldierHealthModuleGS
	{
	public:

		class Write
		{
			public:
			byte HeadShot;                     // this+0x0
			byte LeftArmHit;                     // this+0x1
			byte RightArmHit;                     // this+0x2
			byte LeftLegHit;                     // this+0x3
			byte RightLegHit;                     // this+0x4
			byte OnGround;                     // this+0x5
			byte DeathAnimationTriggered;                     // this+0x6
			int RandomAnimationIndex;                     // this+0x8
			byte Sprinting;                     // this+0xC
			byte HitLeft;                     // this+0xD
			byte HitRight;                     // this+0xE
			byte HitFront;                     // this+0xF
			byte HitBack;                     // this+0x10
			int DeathHitDirection;                     // this+0x14
			byte Explosion;                     // this+0x18
			byte Dead;                     // this+0x19
			byte Revived;                     // this+0x1A
			float RandomValue;                     // this+0x1C
			float Pose;                     // this+0x20
			float RightSpeed;                     // this+0x24
			float ForwardSpeed;                     // this+0x28
			byte CriticallyHit;                     // this+0x2C
			byte InteractiveManDown;                     // this+0x2D

		}; // Write

		class Data
		{
			public:
			struct fb::SoldierHealthModuleGS::Write W;                     // this+0x0

		}; // Data

		struct fb::SoldierHealthModuleGS::Data m_data;                     // this+0x0
																							
	}; // fb::SoldierHealthModuleGS

};

#endif
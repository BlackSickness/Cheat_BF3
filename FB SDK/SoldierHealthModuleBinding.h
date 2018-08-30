#ifndef _SoldierHealthModuleBinding_H
#define _SoldierHealthModuleBinding_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/AntRef.h"
namespace fb
{
	class SoldierHealthModuleBinding
	{

		class ArrayTypeInfo
			:public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{	
		}; // ArrayTypeInfo

		class ArrayTypeInfo_t :public fb::ArrayTypeInfo // Inherited class at offset 0x0
		{		
		}; 
		struct fb::AntRef m_headShot;                     // this+0x0
		struct fb::AntRef m_leftArmHit;                     // this+0x38
		struct fb::AntRef m_rightArmHit;                     // this+0x70
		struct fb::AntRef m_leftLegHit;                     // this+0xA8
		struct fb::AntRef m_rightLegHit;                     // this+0xE0
		struct fb::AntRef m_onGround;                     // this+0x118
		struct fb::AntRef m_deathAnimationTriggered;                     // this+0x150
		struct fb::AntRef m_randomAnimationIndex;                     // this+0x188
		struct fb::AntRef m_sprinting;                     // this+0x1C0
		struct fb::AntRef m_hitLeft;                     // this+0x1F8
		struct fb::AntRef m_hitRight;                     // this+0x230
		struct fb::AntRef m_hitFront;                     // this+0x268
		struct fb::AntRef m_hitBack;                     // this+0x2A0
		struct fb::AntRef m_deathHitDirection;                     // this+0x2D8
		struct fb::AntRef m_explosion;                     // this+0x310
		struct fb::AntRef m_dead;                     // this+0x348
		struct fb::AntRef m_revived;                     // this+0x380
		struct fb::AntRef m_randomValue;                     // this+0x3B8
		struct fb::AntRef m_pose;                     // this+0x3F0
		struct fb::AntRef m_rightSpeed;                     // this+0x428
		struct fb::AntRef m_forwardSpeed;                     // this+0x460
		struct fb::AntRef m_criticallyHit;                     // this+0x498
		struct fb::AntRef m_interactiveManDown;                     // this+0x4D0
	
	}; // fb::SoldierHealthModuleBinding



};

#endif
#ifndef _ClientSoldierSimulation_H
#define _ClientSoldierSimulation_H
#include "Frostbite_Classes.h"
namespace fb
{
	class ClientSoldierSimulation
	{
	public:
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual Vec3 position();	// V: 0x4
		virtual void setPosition(const struct fb::Vec3 &);	// V: 0x8
		virtual Vec3 surfaceVelocity();	// V: 0xC
		virtual const Vec3 & velocity();	// V: 0x10
		virtual float maxSpeed();	// V: 0x14
		virtual enum CharacterPoseType pose();	// V: 0x18
		virtual enum CharacterPoseType changingToPose();	// V: 0x1C
		virtual Vec3 aimingLocalPosition();	// V: 0x20
		virtual enum SoldierEntityActionState actionState();	// V: 0x24
		virtual bool isSprinting();	// V: 0x28
		virtual bool isJumping();	// V: 0x2C
		virtual bool nearBashableObject();	// V: 0x30
		virtual unsigned int groundMaterialIndex();	// V: 0x34
		virtual float ladderHeightClimbed();	// V: 0x3C
		virtual float ladderHeightLeft();	// V: 0x40
	//	LPVOID vftable;									// 0x00
		CharacterPhysicsEntity* m_characterEntity;		// 0x04
	}; // 0x08

};

#endif
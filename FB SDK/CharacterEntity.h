#ifndef _CharacterEntity_H
#define _CharacterEntity_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CharacterEntity
	{
	public:
		virtual FLOAT yaw();                                    // V:00
        virtual FLOAT pitch();                                    // V:04
        virtual BOOL isVisible();                                // V:08
        virtual BOOL isAlive();                                    // V:0C
        virtual BOOL isDead();                                    // V:10
        virtual BOOL isDying();                                    // V:14
        virtual FLOAT getHealth();                                // V:18
        virtual FLOAT maxeHealth();                                // V:1C
        virtual BOOL isAIPlayer();                                // V:20
        virtual BOOL isSingleplayer();                            // V:24
        virtual VOID getPhysicsInfoForAnimation(LPVOID, LPVOID); // V:28 getPhysicsInfoForAnimation(const struct fb::ant::AnimationUpdateArgs &, struct fb::CharacterAnimationPhysicsInfo &);	// V: 0x2
        virtual BOOL isInVehicle();                                // V:2C
		virtual PhysicsEntityBase * physics();	// V: 0x30
		virtual CharacterPoseType pose();	// V: 0x34
		virtual PersonViewEnum activeView();	// V: 0x38
		
	}; // 0x04

};

#endif
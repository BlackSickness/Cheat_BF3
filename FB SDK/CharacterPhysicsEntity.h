#ifndef _CharacterPhysicsEntity_H
#define _CharacterPhysicsEntity_H
#include "Frostbite_Classes.h"
#include "PhysicsEntityBase.h"
#include "CharacterPhysicsEntityContext.h"
namespace fb
{
	class CharacterPhysicsEntity
		: public PhysicsEntityBase									// 0x00
	{
	public:
		class CharacterInput
		{
		public:
			Vec3 m_forwardVector;		// 0x00
			Vec3 m_upVector;			// 0x10
			Vec3 m_characterGravity;	// 0x20
			FLOAT m_waterLevel;			// 0x30
			FLOAT m_speedScale;			// 0x34
			FLOAT m_yaw;				// 0x38
			FLOAT m_pitch;				// 0x3C
			FLOAT m_forwardInput;		// 0x40
			FLOAT m_strafeInput;		// 0x44
			FLOAT m_sprintMultiplier;	// 0x48
			CHAR m_tryJump;				// 0x4C
			CHAR m_changePose;			// 0x4D
			CHAR m_toggleParachute;		// 0x4E
			CHAR m_sprint;				// 0x4F
			LPVOID m_userData;			// 0x50
		}; // 0x54

		class CharacterPhysicsEntityPos
		{
		public:
			WeakPtr<CharacterPhysicsEntity> entity;		// 0x00
			PAD(0xC);									// 0x04
			Vec3 pos;									// 0x10
		}; // 0x20

		class OrientationCallback
		{
		public:
			virtual void setYaw(float);	// V: 0x0
			virtual float getYaw();	// V: 0x4
			virtual void setPitch(float);	// V: 0x8
			virtual float getPitch();	// V: 0xC
				
		}; // OrientationCallback

		PAD(0x8);						// 0x58
		hkpCharacterProxy* m_characterProxy;						// 0x60
		CharacterPhysicsEntityContext* m_characterContext;			// 0x64
		DWORD m_stateManager;										// 0x68
		DWORD m_phantom;											// 0x6C
		LinearTransform* m_gameWorldTransform;						// 0x70
		DWORD m_listener;											// 0x74
		PAD(0x4);													// 0x78
		CharacterPoseType m_currentPose;							// 0x7C
		CharacterPoseType m_changingToPose;							// 0x80
		FLOAT m_poseTransitionTimer;								// 0x84
		CharacterPhysicsEntityCollisionShapes* m_collisionShapes;	// 0x88
		CharacterPoseConstraints* m_poseConstraints;				// 0x8C
		CHAR m_enabled;												// 0x90
		CHAR m_isPhysicsControlled;									// 0x91
		CHAR m_aiBodyAddedToWorld;									// 0x92
		PAD(0xD);													// 0x93
		Vec3 m_currentLocalEyePosition;								// 0xA0
		FLOAT m_mass;												// 0xB0
		CharacterPhysicsData* m_data;								// 0xB4
		eastl::fixed_vector<CharacterPoseData*, 3, 2> m_poseData;	// 0xB8
		PAD(0x8);													// 0xD0
		EntityBusPeer* m_transformNode;								// 0xD8
		DWORD m_rbProxy;											// 0xDC
		DWORD m_aiBody;												// 0xE0
		DWORD m_contactMaterialIndex;								// 0xE4
		FLOAT m_dynamicFriction;									// 0xE8
		FLOAT m_staticFriction;										// 0xEC
		MaterialContainerPair* m_characterMaterials;				// 0xF0
		DWORD m_characterMaterialFlags;								// 0xF4
		PAD(0x8);													// 0xF8
		Vec3 m_ladderPosition;										// 0x100
		PAD(0x10);													// 0x110
		CharacterInput m_characterInput;							// 0x120
		PAD(0x1C);													// 0x174
		CharacterPhysicsEntityPos m_adjustedEntity[4];				// 0x190
		DWORD m_adjustCount;										// 0x210
		void getLocalBoundingBox(fb::AxisAlignedBox* out)
        {
            typedef void (__thiscall * R_getLocalBox)(fb::CharacterPhysicsEntity* pThis,fb::AxisAlignedBox* out);
            R_getLocalBox m_getLocalBox = (R_getLocalBox)0x5801A0;

            return m_getLocalBox(this,out);
        }

		void getLocalBoundingBoxForPose(AxisAlignedBox* out, /*enum  fb::CharacterPoseType*/int pose, bool expandWithVisualRepresentation = true)
        {
	
            typedef void (__thiscall * R_getLocalBoxForPose)(fb::CharacterPhysicsEntity* pThis, fb::AxisAlignedBox* out,/*enum  fb::CharacterPoseType*/ int pose,bool expandWithVisualRepresentation);
            R_getLocalBoxForPose m_getLocalBoxForPose = (R_getLocalBoxForPose)0x00589D40;

            return m_getLocalBoxForPose(this,out,pose,expandWithVisualRepresentation);
        }


	}; // 0x214

	
};

#endif
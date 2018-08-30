#ifndef _Parachute_H
#define _Parachute_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class SoldierParachuteGS
	{

		class Write
		{

			bool Enabled;                     // this+0x0
			float SteerLeftRight;                     // this+0x4
			float AccelerateBrake;                     // this+0x8
			float Pitch;                     // this+0xC
			float Roll;                     // this+0x10

		}; // Write

		class Data
		{

			struct fb::SoldierParachuteGS::Write W;                     // this+0x0

		}; // Data

		struct fb::SoldierParachuteGS::Data m_data;                     // this+0x0
					
	}; // fb::SoldierParachuteGS

	class ParachuteState
	{

		float disableTimer;                     // this+0x0
		float steerLeftRight;                     // this+0x4
		float accelerateBrake;                     // this+0x8
		float pitch;                     // this+0xC
		float roll;                     // this+0x10
		bool enabled;                     // this+0x14
		bool skyDive;                     // this+0x15

	}; // fb::ParachuteState

	class ClientSoldierParachuteComponent
	//	:public ClientComponent , // Inherited class at offset 0x0
	//			GameAnimatable::AnimationCallbackHandler  // Inherited class at offset 0x10
	{
	public:
		PAD(0x18);
		struct fb::ParachuteState m_parachuteState;                     // this+0x18
		class fb::SoldierParachuteGS m_gamestate;                     // this+0x30
		class fb::ClientAntAnimatableComponent * m_parachuteAnimatableComp;                     // this+0x44
		class fb::CharacterPhysicsEntity * m_characterEntity;                     // this+0x48
		class fb::ClientSoldierEntity * m_soldier;                     // this+0x4C
		class fb::AimingConstraints * m_parachuteAimingConstraints;                     // this+0x50
		class fb::ClientSoldierWeaponsComponent * m_weaponsComponent;                     // this+0x54
		struct fb::LinearTransform m_lastParachuteTransform;                     // this+0x60
		enum fb::CharacterStateType m_lastPhysicsState;                     // this+0xA0
		PAD(8);
		float m_previousYaw;                     // this+0xA4
		float m_previousPitch;                     // this+0xA8
		float m_deltaPitch;                     // this+0xAC
		float m_deltaYaw;                     // this+0xB0

	}; // fb::ClientSoldierParachuteComponent

};

#endif
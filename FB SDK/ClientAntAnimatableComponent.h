#ifndef _ClientAntAnimatableComponent_H
#define _ClientAntAnimatableComponent_H
#include "Frostbite_Classes.h"
namespace fb
{


	class Animatable
	{
	public:
		char _0x0000[24];
		fb::ant::UpdatePoseResultData m_updatePoseResultData; //0x0018 
		char _0x0040[40];

	};//Size=0x0068

	class SharedPose
	{
	public:
		char _0x0000[64];

	};//Size=0x0040

	class GameAnimatable
	{
	public:
		char _0x0000[196];
		Animatable* m_animatable; //0x00C4
		char _0x00C8[4];
		unsigned int m_animatableInstanceId; //0x00CC 
		bool m_hadVisualUpdate; //0x00D0 
		char _0x00D1[263];
		SharedPose m_sharedPose; //0x01D8 
		char _0x0218[8];
	};//Size=0x0220

	class AntAnimatableComponent
	{
	public:
		char _0x0000[0x20];
		GameAnimatable m_handler; //0x0020
	};

	class ClientAntAnimatableComponent 
		:public AntAnimatableComponent
	{
	public:
	};

};

#endif
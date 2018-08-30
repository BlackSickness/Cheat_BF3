#ifndef _CharacterPoseConstraints_H
#define _CharacterPoseConstraints_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class CharacterPoseConstraints
	{
	public:
		//LPVOID vftable;			// 0x00
		PAD(0x4);
		CHAR m_validPoses[4];	// 0x04
	}; // 0x08


};

#endif
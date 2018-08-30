#ifndef _CharacterStateData_H
#define _CharacterStateData_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	
	class CharacterStateData
		: public DataContainer							// 0x00
	{
	public:
		RefArray<CharacterStatePoseInfo> m_poseInfo;	// 0x08
	}; // 0x0C

};

#endif
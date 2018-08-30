#ifndef _EyePositionCallback_H
#define _EyePositionCallback_H
#include "Frostbite_Classes.h"
namespace fb
{
	class EyePositionCallback
	{
	public:
		//LPVOID vftable;			// 0x00
		virtual void localEyePosition(Vec3 &);	// V: 0x0
		virtual bool useLocalEyePosition();	// V: 0x4
		virtual void worldEyePosition(Vec3 &);	// V: 0x8
		virtual bool useWorldEyePosition();	// V: 0xC
	
	}; // 0x04

};

#endif
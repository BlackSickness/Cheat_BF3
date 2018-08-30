#ifndef _Input_H
#define _Input_H
#include "Frostbite_Classes.h"
namespace fb
{
	class Input
	{
	public:
		LPVOID vftable;				// 0x00
		InputNode* m_inputNode;		// 0x04
	}; // 0x08
};

#endif
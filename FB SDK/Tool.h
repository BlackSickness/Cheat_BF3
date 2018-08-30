#ifndef _Tool_H
#define _Tool_H
#include "Frostbite_Classes.h"
#include "ITypedObject.h"
namespace fb
{
	class Tool
		: public ITypedObject			// 0x00
	{
	public:
		WeaponData* m_firingData;		// 0x04
		CHAR m_isPlayerControlled;		// 0x08
		PAD(0x3);						// 0x09
	}; // 0xC

};

#endif
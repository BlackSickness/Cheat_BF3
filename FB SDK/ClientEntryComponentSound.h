#ifndef _ClientEntryComponentSound_H
#define _ClientEntryComponentSound_H
#include "Frostbite_Classes.h"
namespace fb
{
		class ClientEntryComponentSound
	{
			public:
		/*ISound **/void* m_stanceSwitchSound;                     // this+0x0
		int m_currentStance;                     // this+0x4
		int m_oldStance;                     // this+0x8
		bool m_triggerStanceChange;                     // this+0xC
		/*class fb::SmartRef<fb::EntryComponentSoundData>*/void* m_data;                     // this+0x10
		
	}; // fb::ClientEntryComponentSound
};

#endif
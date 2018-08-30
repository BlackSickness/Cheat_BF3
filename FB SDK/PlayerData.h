#ifndef _PlayerData_H
#define _PlayerData_H

//#include "../Frostbite_classes.h"

namespace fb
{

		class PlayerData
		: public Asset								// 0x00
	{
	public:
		DataContainer* m_playerView;				// 0x0C
		DataContainer* m_inputConceptDefinition;	// 0x10
		DataContainer* m_inputMapping;				// 0x14
	}; // 0x18

};

#endif
#ifndef _ClientSoldierBodyComponent_H
#define _ClientSoldierBodyComponent_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class SoldierBodyComponent // Inherited class at offset 0x10
	{
		bool m_freezeSoldier;                     // 0x0
		bool m_changePosePressed;                     // 0x1
	}; // fb::SoldierBodyComponent

	class ClientSoldierBodyComponent
		:public ClientComponent , 
				SoldierBodyComponent
	{
	public:
		LPVOID vTable;
	}; // fb::ClientSoldierBodyComponent

};

#endif
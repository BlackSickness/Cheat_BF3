
#ifndef _SOCKETDATA_H
#define _SOCKETDATA_H

#include "Frostbite_classes.h"

//#include <Windows.h>
//#include <math.h>

namespace fb
{

	class SocketData
		:public DataContainer
	{
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x4

		LinearTransform m_boneRigidTransform;                     // this+0x10
		LinearTransform m_transform;                     // this+0x50
		CtrRefBase m_unlockAsset;                     // this+0x90
		int m_boneId;                     // this+0x94
		String m_boneName;                     // this+0x98
		RefArray<fb::SocketObjectDataBase> m_availableObjects;                     // this+0x9C
		GearSlot m_gearSlot;                     // this+0xA0
		SocketType m_socketType;                     // this+0xA4
		bool m_usesDefaultObject;                     // this+0xA8
		bool m_excluded;                     // this+0xA9
		bool m_defaultEnableSocketEntities;                     // this+0xAA
		bool m_forceSocketEntitiesEnabled;                     // this+0xAB
		bool m_hideByZoomTransition;                     // this+0xAC
		bool m_hideByLightToggle;                     // this+0xAD
		String m_socketName;                     // this+0xB0
		

	}; // fb::SocketData

};

#endif
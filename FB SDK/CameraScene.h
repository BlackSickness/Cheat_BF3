#ifndef _CameraScene_H
#define _CameraScene_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CameraScene
	{
	public:
		CameraManager* m_manager;							// 0x00
	//	eastl::map<UINT, Camera*> m_cameras;				// 0x04
		eastl::map<unsigned int,Camera *,eastl::less<unsigned int>,eastl_arena_allocator> m_cameras;// this+0x4
		//eastl::map_node<UINT, Camera*>* m_activeCamera;		// 0x1C
		eastl::rbtree_iterator<eastl::pair<unsigned int const ,Camera *>,eastl::pair<unsigned int const ,Camera *> *,eastl::pair<unsigned int const ,fb::Camera *> &> m_activeIterator;                     // this+0x1C
	}; // 0x20

};

#endif
#ifndef _CameraManager_H
#define _CameraManager_H
#include "Frostbite_Classes.h"
namespace fb
{
	class CameraManager
	{
	public:
		//LPVOID vftable;			// 0x00
		virtual void pop(class fb::CameraScene *);	// V: 0x0
		virtual void onCameraRemovedFromScene();	// V: 0x4
		virtual void getTransform(struct fb::LinearTransform &);	// V: 0x8
		virtual float getFov();	// V: 0xC
		virtual void setFovEffect(const class fb::FovEffect &);	// V: 0x10
		virtual class fb::Camera * getActiveCamera();	// V: 0x14
	}; // 0x04

};

#endif
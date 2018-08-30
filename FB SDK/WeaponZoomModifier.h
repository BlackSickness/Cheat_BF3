#ifndef _WeaponZoomModifier_H
#define _WeaponZoomModifier_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponModifierBase.h"
namespace fb
{
	class WeaponZoomModifier
		: public WeaponModifierBase		// 0x00
	{
	public:
		FLOAT m_zoomRenderFov;			// 0x08
	}; // 0x0C

};

#endif
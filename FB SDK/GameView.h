#ifndef _GameView_H
#define _GameView_H
#include "Frostbite_Classes.h"
#include "TargetCameraCallback.h"
namespace fb
{
	class GameView
		: public TargetCameraCallback		// 0x00
	{
	public:
		class EntryUnSpawnCallback
			: public EntryComponent::Subscriber		// 0x00
		{
		public:
			GameView* m_gameView;					// 0x04
			EntryComponent* m_entry;				// 0x08
		}; // 0x0C

		INT m_currentGameplayCameraId;		// 0x04
	}; // 0x08

};

#endif
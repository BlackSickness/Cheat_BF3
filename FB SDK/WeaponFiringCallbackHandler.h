#ifndef _WeaponFiringCallbackHandler_H
#define _WeaponFiringCallbackHandler_H
#include "Frostbite_Classes.h"
namespace fb
{
	
	class WeaponFiringCallbackHandler
	{
	public:
		class Event
		{
		public:
			WeaponFiringEvent call;	// 0x00
			FLOAT powerModifier;	// 0x04
			DWORD ticks;			// 0x08
			CHAR trace;				// 0x0C
			CHAR detonatorActive;	// 0x0D
			CHAR needUpdate;		// 0x0E
			PAD(0x1);				// 0x0F
		}; // 0x10
		PAD(0x4);
		eastl::fixed_list<fb::WeaponFiringCallbacks *,8,0,fb::eastl_arena_allocator> m_callbackHandlers;                     // this+0x4
		enum Action
		{

			 Add,// constant 0x0
			 Remove // constant 0x1

		}; // Action

		class Command
		{

			WeaponFiringCallbackHandler::Action action;                     // this+0x0
			WeaponFiringCallbacks * callbacks;                     // this+0x4

		}; // Command

		class IterationScope
		{

			eastl::vector<WeaponFiringCallbackHandler::Command,eastl_arena_allocator> commands;                     // this+0x0
			unsigned int depth;                     // this+0x10
				
		}; // IterationScope

		WeaponFiringCallbackHandler::IterationScope * m_activeIterationScope;                     // this+0x88
		//maybe pad 4 more
		//LPVOID vftable;		// 0x00
		//PAD(0x88);			// 0x04
	}; // 0x8C

};

#endif
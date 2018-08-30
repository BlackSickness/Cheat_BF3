#ifndef _ClientControllableEntity_H
#define _ClientControllableEntity_H
#include "Frostbite_Classes.h"
#include "ClientGhostAndNetworkableGameEntity.h"
#include "ControllableEntity.h"
namespace fb
{
	class ClientControllableEntity
		: public ClientGhostAndNetworkableGameEntity,			// 0x00
		public ControllableEntity								// 0x70
	{
	public:
		/*
		virtual bool updateAsynchronously();	// V: 0x128
		class eastl::vector<fb::ClientEntryComponent *,fb::eastl_arena_allocator> m_entries;                     // 0xB0
		virtual void pushCorrectionState(unsigned int);	// V: 0x13C
		virtual void setCorrectionState(unsigned int, class fb::IBitStreamRead *, class fb::ControlObjectState *, const class fb::ControlObjectState *);	// V: 0x140
		virtual void readCorrectionState(unsigned int, class fb::IBitStreamRead *, class fb::ControlObjectState *, const class fb::ControlObjectState *);	// V: 0x144
		virtual void prePhysicsUpdateCorrectionState(unsigned int, const class fb::EntryInput &);	// V: 0x148
		virtual void postPhysicsUpdateCorrectionState(unsigned int, const class fb::EntryInput &);	// V: 0x14C
		virtual void correctPredictionState(unsigned int, bool);	// V: 0x150
		virtual void popCorrectionState(unsigned int);	// V: 0x154
		*/
		eastl::vector<ClientEntryComponent*> m_entries;			// 0x80
		DWORD m_currentVelocityNormalizedOut;					// 0x90 PropertyWriter<FLOAT>
		DWORD m_currentHealthNormalizedOut;						// 0x94 PropertyWriter<FLOAT>
		FLOAT m_oldVelocity;									// 0x98
		FLOAT m_oldHealth;										// 0x9C
		ClientSpawnEntity* m_owner;								// 0xA0
		DWORD m_correctionTask;									// 0xA4
		DWORD m_remoteGhostId;									// 0xA8
		DWORD m_correctingEntry;								// 0xAC
		CHAR m_predictionEnabled;								// 0xB0
		CHAR m_correctionEnabled;								// 0xB1
		CHAR m_isCorrecting;									// 0xB2
		PAD(0x1);												// 0xB3
		
		__forceinline Vec3* getVehicleSpeed()
		{
			return (Vec3*)((DWORD)this + 0x0140);
		}

		__forceinline float* getVehicleHealth()
		{
			return (float*)((DWORD)this + 0x009C);
		}

		ClientVehicleEntityHealth* getVehicleMaxHealth()
		{
			return (ClientVehicleEntityHealth*)((DWORD)this + 0x200);
		}

		ClientSpottingTargetComponent* getFirstComponentOfType(bool bUnk)
		{
			typedef ClientSpottingTargetComponent* (__thiscall *tgetFirstComponentOfType)(fb::ClientControllableEntity *pThis, bool bBool);  
			tgetFirstComponentOfType getSpottingTargetComponent = ( tgetFirstComponentOfType )MINIMAP; //0x00A01EA0; // 0xXX4F6E0
			return getSpottingTargetComponent(this,bUnk);
		}
	}; // 0xB4


};

#endif
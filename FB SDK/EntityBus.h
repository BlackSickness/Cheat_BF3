#ifndef _EntityBus_H
#define _EntityBus_H

namespace fb
{
	class EntityBus
		:public PropertyModificationListener // Inherited class at offset 0x0
	{
	public:
		

		class QueryConnectionRecord
		{

			const DataContainer * data;                     // this+0x0
			EntityBusPeer * peer;                     // this+0x4
			int targetEventId;                     // this+0x8

		}; // QueryConnectionRecord

		virtual bool isRegistered(const class DataContainer *);	// V: 0x14
		virtual void fireEvent(const class DataContainer *, const class fb::EntityEvent *);	// V: 0x18
		virtual void registerPeer(const class DataContainer *, EntityBusPeer *);	// V: 0x20
		virtual void deregisterPeer(const class DataContainer *, EntityBusPeer *);	// V: 0x24
		virtual void queryConnections(const class DataContainer *, int, class eastl::fixed_vector<EntityBus::QueryConnectionRecord,128,1,eastl_arena_allocator> &);	// V: 0x28
		virtual struct DataContext dataContext();	// V: 0x30
		virtual const ReferenceObjectData * parentRepresentative();	// V: 0x34

		virtual EntityBusPeer * convertDataToEntity(const DataContainer *, bool);	// V: 0x3C
		virtual void internalGetWorldTransform(LinearTransform &);	// V: 0x40
		virtual bool registerListener(const class fb::DataContainer *, PropertyModificationListener *, Realm);	// V: 0x44
		virtual void deregisterListener(const class fb::DataContainer *, PropertyModificationListener *, Realm);	// V: 0x48
		virtual bool parentPropertiesCanChange();	// V: 0x4C
		virtual void getDebugName(StringBuilderBase &);	// V: 0x54
		virtual void* getDataBus();	// V: 0x58
		
	//	LPVOID vftable;							// 0x00
		SubLevel* m_subLevel;					// 0x04
		EntityBus* m_parentBus;					// 0x08
		INT m_dataId;							// 0x0C
		INT m_refCount;							// 0x10
		INT m_networkId;						// 0x14
		SHORT m_realm;							// 0x18
		CHAR m_parentPropertiesCanChange;		// 0x1A
		PAD(0x1);								// 0x1B
	}; // 0x1C

};

#endif
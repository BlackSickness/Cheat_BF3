#ifndef _IPhantom_H
#define _IPhantom_H

namespace fb
{
	class IPhantomHook
	{
		public:
		//virtual void * __vecDelDtor(unsigned int);	// V: 0x0

	}; // fb::IPhantomHook
 
	class IPhantom // Inherited class at offset 0x0
	{
//		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void addHook(IPhantomHook *);	// V: 0x4
		virtual void removeHook(IPhantomHook *);	// V: 0x8
		virtual unsigned int getOverlappingCount();	// V: 0xC
		virtual bool getIsDirty();	// V: 0x10
		PhysicsEntityUserData m_physicsUserData;   // 0x10
		class eastl::basic_string<char,eastl_arena_allocator> m_name;             // 0x30

		ITypedObject * m_userData;                     // 0x40
		

	}; // fb::IPhantom

	class IPhantomBox :public IPhantom
	{
	//	virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void setAxisAlignedBox(const struct fb::AxisAlignedBox &);	// V: 0x14
		virtual const struct AxisAlignedBox & getAxisAlignedBox();	// V: 0x18
	}; // fb::IPhantomBox


    class IPhantomShape :public IPhantom
    {
    public:
	//	virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual unsigned int getPenetrationCount();	// V: 0x14

    };


};

#endif
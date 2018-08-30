#ifndef _IHavok_H
#define _IHavok_H

namespace fb
{

	class IHavokRenderObject
	{
		virtual void * __vecDelDtor(unsigned int);	// V: 0x0
		virtual void render();	// V: 0x4
		virtual void describe(StringStream &);	// V: 0x8
		PhysicsEntityBase * m_physicsEntity;                     // this+0x4
		bool m_alwaysRender;                     // this+0x8
			
	}; // fb::IHavokRenderObject
 

};

#endif
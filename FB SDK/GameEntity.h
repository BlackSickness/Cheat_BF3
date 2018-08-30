#ifndef _GameEntity_H
#define _GameEntity_H
#include "Frostbite_Classes.h"
#include "SpatialEntityWithBusAndData.h"
namespace fb
{
	
	class GameEntity
		: public SpatialEntityWithBusAndData<GameEntityData>	// 0x00
	{
	public:
		DWORD m_updateInterval;									// 0x18
		ComponentCollection* m_collection;						// 0x1C

		template<class T>
		T *getComponent( std::string name ) 
		{
			if( !m_collection || !(( m_flags >> 15 ) & 1 ) ) 
				return NULL;
			for( int i = 0; i < m_collection->totalCount; i++ ) 
			{
				fb::ComponentInfo *info = m_collection->getInfo( i );
				if( !info || !info->flags >> 15 || !info->component )
					continue;

				fb::TypeInfo *tinfo = info->component->getType( );

			//	LOG.Write("%s",tinfo->m_infoData->name);

				if( !std::string( tinfo->m_infoData->name ).compare( name ) ) 
					return (T *)info->component;
			}
			return NULL;
		}

		//LinearTransform * m_worldTransform;                     // 0x1C
	}; // 0x20

};

#endif
#ifndef _WeaponEntityData_H
#define _WeaponEntityData_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/WeaponName.h"
namespace fb
{
	class WeaponEntityData
	{
	public:
		PAD(0x84);									// 0x00
		WeaponClassEnum m_weaponClass;				// 0x84
		PAD(0xA4);									// 0x88
		WeaponName * m_namePtr;						//0x12C

		__forceinline char *GetWeaponName()
        { 
            static char szWeaponName[20] = {0}; 
            bool asdf = false; 
			bool Slash = false;

			const char *name = m_namePtr->m_name.c_str();

			if( name ) 
			{ 
				for( int i = 0, j = 0; i < (int)strlen(name); i++ ) 
				{ 
					if( asdf && name[i] == '_' ) 
					{ 
						szWeaponName[j] = 0; 
						break; 
					} 

					if( name[i] == '/' && !asdf ) 
					{ 
						if(!Slash)
						{
							Slash = true;
							continue;
						}
						asdf = true; 
						continue; 
					} 

					if( asdf )
					{ 
						szWeaponName[j] = name[i]; 
						j++; 
					} 
				} 
			}
			return szWeaponName;
        } 
	};

};

#endif
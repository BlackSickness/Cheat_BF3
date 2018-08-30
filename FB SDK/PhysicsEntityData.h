#ifndef _PhysicsEntityData_H
#define _PhysicsEntityData_H
#include "Frostbite_Classes.h"
#include "EntityData.h"
#include "HavokAsset.h"
namespace fb
{
	class PhysicsEntityData
		: public EntityData						// 0x00
	{
	public:
		PAD(0x4);								// 0x0C
		Vec3 m_intertiaModifier;				// 0x10
		RefArray<HavokAsset> m_scaledAssets;	// 0x20
		RefArray<DWORD> m_rigidBodies;			// 0x24
		DataContainer* m_asset;					// 0x28
		DataContainer* m_floatPhysics;			// 0x2C
		FLOAT m_mass;							// 0x30
		FLOAT m_restitution;					// 0x34
		FLOAT m_friction;						// 0x38
		FLOAT m_linearVelocityDamping;			// 0x3C
		FLOAT m_angularVelocityDamping;			// 0x40
		DataContainer* m_proximity;				// 0x44
		RefArray<DWORD> m_constraints;			// 0x48
		CHAR m_encapsulatePartsInLists;			// 0x4C
		CHAR m_movableParts;					// 0x4D
		PAD(0x2);								// 0x4E
		//new

		__forceinline char *GetLongName()
        { 
			HavokAsset *pAsset = m_scaledAssets.At(0);

			if(pAsset == NULL) return "";

			char *name = pAsset->m_name.GetString();

			if( name ) 
				return name;
        } 
		
		__forceinline char *GetObjectName()
        { 
            static char szVehicleName[20] = {0}; 
            bool asdf = false; 
			bool WaitforFirstSlash = false;

			HavokAsset *pAsset = m_scaledAssets.At(0);

			if(pAsset == NULL) return "";

			char *name = pAsset->m_name.GetString();

			if( name ) 
			{ 
				for( int i = 0, j = 0; i < (int)strlen(name); i++ ) 
				{ 
					if( asdf && (name[i] == '/' || name[i] == '_' || name[6] == 'A')  )
					{ 
						szVehicleName[j] = 0; 
						break; 
					} 

					if( name[i] == '/' && !asdf ) 
					{ 
						asdf = true; 
						continue; 
					} 

					if( asdf ) 
					{ 
						szVehicleName[j] = name[i]; 
						j++; 
					} 
				} 
			} 

			//if(strcmp(szVehicleName, "XPack01") != 0 && strcmp(szVehicleName, "XP3") != 0 && strcmp(szVehicleName, "XP4") != 0 && strcmp(szVehicleName, "XP5") != 0) return szVehicleName;

			if(szVehicleName[0] != 'X') return szVehicleName;

			asdf = false;
			name = pAsset->m_name.GetString();

			if( name ) 
			{ 
				for( int i = 0, j = 0; i < (int)strlen(name); i++ ) 
				{ 
					if( asdf && name[i] == '/' || name[i] == '_') 
					{ 
						szVehicleName[j] = 0; 
						break; 
					} 

					if( name[i] == '/' && !asdf ) 
					{ 
						if(!WaitforFirstSlash)
						{
							WaitforFirstSlash = true;
							continue;
						}
						asdf = true; 
						continue; 
					} 

					if( asdf ) 
					{ 
						if(name[i] == '-' )
							szVehicleName[j] = 0; 
						else
							szVehicleName[j] = name[i]; 
						j++; 
					} 
				} 
			}
			return szVehicleName;
        } 

	}; // 0x50




};

#endif
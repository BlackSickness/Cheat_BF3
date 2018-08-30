#ifndef _HavokPhysicsData_H
#define _HavokPhysicsData_H
#include "Frostbite_Classes.h"
#include "TntObject.h"
namespace fb
{
	class HavokPhysicsData
		: public TntObject<IResourceObject>
	{
	public:
		class LoadedData
		{
		public:
			DWORD partCount;							// 0x00
			RelocArray<Vec3> partTranslations;			// 0x04
			PAD(0x4);									// 0x0C
			RelocArray<AxisAlignedBox> localAabbs;		// 0x10
			PAD(0x4);									// 0x18
			RelocArray<BYTE> materialIndices;			// 0x1C
			PAD(0x4);									// 0x24
			RelocArray<UINT> materialFlagsAndIndices;	// 0x28
			FLOAT scale;								// 0x34
			BYTE materialCountUsed;						// 0x38
			BYTE highestMaterialIndex;					// 0x39
			PAD(0x2);									// 0x3A
		}; // 0x3C

		MemoryArena* m_arena;				// 0x08
		LoadedData* m_loadedData;			// 0x0C
		LPVOID m_nativeData;				// 0x10
		INT m_nativeDataSize;				// 0x14
		DWORD m_rootContainer;				// 0x18
		LPUINT m_materialFlagsAndIndices;	// 0x1C
		UINT m_runtimeFlags;				// 0x20
	}; // 0x24



};

#endif
#ifndef _SafeQueryResult_H
#define _SafeQueryResult_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	cclass SafeQueryResult
	{
	public:
		QueryResult * queryResult;                     // 0x0
		EntityGridQueryJobData::QueryDetail queryDetail;                     // 0x4
		int resultCount;                     // 0x8
		int entityPtrIsValid;                     // 0xC, len(0x1)
		int isMarkedForRelease;                     // 0xD, len(0x1)
		/*ConstWeakPtr<SpatialEntity> */ DWORD safeEntity;                     // 0x10
		const char * ident;                     // 0x14	
	}; // fb::SafeQueryResult
};

#endif
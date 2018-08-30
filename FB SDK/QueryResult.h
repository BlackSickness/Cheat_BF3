#ifndef _QueryResult_H
#define _QueryResult_H

namespace fb
{
	class QueryResult
    {
    public:
		PhysicsEntityBaseRayCast::RayCastOutput rayCastOutput;// 0x0
		SpatialEntity * entity;          // 0x20
        CHAR isDone;                     // 0x24
        CHAR hasHit;                     // 0x25
        unsigned char pad[0xA];          // 0x26

    }; // fb::QueryResult

};

#endif
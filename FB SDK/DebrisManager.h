#ifndef _DebrisManager_H
#define _DebrisManager_H

namespace fb
{
	class DebrisManager
    {
    public:
        char _0x0000[4];
        int m_refCount; //0x0004 
        char _0x0008[100];
        float m_time; //0x006C 
        int m_frameCount; //0x0070 
        int m_totalPartsSpawnedCount; //0x0074 
       DWORD m_currentScheduledPartsCount; 
	   char _0x007C[4];
	   MemoryArena* m_debrisArena; 
	   DebrisSystemSettings* m_settings;


    };//Size=0x00F4
};

#endif
#ifndef _TypeInfo_H
#define _TypeInfo_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
	class TypeInfo
    {
    public:
        class TypeInfoData
        {
        public:
            const char *name; //0x0
            unsigned short flags; //0x4
            unsigned short totalSize; //0x6
            ModuleInfo *module; //0x8
            unsigned char alignment; //0xC
            unsigned char fieldCount; //0xD
            unsigned char pad[2]; //0xE
        };
        TypeInfoData *m_infoData;
        TypeInfo *m_pNext; //0x4
        unsigned short m_runtimeId; //0x8
        unsigned short m_flags; //0xA

        TypeInfoData *getTypeInfoData( ) {
            return (TypeInfoData *)m_infoData;
        }
    };

};

#endif
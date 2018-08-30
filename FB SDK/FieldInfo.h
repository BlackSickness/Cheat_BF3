#ifndef _FieldInfo_H
#define _FieldInfo_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/MemberInfoFlags.h"
namespace fb
{
	class FieldInfo
    {
    public:
        virtual unsigned int getFieldIndex();    // V: 0x4
        class FieldInfoData
        {
        public:
            const char * name;                     // this+0x0
            MemberInfoFlags flags;                     // this+0x4
            unsigned short fieldOffset;                     // this+0x6
            const class TypeInfo * fieldTypePtr;                     // this+0x8

        }; // FieldInfoData
    }; // fb::FieldInfo

};

#endif
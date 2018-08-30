#ifndef _ClassInfo_H
#define _ClassInfo_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/TypeInfo.h"
namespace fb
{
	
	 class ClassInfo
        : TypeInfo
    {
        public:
        class ClassTypeInfoData
        {
        public:
            TypeInfo::TypeInfoData basicInfo;                     // this+0x0
            const class ClassInfo * superClass;                     // this+0x10
            void *createFun;                     // this+0x14
            FieldInfo::FieldInfoData * fields;                     // this+0x18
        }; // TypeInfoData
        const class ClassInfo * m_super;                     // this+0xC
        class DataContainer * m_defaultInstance;                     // this+0x10
        unsigned short m_classId;                     // this+0x14
        unsigned short m_lastSubClassId;                     // this+0x16
        enum
        {

            kInternalFlags_DerivedFromDataContainer                     // constant 0x1

        };

        class ParseState
        {
            public:
            const char * strPtr;                     // this+0x0
            char pad[0x318];// this+0x4
            bool tagged;                     // this+0x31C
                        
        }; // ParseState

        const class ClassInfo * m_firstDerivedClass;                     // this+0x18
        const class ClassInfo * m_nextSiblingClass;                     // this+0x1C
        FieldInfoImpl * const * m_fieldInfos;                     // this+0x20
        unsigned int m_totalFieldCount;                     // this+0x24

        ClassTypeInfoData *getClassTypeInfoData( ) {
            return (ClassTypeInfoData *)m_infoData;
        }
    }; // fb::ClassInfo

};

#endif
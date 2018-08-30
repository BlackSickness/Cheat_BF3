#ifndef _MESSAGELISTENER_H
#define _MESSAGELISTENER_H
#include "FB SDK/Frostbite_Classes.h"
namespace fb
{
		class VeniceClientPlayerExtent 
    {
    public:
        PAD(0x4C);
        SquadId m_squadId;
        bool    m_isSquadLeader;
        bool    m_isSquadPrivate;
        bool    m_isAllowedToSpawnOn;
        bool    m_isAdmin;
        char __0x0054[0x1C];
        char    m_name[64];
    }; // Shorted the class

};

#endif
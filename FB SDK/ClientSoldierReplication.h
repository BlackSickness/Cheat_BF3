#ifndef _ClientSoldierReplication_H
#define _ClientSoldierReplication_H
#include "FB SDK/Frostbite_Classes.h"
#include "FB SDK/ClientSoldierSimulation.h"
namespace fb
{  
	
    class ClientSoldierReplication
        : public ClientSoldierSimulation    // 0x00
    {
    public: 
		class State
        {
        public:
            Vec3 parachuteRotation;            // 0x00
            Vec3 position;                    // 0x10
            Vec3 surfaceVelocity;            // 0x20
            Vec3 velocity;                    // 0x30
            Vec3 groundNormal;                // 0x40
            DWORD groundSupported;            // 0x50
            DWORD groundMaterialIndex;        // 0x54
            INT state;                        // 0x58
            INT pose;                        // 0x5C
            INT changingToPose;                // 0x60
            PAD(0x4);                        // 0x64
            FLOAT groundHeight;                // 0x68
            FLOAT ladderHeightClimbed;        // 0x6C
            FLOAT ladderHeightLeft;            // 0x70
            PAD(0x4);                        // 0x74
            INT actionState;                // 0x78
        }; // 0x7C
      
		DWORD m_interpolator;            // 0x08
        PAD(0x4);                        // 0x0C
        State m_state;                    // 0x10
      
    }; // 0x8C
		
};

#endif  
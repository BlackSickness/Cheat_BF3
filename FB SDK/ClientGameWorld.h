#ifndef _ClientGameWorld_H
#define _ClientGameWorld_H
#include "FB SDK/GameWorld.h"
namespace fb
{
	class ClientGameWorld : public GameWorld //, public IPhysicsRayCaster
    {
    public:
 
        __declspec(noinline) static ClientGameWorld* Singleton()
        {
            return ( ClientGameWorld* ) GameWorld::Singleton();
        }
    };

};

#endif
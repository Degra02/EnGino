#ifndef PHYSICSENGINE_SWEEPANDPRUNE_H
#define PHYSICSENGINE_SWEEPANDPRUNE_H


#include <vector>
#include "Object.h"

namespace pheng {
    class SweepAndPrune {
    public:
        static std::vector<Object*> getPossibleCollisions(std::vector<Object*> worldObjects);
        static bool sortByXLeft(Object* o1, Object* o2);
        static void checkEffectiveCollisions(Object* o1, Object* o2, std::vector<Object*> activeList);
    };
}



#endif //PHYSICSENGINE_SWEEPANDPRUNE_H

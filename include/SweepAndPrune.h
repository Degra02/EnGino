#ifndef PHYSICSENGINE_SWEEPANDPRUNE_H
#define PHYSICSENGINE_SWEEPANDPRUNE_H


#include <vector>
#include "Object.h"
#include "Collisions.h"
#include "PairsList.h"

namespace pheng {
    class SweepAndPrune {
    public:
        static void calculateCollisions(std::vector<Object*> worldObjects, float r_c);
        static PairsList<Object*>* getPossibleCollisions(std::vector<Object*> worldObjects, float r_c);
        static bool sortByXLeft(Object* o1, Object* o2);
    };
}



#endif //PHYSICSENGINE_SWEEPANDPRUNE_H

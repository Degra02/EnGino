#ifndef PHYSICSENGINE_COLLISIONS_H
#define PHYSICSENGINE_COLLISIONS_H

#include "Circle.h"

namespace pheng {

    class Collisions {
    public:
        static bool objToObj(Object* o1, Object* o2);
        static bool circleToCircle(Circle* s1, Circle *s2);
    };

}

#endif //PHYSICSENGINE_COLLISIONS_H

#ifndef PHYSICSENGINE_COLLISIONS_H
#define PHYSICSENGINE_COLLISIONS_H

#include "Circle.h"

namespace phy_eng {

    class Collisions {
    public:
        static bool sphereToSphere(Circle* s1, Circle *s2);
    };

}

#endif //PHYSICSENGINE_COLLISIONS_H

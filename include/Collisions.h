#ifndef PHYSICSENGINE_COLLISIONS_H
#define PHYSICSENGINE_COLLISIONS_H

#include "Sphere.h"

namespace phy_eng {

    class Collisions {
    public:
        static bool sphereToSphere(Sphere* s1, Sphere *s2);
    };

}

#endif //PHYSICSENGINE_COLLISIONS_H

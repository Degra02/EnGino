#ifndef PHYSICSENGINE_SPHERECOLLIDER_H
#define PHYSICSENGINE_SPHERECOLLIDER_H

#include "Collider.h"
#include "Sphere.h"

namespace phy_eng {

    class SphereCollider : public Collider{
    public:
        bool sphereToSphere(Sphere* current, Sphere* s2);
    };

} // phy_eng

#endif //PHYSICSENGINE_SPHERECOLLIDER_H

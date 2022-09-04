#include "../../include/Collisions.h"

namespace phy_eng {

    bool Collisions::sphereToSphere(Circle* s1, Circle* s2) {
        if ( vector2::norm(s1->getCenterPos(), s2->getCenterPos()) < s1->getRadius() + s2->getRadius())
            return true;
        return false;
    }

} // phy_eng

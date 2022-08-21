#include "../../include/SphereCollider.h"

namespace phy_eng {
    bool SphereCollider::sphereToSphere(Sphere* current, Sphere* s2) {
        if ( vector2::norm(current->getCenterPos() - s2->getCenterPos()) < current->getRadius())
            return true;
        return false;
    }
} // phy_eng
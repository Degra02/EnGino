#include "../../include/Collisions.h"
#include <typeinfo>

namespace phy_eng {

    bool Collisions::objToObj(Object *o1, Object *o2) {
        if(typeid(o1) == typeid(Circle)){
            if(typeid(o2) == typeid(Circle))
                return circleToCircle(dynamic_cast<Circle*>(o1), dynamic_cast<Circle*>(o2));
            else if (typeid(o2) == typeid(phy_eng::Rectangle)){

            }
        } else if (typeid(o1) == typeid(Rectangle)){
            // All the other collisions
        }
    }

    bool Collisions::circleToCircle(Circle* s1, Circle* s2) {
        //vector2 collisionLine = vector2::twoPoints(s1->getPosition(), s2->getPosition());

        if ( vector2::norm(s1->getCenterPos(), s2->getCenterPos()) < s1->getRadius() + s2->getRadius())
            return true;
        return false;
    }

} // phy_eng

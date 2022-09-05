#include "../../include/Collisions.h"
#include <typeinfo>
#include <cmath>

namespace pheng {

    bool Collisions::objToObj(Object *o1, Object *o2) {
        if(typeid(o1) == typeid(Circle)){
            if(typeid(o2) == typeid(Circle))
                return circleToCircle(dynamic_cast<Circle*>(o1), dynamic_cast<Circle*>(o2));
            else if (typeid(o2) == typeid(pheng::Rectangle)){

            }
        } else if (typeid(o1) == typeid(Rectangle)){
            // All the other collisions
        }
    }

    bool Collisions::circleToCircle(Circle* s1, Circle* s2) {
        if ( vector2::norm(s1->getCenterPos(), s2->getCenterPos()) < s1->getRadius() + s2->getRadius()){
            vector2 v1i = s1->Velocity, v2i = s2->Velocity;
            float m1 = s1->Mass, m2 = s2->Mass;
            vector2 v1f = v1i -  (s1->getCenterPos() - s2->getCenterPos()) * (2*m2/(m1 + m2)) *
                    ((vector2::dotProduct(v1i - v2i, s1->getCenterPos() - s2->getCenterPos())) / pow((v1i - v2i).norm(), 2));

            vector2 v2f = v2i - (s2->getCenterPos() - s1->getCenterPos()) * (2*m1/(m1 + m2)) *
                                ((vector2::dotProduct(v2i - v1i, s2->getCenterPos() - s1->getCenterPos())) / pow((v2i - v1i).norm(), 2));

            s1->Velocity = v1f;
            s2->Velocity = v2f;

            return true;
        }
        return false;
    }

} // pheng

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
            // NOPE, wrong

            float a = s1->Velocity.angle(), b = s2->Velocity.angle();
            float v1f = s1->Velocity.norm() *
                        (sin(b) / ((cos(a) * sin(b)) + (sin(a) * cos(b))) );

            float v2f = v1f * (sin(a) / sin(b));

            s1->setVelocity(pheng::vector2::fromNormAngle(v1f, a));
            s2->setVelocity(pheng::vector2::fromNormAngle(v2f, b));

            return true;
        }
        return false;
    }

} // pheng

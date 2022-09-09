#include "../../include/Collisions.h"
#include <typeinfo>
#include <cmath>

namespace pheng {

    bool Collisions::objToObj(Object *o1, Object *o2, float r_c) {
        if (dynamic_cast<Circle*>(o1) != nullptr) {
            if (dynamic_cast<Circle*>(o2) != nullptr)
                return circleToCircle(dynamic_cast<Circle*>(o1), dynamic_cast<Circle*>(o2), r_c);

        }
    }

    bool Collisions::circleToCircle(Circle* s1, Circle* s2, double restitution_coef) {
        if ( vector2::norm(s1->getCenterPos(), s2->getCenterPos()) <= (s1->getRadius() + s2->getRadius())){
            double delta = (s1->getRadius() + s2->getRadius()) -
                            vector2::norm(s1->getCenterPos(), s2->getCenterPos());
            vector2 collisionAxis =( s1->getCenterPos() - s2->getCenterPos()) /
                    vector2::norm(s1->getCenterPos() - s2->getCenterPos()); //Normalized

            s1->Position += collisionAxis*delta*0.5;
            s2->Position -= collisionAxis*delta*0.5;

            vector2 v1i = s1->Velocity, v2i = s2->Velocity;
            double m1 = s1->Mass, m2 = s2->Mass;
            vector2 v1f = v1i -  (s1->getCenterPos() - s2->getCenterPos()) * (2*m2/(m1 + m2)) *
                    ((vector2::dotProduct(v1i - v2i, s1->getCenterPos() - s2->getCenterPos())) /
                    pow((s1->getCenterPos() - s2->getCenterPos()).norm(), 2));

            vector2 v2f = v2i - (s2->getCenterPos() - s1->getCenterPos()) * (2*m1/(m1 + m2)) *
                                ((vector2::dotProduct(v2i - v1i, s2->getCenterPos() - s1->getCenterPos())) /
                                pow((s2->getCenterPos() - s1->getCenterPos()).norm(), 2));

            s1->Velocity = v1f * restitution_coef;
            s2->Velocity = v2f * restitution_coef;


            return true;
        }
        return false;
    }

    bool Collisions::circleToRectangle(Circle *c, Rectangle *r) {

    }

} // pheng

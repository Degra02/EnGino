#ifndef PHYSICSENGINE_COLLISIONS_H
#define PHYSICSENGINE_COLLISIONS_H

#include "Circle.h"
#include "Rectangle.h"

namespace pheng {

    class Collisions {
    public:
        //static double r_c;    =1? elastic collision, =0? perfect inelastic collision

        static bool objToObj(Object* o1, Object* o2, float r_c);
        static bool circleToCircle(Circle* s1, Circle *s2, double restitution_coef);
        static bool circleToRectangle(Circle *c, Rectangle *r);

        static bool areColliding(Object* o1, Object* o2);
    };

}

#endif //PHYSICSENGINE_COLLISIONS_H

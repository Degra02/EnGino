#ifndef PHYSICSENGINE_OBJECT_H
#define PHYSICSENGINE_OBJECT_H


#include "vector2.h"

namespace phy_eng {

    class Object {
    public:
        vector2 Position;
        vector2 Velocity;
        vector2 Acc;
        vector2 Force;
        float Mass;

        Object();
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m);
        ~Object();

        void applyForce(vector2 force);
    };
}

#endif //PHYSICSENGINE_OBJECT_H

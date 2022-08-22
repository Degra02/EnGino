#ifndef PHYSICSENGINE_OBJECT_H
#define PHYSICSENGINE_OBJECT_H


#include "vector2.h"

namespace phy_eng {

    class Object {
    public:
        vector2 Position;
        vector2 Velocity;
        vector2 Force = {0, 0};
        float Mass;

        float coef_st_frict = 0;
        float coef_dn_frict = 0;

        float angular_velocity = 0;

        Object();
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m);
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m, float st_frict, float dn_frict);
        ~Object();

        void applyForce(vector2 force);
    };
}

#endif //PHYSICSENGINE_OBJECT_H

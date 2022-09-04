#ifndef PHYSICSENGINE_OBJECT_H
#define PHYSICSENGINE_OBJECT_H

#include "vector2.h"
#include <SFML/Graphics.hpp>

namespace pheng {

    enum Mobility {FIXED, FREE};

    class Object {
    public:
        vector2 Position;
        vector2 Velocity;
        vector2 Force = {0, 0};
        float Mass;

        float coef_st_frict = 0;
        float coef_dn_frict = 0;

        float angular_velocity = 0;

        Mobility mobility;

        Object();
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m, Mobility mobility);
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m, float st_frict, float dn_frict);
        ~Object();

        void applyForce(vector2 force);

        // Gets overridden by each subclass
        virtual sf::Drawable& getDrawable();

        // Applies change to graphics
        virtual void applyChange();

        //Setters
        void setMass(float kg);
        void setVelocity(vector2);
        void setPosition(vector2);
        void setMobility(Mobility);
        void setForce(vector2);
    };
}

#endif //PHYSICSENGINE_OBJECT_H

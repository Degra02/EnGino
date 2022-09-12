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

        float Energy;

        float coef_st_frict = 0;
        float coef_dn_frict = 0;

        float angular_velocity = 0;

        Mobility mobility;

        Object();
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m, Mobility mobility);
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, float m, float st_frict, float dn_frict);
        virtual ~Object();

        void applyForce(vector2 force);
        virtual void constraintsCollision(float constraints[], float r_f);

        // Gets overridden by each subclass
        virtual sf::Drawable& getDrawable();

        virtual float getSize() = 0;
        virtual vector2 getCenter() = 0;

        // Applies change to graphics
        virtual void applyChange();

        //Setters
        void setMass(float kg);
        void setVelocity(vector2);
        void setPosition(vector2);
        void setMobility(Mobility);
        void setForce(vector2);


        //Verlet integration
        vector2 Old_Position;
        vector2 Acceleration;
        virtual void updatePositionVerlet(float dt) = 0;
        virtual void accelerate(vector2 acceleration) = 0;

        virtual float calculateEnergy(float h, float g);

        virtual void changeColorVelocity() = 0;
    };
}

#endif //PHYSICSENGINE_OBJECT_H

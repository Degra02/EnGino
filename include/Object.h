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
        double Mass;

        double coef_st_frict = 0;
        double coef_dn_frict = 0;

        double angular_velocity = 0;

        Mobility mobility;

        Object();
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, double m, Mobility mobility);
        Object(vector2 pos, vector2 v, vector2 a, vector2 f, double m, double st_frict, double dn_frict);
        ~Object();

        void applyForce(vector2 force);
        virtual void constraintsCollision(double constraints[]);

        // Gets overridden by each subclass
        virtual sf::Drawable& getDrawable();

        // Applies change to graphics
        virtual void applyChange();

        //Setters
        void setMass(double kg);
        void setVelocity(vector2);
        void setPosition(vector2);
        void setMobility(Mobility);
        void setForce(vector2);


        //Verlet integration
        vector2 Old_Position;
        vector2 Acceleration;
        virtual void updatePositionVerlet(double dt) = 0;
        virtual void accelerate(vector2 acceleration) = 0;
    };
}

#endif //PHYSICSENGINE_OBJECT_H

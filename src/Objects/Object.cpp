#include "../../include/Object.h"

namespace pheng {
    pheng::Object::Object() {
        this->Position = {0.f, 0.f};
        this->Velocity = {0.f, 0.f};
        this->Mass = 0.f;
        this->mobility = FREE;
    }

    pheng::Object::~Object() = default;

    pheng::Object::Object(pheng::vector2 pos, pheng::vector2 v, pheng::vector2 a, pheng::vector2 f, double m,
                          Mobility mobility = FREE) {
        this->Position = pos;
        this->Velocity = v;
        this->Force = f;
        setMass(m);
        this->mobility = mobility;
    }

    pheng::Object::Object(pheng::vector2 pos, pheng::vector2 v, pheng::vector2 a, pheng::vector2 f,
                          double m, double st_frict, double dn_frict) {
        this->Position = pos;
        this->Velocity = v;
        this->Force = f;
        setMass(m);
        this->coef_st_frict = st_frict;
        this->coef_dn_frict = dn_frict;
    }

    void pheng::Object::applyForce(pheng::vector2 force) {
        this->Force = force;
    }

    void Object::applyChange() {
    }

    sf::Drawable &Object::getDrawable() {
    }

    void Object::setMass(double kg) {
        if(kg > 0){
            this->Mass = kg;
        } else {
            printf("Mass must be positive");
        }
    }

    void Object::setVelocity(vector2 Velocity) {
        this->Velocity = Velocity;
    }

    void Object::setPosition(vector2 Position) {
        this->Position = Position;
    }

    void Object::setMobility(Mobility mobility) {
        this->mobility = mobility;
    }

    void Object::setForce(vector2 f) {
        this->Force = f;
    }

    void Object::constraintsCollision(double *constraints, float r_f) {

    }

    float Object::calculateEnergy(double h, double g) {
        return 0.5 * Mass * Velocity.norm() * Velocity.norm() +
               Mass * g * (h - Position.getY())/100;
    }

}



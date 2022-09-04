#include "../../include/Object.h"

namespace phy_eng {
    phy_eng::Object::Object() {
        this->Position = {0.f, 0.f};
        this->Velocity = {0.f, 0.f};
        this->Mass = 0.f;
        this->mobility = FREE;
    }

    phy_eng::Object::~Object() = default;

    phy_eng::Object::Object(phy_eng::vector2 pos, phy_eng::vector2 v, phy_eng::vector2 a, phy_eng::vector2 f, float m,
                            Mobility mobility = FREE) {
        this->Position = pos;
        this->Velocity = v;
        this->Force = f;
        this->Mass = m;
        this->mobility = mobility;
    }

    phy_eng::Object::Object(phy_eng::vector2 pos, phy_eng::vector2 v, phy_eng::vector2 a, phy_eng::vector2 f,
                            float m, float st_frict, float dn_frict) {
        this->Position = pos;
        this->Velocity = v;
        this->Force = f;
        this->Mass = m;
        this->coef_st_frict = st_frict;
        this->coef_dn_frict = dn_frict;
    }

    void phy_eng::Object::applyForce(phy_eng::vector2 force) {
        this->Force = force;
    }

    void Object::applyChange() {
    }

    sf::Drawable &Object::getDrawable() {
    }

    void Object::setMass(float kg) {
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

}



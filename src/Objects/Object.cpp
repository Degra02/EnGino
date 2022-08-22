#include "../../include/Object.h"

namespace phy_eng {
    phy_eng::Object::Object() {
        this->Position = {0.f, 0.f};
        this->Velocity = {0.f, 0.f};
        this->Mass = 0.f;
    }

    phy_eng::Object::~Object() = default;

    phy_eng::Object::Object(phy_eng::vector2 pos, phy_eng::vector2 v, phy_eng::vector2 a, phy_eng::vector2 f, float m) {
        this->Position = pos;
        this->Velocity = v;
        this->Force = f;
        this->Mass = m;
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
}



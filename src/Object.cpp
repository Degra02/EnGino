#include "../include/Object.h"

phy_eng::Object::Object() {
    this->Position = {0.f, 0.f};
    this->Velocity = {0.f, 0.f};
    this->Acc = {0.f, 0.f};
    this->Force = {0.f, 0.f};
    this->Mass = 0.f;
}

phy_eng::Object::~Object() = default;

phy_eng::Object::Object(phy_eng::vector2 pos, phy_eng::vector2 v, phy_eng::vector2 a, phy_eng::vector2 f, float m) {
    this->Position = pos;
    this->Velocity = v;
    this->Acc = a;
    this->Force = f;
    this->Mass = m;
}

void phy_eng::Object::applyForce(phy_eng::vector2 force) {
    this->Force = force;
}


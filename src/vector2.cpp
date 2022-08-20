#include "../include/vector2.h"



phy_eng::vector2::vector2() {
    x = 0.f;
    y = 0.f;
}

phy_eng::vector2::vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

phy_eng::vector2 phy_eng::vector2::operator+(phy_eng::vector2 v2) {
    return {x + v2.x, y + v2.y};
}

phy_eng::vector2 phy_eng::vector2::operator+=(phy_eng::vector2 v2) const {
    return {x + v2.x, y + v2.y};
}

phy_eng::vector2 phy_eng::vector2::operator*(float m) {
    return {0, 0};
}

phy_eng::vector2 phy_eng::vector2::operator/(float m) {
    return {x / m, y / m};
}

#include "../include/vector2.h"
#include <cmath>


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

void phy_eng::vector2::operator+=(phy_eng::vector2 v2) {
    this->x += v2.x;
    this->y += v2.y;
}

phy_eng::vector2 phy_eng::vector2::operator*(float m) {
    return {this->x * m, this->y * m};
}

phy_eng::vector2 phy_eng::vector2::operator/(float m) {
    return {x / m, y / m};
}

phy_eng::vector2 phy_eng::vector2::operator-(phy_eng::vector2 v2) {
    return {this->x - v2.x, this->y - v2.y};
}

float phy_eng::vector2::norm(phy_eng::vector2 v) { // Static function
    return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
}

float phy_eng::vector2::norm(phy_eng::vector2 v1, phy_eng::vector2 v2) {
    return std::sqrt(std::pow((v1.x - v2.x), 2) +
                     std::pow((v1.y - v2.y), 2));
}

void phy_eng::vector2::setX(float x) {
    this->x = x;
}

void phy_eng::vector2::setY(float y) {
    this->y = y;
}

float phy_eng::vector2::getX() {
    return this->x;
}

float phy_eng::vector2::getY() {
    return this->y;
}

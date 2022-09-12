#include "../../include/vector2.h"
#include <cmath>

namespace pheng {
    vector2::vector2() {
        x = 0.f;
        y = 0.f;
    }

    vector2::vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    vector2 vector2::operator+(vector2 v2) const {
        return {x + v2.x, y + v2.y};
    }

    void vector2::operator+=(vector2 v2) {
        this->x += v2.x;
        this->y += v2.y;
    }

    void vector2::operator-=(vector2 v2) {
        this->x -= v2.x;
        this->y -= v2.y;
    }

    vector2 vector2::operator*(float m) const {
        return {this->x * m, this->y * m};
    }

    vector2 vector2::operator/(float m) const {
        return {x / m, y / m};
    }

    vector2 vector2::operator-(vector2 v2) const {
        return {this->x - v2.x, this->y - v2.y};
    }

    float vector2::norm() const {
        return static_cast<float>(std::sqrt(pow(x,2) + pow(y, 2)));
    }

    float vector2::norm(vector2 v) { // Static function
        return static_cast<float>(std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2)));
    }

    float vector2::norm(vector2 v1, vector2 v2) {
        return static_cast<float>(std::sqrt(std::pow((v1.x - v2.x), 2) +
                         std::pow((v1.y - v2.y), 2)));
    }

    float vector2::dotProduct(vector2 v1, vector2 v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    float vector2::angle() const {
        return atan2f(y, x);
    }

    float vector2::angle(vector2 v) {
        return atan2f(v.y, v.x);
    }

    float vector2::angleBetween(vector2 v1, vector2 v2) {
        return std::acos(dotProduct(v1, v2) / (norm(v1 * norm(v2))));
    }

    vector2 vector2::twoPoints(vector2 p1, vector2 p2) {
        return {p2.x - p1.x, p2.y - p1.y};
    }

    vector2 vector2::fromNormAngle(float_t norm, float angle) {
        return {norm * std::cos(angle), norm * std::sin(angle)};
    }

    void vector2::setX(float_t _x) {
        this->x = _x;
    }

    void vector2::setY(float_t _y) {
        this->y = _y;
    }

    float vector2::getX() const {
        return this->x;
    }

    float vector2::getY() const {
        return this->y;
    }

}


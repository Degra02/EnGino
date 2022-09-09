#include "../../include/vector2.h"
#include <cmath>

namespace pheng {
    vector2::vector2() {
        x = 0.f;
        y = 0.f;
    }

    vector2::vector2(double x, double y) {
        this->x = x;
        this->y = y;
    }

    vector2 vector2::operator+(vector2 v2) {
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

    vector2 vector2::operator*(double m) {
        return {this->x * m, this->y * m};
    }

    vector2 vector2::operator/(double m) {
        return {x / m, y / m};
    }

    vector2 vector2::operator-(vector2 v2) {
        return {this->x - v2.x, this->y - v2.y};
    }

    double vector2::norm() {
        return std::sqrt(pow(x,2) + pow(y, 2));
    }

    double vector2::norm(vector2 v) { // Static function
        return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
    }

    double vector2::norm(vector2 v1, vector2 v2) {
        return std::sqrt(std::pow((v1.x - v2.x), 2) +
                         std::pow((v1.y - v2.y), 2));
    }

    double vector2::dotProduct(vector2 v1, vector2 v2) {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    double vector2::angle() {
        return atan2f(y, x);
    }

    double vector2::angle(vector2 v) {
        return atan2f(v.y, v.x);
    }

    double vector2::angleBetween(vector2 v1, vector2 v2) {
        return std::acos(dotProduct(v1, v2) / (norm(v1 * norm(v2))));
    }

    vector2 vector2::twoPoints(vector2 p1, vector2 p2) {
        return {p2.x - p1.x, p2.y - p1.y};
    }

    vector2 vector2::fromNormAngle(double_t norm, double angle) {
        return {norm * cos(angle), norm * sin(angle)};
    }

    void vector2::setX(double_t x) {
        this->x = x;
    }

    void vector2::setY(double_t y) {
        this->y = y;
    }

    double vector2::getX() {
        return this->x;
    }

    double vector2::getY() {
        return this->y;
    }

}


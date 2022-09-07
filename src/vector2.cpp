#include "../include/vector2.h"
#include <cmath>


pheng::vector2::vector2() {
    x = 0.f;
    y = 0.f;
}

pheng::vector2::vector2(double x, double y) {
    this->x = x;
    this->y = y;
}

pheng::vector2 pheng::vector2::operator+(pheng::vector2 v2) {
    return {x + v2.x, y + v2.y};
}

void pheng::vector2::operator+=(pheng::vector2 v2) {
    this->x += v2.x;
    this->y += v2.y;
}

void pheng::vector2::operator-=(pheng::vector2 v2) {
    this->x -= v2.x;
    this->y -= v2.y;
}

pheng::vector2 pheng::vector2::operator*(double m) {
    return {this->x * m, this->y * m};
}

pheng::vector2 pheng::vector2::operator/(double m) {
    return {x / m, y / m};
}

pheng::vector2 pheng::vector2::operator-(pheng::vector2 v2) {
    return {this->x - v2.x, this->y - v2.y};
}

double pheng::vector2::norm() {
    return std::sqrt(pow(x,2) + pow(y, 2));
}

double pheng::vector2::norm(pheng::vector2 v) { // Static function
    return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
}

double pheng::vector2::norm(pheng::vector2 v1, pheng::vector2 v2) {
    return std::sqrt(std::pow((v1.x - v2.x), 2) +
                     std::pow((v1.y - v2.y), 2));
}

double pheng::vector2::dotProduct(vector2 v1, vector2 v2) {
    return (v1.x * v2.x) + (v1.y * v2.y);
}

double pheng::vector2::angle() {
    return atan2f(y, x);
}

double pheng::vector2::angle(pheng::vector2 v) {
    return atan2f(v.y, v.x);
}

double pheng::vector2::angleBetween(pheng::vector2 v1, pheng::vector2 v2) {
    return std::acos(dotProduct(v1, v2) / (norm(v1 * norm(v2))));
}

pheng::vector2 pheng::vector2::twoPoints(vector2 p1, vector2 p2) {
    return {p2.x - p1.x, p2.y - p1.y};
}

pheng::vector2 pheng::vector2::fromNormAngle(double_t norm, double angle) {
    return {norm * cos(angle), norm * sin(angle)};
}

void pheng::vector2::setX(double_t x) {
    this->x = x;
}

void pheng::vector2::setY(double_t y) {
    this->y = y;
}

double pheng::vector2::getX() {
    return this->x;
}

double pheng::vector2::getY() {
    return this->y;
}

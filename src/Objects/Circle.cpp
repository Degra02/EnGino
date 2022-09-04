#include "../../include/Circle.h"

namespace pheng {
    Circle::Circle() : Object() {
        this->r = 0;
        this->Position = {0, 0};
        initDrawable();
    }

    Circle::Circle(float r, vector2 centerPos, float mass) {
        this->r = r;
        setPosition(centerPos);
        setMass(mass);
        initDrawable();
    }

    Circle::Circle(float r, vector2 centerPos, float mass, Mobility mobility) {
        this->r = r;
        setPosition(centerPos);
        setMass(mass);
        setMobility(mobility);
        initDrawable();
    }

    void Circle::initDrawable() {
        this->circleShape = sf::CircleShape(r);
        this->circleShape.setPosition(this->Position.getX(), this->Position.getY());
        this->circleShape.setPointCount(20);
        circleShape.setFillColor(sf::Color::Black);
        this->circleShape.setOutlineColor(sf::Color::White);
        this->circleShape.setOutlineThickness(4);
    }

    void Circle::setRadius(float r) {
        this->r = r;
    }

    void Circle::setCenterPos(vector2 centerPos) {
        this->Position = centerPos;
    }

    float Circle::getRadius() const {
        return this->r;
    }

    vector2 Circle::getCenterPos() {
        return this->Position;
    }

    sf::Drawable &Circle::getDrawable() {
        return circleShape;
    }

    void Circle::applyChange() {
        this->circleShape.setPosition({this->Position.getX(), -this->Position.getY()});
    }
} // pheng
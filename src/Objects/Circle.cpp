#include "../../include/Circle.h"

namespace phy_eng {
    Circle::Circle() : Object() {
        this->r = 0;
        this->Position = {0, 0};
        this->circleShape = sf::CircleShape(r);
        this->circleShape.setPosition(this->Position.getX(), this->Position.getY());
    }

    Circle::Circle(float r, vector2 centerPos, float mass) {
        this->r = r;
        setPosition(centerPos);
        setMass(mass);
        this->circleShape = sf::CircleShape(r);
        this->circleShape.setPosition(this->Position.getX(), this->Position.getY());
        this->circleShape.setFillColor(sf::Color::White);
        this->circleShape.setPointCount(20);
    }

    Circle::Circle(float r, vector2 centerPos, float mass, Mobility mobility) {
        this->r = r;
        setPosition(centerPos);
        setMass(mass);
        setMobility(mobility);
        this->circleShape = sf::CircleShape(r);
        this->circleShape.setPosition(this->Position.getX(), this->Position.getY());
        this->circleShape.setFillColor(sf::Color::White);
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
} // phy_eng
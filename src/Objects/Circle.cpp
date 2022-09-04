#include "../../include/Circle.h"

namespace phy_eng {
    Circle::Circle() : Object() {
        this->r = 0;
        this->Position = {0, 0};
        this->circleShape = sf::CircleShape(r);
        this->circleShape.setPosition(this->Position.getX(), this->Position.getY());
    }

    Circle::Circle(float r, vector2 centerPos) {
        this->r = r;
        this->Position = centerPos;
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

    sf::CircleShape &Circle::getCircleShape() {
        return circleShape;
    }

    void Circle::applyChange() {
        this->circleShape.setPosition({this->Position.getX(), -this->Position.getY()});
    }
} // phy_eng
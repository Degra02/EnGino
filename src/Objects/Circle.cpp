#include "../../include/Circle.h"

namespace pheng {
    Circle::Circle() : Object() {
        this->r = 0;
        this->Position = {0, 0};
        initDrawable();
    }

    Circle::Circle(double r, vector2 centerPos, double mass) {
        this->r = r;
        setPosition(centerPos);
        setMass(mass);
        initDrawable();
    }

    Circle::Circle(double r, vector2 centerPos, double mass, Mobility mobility) {
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

    double Circle::getRadius() const {
        return this->r;
    }

    vector2 Circle::getCenterPos() {
        return this->Position;
    }

    sf::Drawable &Circle::getDrawable() {
        return circleShape;
    }

    void Circle::applyChange() {
        this->circleShape.setPosition({static_cast<float>(this->getCenterPos().getX()), static_cast<float>(-this->getCenterPos().getY())});
    }

    void Circle::constraintsCollision(double *constraints) {

        if (vector2::norm(getCenterPos(), {constraints[0], getCenterPos().getY()}) < getRadius() ||
            vector2::norm(getCenterPos(), {0, getCenterPos().getY()}) < getRadius()) {
            Velocity.setX(-Velocity.getX());
        }
        if (vector2::norm(getCenterPos(), {getCenterPos().getX(), -constraints[1]}) < getRadius() ||
            vector2::norm(getCenterPos(), {getCenterPos().getX(), 0}) < getRadius()) {
            Velocity.setY(-Velocity.getY());
        }

        /**
        if ((getCenterPos().getX() - getRadius()) < 0  || (getCenterPos().getX() + getRadius() > constraints[0])) {
            Velocity.setX(-Velocity.getX());
        }
        if ((-getCenterPos().getY() + getRadius()) < 0 || (getCenterPos().getY() - getRadius()) < constraints[1]) {
            Velocity.setY(-Velocity.getY());
        }**/

    }
} // pheng
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

    Circle::~Circle() {
        Object::~Object();
    }

    void Circle::initDrawable() {
        this->circleShape = sf::CircleShape(r);
        this->circleShape.setPosition(this->Position.getX(), this->Position.getY());
        circleShape.setOrigin(circleShape.getRadius(), circleShape.getRadius());
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

    float Circle::getSize() {
        return getRadius();
    }

    vector2 Circle::getCenter() {
        return getCenterPos();
    }


    void Circle::applyChange() {
        this->circleShape.setPosition({static_cast<float>(this->getCenterPos().getX()), static_cast<float>(this->getCenterPos().getY())});
    }

    void Circle::constraintsCollision(float *constraints, float r_f) {

        if (vector2::norm(getCenterPos(), {constraints[0], getCenterPos().getY()}) < getRadius()) {
            Velocity.setX(-Velocity.getX() * r_f);
            float delta = getRadius() - vector2::norm(getCenterPos(), {constraints[0], getCenterPos().getY()});
            vector2 second_point = {constraints[0], getCenterPos().getY()};
            vector2 collision_axis = (getCenterPos() - second_point) /
                    vector2::norm(getCenterPos(), second_point);

            Position += collision_axis * delta * 0.5;

        } else if ( vector2::norm(getCenterPos(), {0, getCenterPos().getY()}) < getRadius()) {
            Velocity.setX(-Velocity.getX() * r_f);
            float delta = getRadius() - vector2::norm(getCenterPos(), {0, getCenterPos().getY()});
            vector2 second_point = {0, getCenterPos().getY()};
            vector2 collision_axis = (getCenterPos() - second_point) /
                                     vector2::norm(getCenterPos(), second_point);

            Position += collision_axis * delta * 0.5;
        }
        if (vector2::norm(getCenterPos(), {getCenterPos().getX(), constraints[1]}) < getRadius()) {
            Velocity.setY(-Velocity.getY() * r_f);
            float delta = getRadius() - vector2::norm(getCenterPos(), {getCenterPos().getX(), constraints[1]});
            vector2 second_point ={getCenterPos().getX(), constraints[1]};
            vector2 collision_axis = (getCenterPos() - second_point) /
                                     vector2::norm(getCenterPos(), second_point);

            Position += collision_axis * delta * 0.5;
        } else if ( vector2::norm(getCenterPos(), {getCenterPos().getX(), 0}) < getRadius()) {
            Velocity.setY(-Velocity.getY() * r_f);
            float delta = getRadius() - vector2::norm(getCenterPos(), {getCenterPos().getX(), 0});
            vector2 second_point ={getCenterPos().getX(), 0};
            vector2 collision_axis = (getCenterPos() - second_point) /
                                     vector2::norm(getCenterPos(), second_point);

            Position += collision_axis * delta * 0.5;
        }

    }

    float Circle::calculateEnergy(float h, float g) {
        return Object::calculateEnergy(h - getRadius(), g);
    }

    void Circle::changeColorVelocity() {
    }


    //Verlet integration
    void Circle::updatePositionVerlet(float dt) {
        vector2 velocity = Position - Old_Position;
        Old_Position = Position;

        //verlet integration formula
        Position = Position + velocity + Acceleration * dt * dt;
        Acceleration = {0, 0};
    }

    void Circle::accelerate(vector2 acc){
        Acceleration += acc;
    }
} // pheng
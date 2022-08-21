#include "../include/Sphere.h"

namespace phy_eng {
    Sphere::Sphere() {
        this->r = 0;
        this->centerPos = {0, 0};
        this->collider = SphereCollider();
    }

    Sphere::Sphere(float r, vector2 centerPos) {
        this->r = r;
        this->centerPos = centerPos;
        this->collider = SphereCollider();
    }

    void Sphere::setRadius(float r) {
        this->r = r;
    }

    void Sphere::setCenterPos(vector2 centerPos) {
        this->centerPos = centerPos;
    }

    float Sphere::getRadius() const {
        return this->r;
    }

    vector2 Sphere::getCenterPos() {
        return this->centerPos;
    }
} // phy_eng
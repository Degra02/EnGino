#ifndef PHYSICSENGINE_SPHERE_H
#define PHYSICSENGINE_SPHERE_H

#include "vector2.h"
#include "Object.h"

namespace phy_eng {

    class Sphere : public Object{
    private:
        float r;
        vector2 centerPos;
    public:
        Sphere();
        Sphere(float, vector2);
        void setRadius(float);
        void setCenterPos(vector2);
        float getRadius() const;
        vector2 getCenterPos();
    };

} // phy_eng

#endif //PHYSICSENGINE_SPHERE_H
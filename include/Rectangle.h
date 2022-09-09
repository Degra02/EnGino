#ifndef PHYSICSENGINE_RECTANGLE_H
#define PHYSICSENGINE_RECTANGLE_H

#include "Object.h"

namespace pheng {

    class Rectangle : public Object{
        float b;
        float h;

        sf::RectangleShape rectangleShape;

        Rectangle();
        Rectangle(float b, float h);

    };

} // pheng

#endif //PHYSICSENGINE_RECTANGLE_H

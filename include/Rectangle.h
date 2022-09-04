#ifndef PHYSICSENGINE_RECTANGLE_H
#define PHYSICSENGINE_RECTANGLE_H

#include "Object.h"

namespace pheng {

    class Rectangle : public Object{
    private:
        float lenght = 0;
        float height = 0;
        vector2 corners[4];

    public:
        Rectangle();
        Rectangle(float l, float h);
        void setLenght(float);
        void setHeight(float);
        float getLenght() const;
        float getHeight() const;
    };

} // pheng

#endif //PHYSICSENGINE_RECTANGLE_H

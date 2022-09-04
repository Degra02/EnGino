#ifndef PHYSICSENGINE_CIRCLE_H
#define PHYSICSENGINE_CIRCLE_H

#include "vector2.h"
#include "Object.h"

namespace phy_eng {

    class Circle : public Object{
    private:
        float r;
        //this->Position = center position
        sf::CircleShape circleShape = sf::CircleShape(r);
    public:
        Circle();
        Circle(float, vector2);

        sf::CircleShape& getCircleShape();

        void setRadius(float);
        void setCenterPos(vector2);
        float getRadius() const;
        vector2 getCenterPos();

        virtual void applyChange();
    };

} // phy_eng

#endif //PHYSICSENGINE_CIRCLE_H

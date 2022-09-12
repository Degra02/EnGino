#ifndef PHYSICSENGINE_CIRCLE_H
#define PHYSICSENGINE_CIRCLE_H

#include "vector2.h"
#include "Object.h"

namespace pheng {

    class Circle : public Object{
    public:
        float r;
        //this->Position = center position
        sf::CircleShape circleShape = sf::CircleShape(r);

        Circle();
        Circle(float , vector2, float );
        Circle(float , vector2, float , Mobility);
        ~Circle() override;

        void initDrawable();
        sf::Drawable& getDrawable() override;

        float getSize() override;
        vector2 getCenter() override;

        void setRadius(float);
        void setCenterPos(vector2);
        float getRadius() const;
        vector2 getCenterPos();

        void applyChange() override;
        void constraintsCollision(float constraints[], float r_f) override;

        float calculateEnergy(float h, float g) override;

        void changeColorVelocity() override;

        //Verlet integration
        void updatePositionVerlet(float dt) override;
        void accelerate(vector2 acceleration) override;
    };

} // pheng

#endif //PHYSICSENGINE_CIRCLE_H

#ifndef PHYSICSENGINE_CIRCLE_H
#define PHYSICSENGINE_CIRCLE_H

#include "vector2.h"
#include "Object.h"

namespace pheng {

    class Circle : public Object{
    public:
        double r;
        //this->Position = center position
        sf::CircleShape circleShape = sf::CircleShape(r);

        Circle();
        Circle(double , vector2, double );
        Circle(double , vector2, double , Mobility);
        ~Circle() override;

        void initDrawable();
        sf::Drawable& getDrawable() override;

        double getSize() override;

        void setRadius(float);
        void setCenterPos(vector2);
        double getRadius() const;
        vector2 getCenterPos();

        void applyChange() override;
        void constraintsCollision(double constraints[]) override;

        float calculateEnergy(double h, double g) override;


        //Verlet integration
        void updatePositionVerlet(double dt) override;
        void accelerate(vector2 acceleration) override;
    };

} // pheng

#endif //PHYSICSENGINE_CIRCLE_H

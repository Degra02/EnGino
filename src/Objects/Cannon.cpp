#include "Cannon.h"

namespace pheng {

    Cannon::Cannon(vector2 spawnPos, int *circleRadiusSpan, vector2 speed) {
        spawnPosition = spawnPos;
        this->circleRadiusSpan = circleRadiusSpan;
        this->speed = speed;
    }

    Object* Cannon::shootObject() {
        red = rand() % 255;
        green = rand() % 255;
        blue = rand() % 255;

        float r = rand() % (circleRadiusSpan[1] - circleRadiusSpan[0] + 1) + circleRadiusSpan[0];
        auto* c = new Circle(r, spawnPosition.operator+({static_cast<float>(rand() % (5 + 5 + 1) - 5),
                                                         static_cast<float>(rand() % (5 + 5 + 1) - 5)}), r);
        c->Velocity = speed;
        c->circleShape.setFillColor(sf::Color(red, green, blue));
        c->circleShape.setOutlineColor(sf::Color(red, green, blue, 50));

        return c;
    }
}

#include "../../include/ObjectSpawner.h"
#include "../../include/Circle.h"


namespace pheng {
    ObjectSpawner::ObjectSpawner(vector2 spawPos, uint32_t spawnRate, int* circleRadiusSpan) {
        spawnPosition = spawPos;
        this->spawnRate = spawnRate;
        this->circleRadiusSpan = circleRadiusSpan;
    }

    Object* ObjectSpawner::spawnObject() {
        if (spawnCounter % spawnRate == 0) {
            red = rand() % 255;
            green = rand() % 255;
            blue = rand() % 255;
            double r = rand() % (circleRadiusSpan[1] - circleRadiusSpan[0] + 1) + circleRadiusSpan[0];
            auto* c = new Circle(r, spawnPosition.operator+({static_cast<double>(rand() % (5 + 5 + 1) - 5),
                                                             static_cast<double>(rand() % (5 + 5 + 1) - 5)}), r);
            c->circleShape.setFillColor(sf::Color(red, green, blue));
            c->circleShape.setOutlineColor(sf::Color(red, green, blue));

            spawnCounter = (spawnCounter % spawnRate) + 1;

            return c;
        }
        spawnCounter = (spawnCounter % spawnRate) + 1;

        return nullptr;
    }
}

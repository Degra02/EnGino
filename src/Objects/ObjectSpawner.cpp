#include "../../include/ObjectSpawner.h"
#include "../../include/Circle.h"


namespace pheng {
    ObjectSpawner::ObjectSpawner(vector2 spawPos, uint32_t spawnRate = 5) {
        spawnPosition = spawPos;
        this->spawnRate = spawnRate;
    }

    Object* ObjectSpawner::spawnObject() {
        if (spawnCounter % spawnRate == 0) {
            red = rand() % 255;
            green = rand() % 255;
            blue = rand() % 255;
            double r = rand() % (20 - 10 + 1) + 10;
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

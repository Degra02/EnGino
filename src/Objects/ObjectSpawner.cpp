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
            iter = (iter % 3);
            switch (iter) {
                case 0: {
                    red = (red % 255) + 10;
                }
                case 1: {
                    green = (green % 255) + 10;
                }
                case 2: {
                    blue = (blue % 255) + 10;
                }
            }
            iter++;

            float r = rand() % (circleRadiusSpan[1] - circleRadiusSpan[0] + 1) + circleRadiusSpan[0];
            Circle* c = new Circle(r, spawnPosition.operator+({static_cast<float>(rand() % (5 + 5 + 1) - 5),
                                                             static_cast<float>(rand() % (5 + 5 + 1) - 5)}), r);
            c->circleShape.setFillColor(sf::Color(red, green, blue));
            c->circleShape.setOutlineThickness(0);

            spawnCounter = (spawnCounter % spawnRate) + 1;

            return c;
        }
        spawnCounter = (spawnCounter % spawnRate) + 1;

        return nullptr;
    }
}

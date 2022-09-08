#include "../../include/ObjectSpawner.h"
#include "../../include/Circle.h"


namespace pheng {
    ObjectSpawner::ObjectSpawner(vector2 spawPos) {
        spawnPosition = spawPos;
    }

    void ObjectSpawner::spawnObject(World *world) {
        red += 10, green += 10, blue += 10;
        double r = rand() % 10 + 1;
        Circle c(r, spawnPosition, r);
        c.circleShape.setFillColor(sf::Color(red, green, blue));

        world->addObject(&c);
    }
}

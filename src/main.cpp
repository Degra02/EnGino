#include <iostream>
#include "../include/World.h"
#include "../include/Sphere.h"
#include "../include/Collisions.h"

int main() {
    phy_eng::World world = phy_eng::World(0.01);
    world.addObject(new phy_eng::Object());

    phy_eng::Sphere s(5, {0, 0});

    bool colliding = phy_eng::Collisions::sphereToSphere(&s, new phy_eng::Sphere(10, {0, 8}));
    if (colliding)
        printf("colliding");

}

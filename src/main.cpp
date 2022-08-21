#include <iostream>
#include "../include/World.h"
#include "../include/Sphere.h"

int main() {
    phy_eng::World world = phy_eng::World(0.01);
    world.addObject(new phy_eng::Object());

    phy_eng::Sphere s(5, {0, 0});

    bool colliding = s.collider.sphereToSphere(&s, new phy_eng::Sphere(10, {0, 8}));
    printf("%d", colliding);

}

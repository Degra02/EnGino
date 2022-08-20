#include <iostream>
#include "../include/World.h"

int main() {
    phy_eng::World world = phy_eng::World(0.01);
    world.addObject(new phy_eng::Object());

}

#include "../include/World.h"
#include <iostream>
#include <cassert>
#include <algorithm>

namespace phy_eng {

    phy_eng::World::World() {
        dt = 0;
    }

    World::World(float dt) {
        this->dt = dt;
    }

    phy_eng::World::~World() {
        assert(this->n == 0);
    }

    void World::addObject(Object *obj) {
        this->worldObjects.push_back(obj);
        n++;
    }

    void World::removeObject(Object *obj) {
        if(n > 0){
            auto itr = std::find(worldObjects.begin(), worldObjects.end(), obj);
            if (itr == worldObjects.end()) return; // This means there's no such object in the world
            worldObjects.erase(itr);
        } else {
            printf("\n No objects in the World");
        }
    }

    void World::step() {
        for (Object* obj: worldObjects){
            obj->Force += gravity * obj->Mass;
            obj->Velocity += (obj->Force / obj->Mass) * dt;
            obj->Position += obj->Velocity * dt;

            obj->Force = {0.f, 0.f}; // Reinitializing the force applied to the Object
        }
    }
} // phy_eng



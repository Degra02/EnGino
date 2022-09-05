#include "../include/World.h"
#include "../include/Collisions.h"
#include <iostream>
#include <algorithm>

namespace pheng {

    pheng::World::World() {
        dt = 0;
    }

    World::World(float dt) {
        this->dt = dt;
    }

    pheng::World::~World() {
    }

    void World::addObject(Object* obj) {
        this->worldObjects.push_back(obj);
        n++;
    }

    void World::addObjects(std::vector<Object*> objects ) {
        for (auto &obj : objects){
            addObject(obj);
            n++;
        }
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
        if(!isPaused) {
            for (Object* obj: worldObjects){
                if (obj->mobility == FREE){
                    obj->Force += (this->gravity * obj->Mass);
                    obj->Velocity += (obj->Force / obj->Mass) * dt;
                    obj->Position += (obj->Velocity * dt);

                    checkConstraintsCollision(obj);

                    obj->Force = {0.f, 0.f}; // Reinitializing the force applied to the Object
                    obj->applyChange();
                }

                for (Object* other: worldObjects) {
                    if (std::cref(other) != std::cref(obj))
                        pheng::Collisions::circleToCircle(dynamic_cast<Circle *>(obj), dynamic_cast<Circle *>(other));
                }

            }
        }
    }

    void World::setGravity(vector2 value) {
        this->gravity = value;
    }

    void World::setDt(float dt) {
        this->dt = dt;
    }

    std::vector<Object*> World::getWorldObjects() {
        return this->worldObjects;
    }

    void World::setPaused() {
        this->isPaused = !isPaused;
    }

    void World::setConstraints(float x, float y) {
        this->constraints[0] = x;
        this->constraints[1] = y;
    }

    bool World::checkConstraintsCollision(Object* obj) {
        obj->constraintsCollision(constraints);
    }
} // pheng



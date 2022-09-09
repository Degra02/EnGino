#include "../include/World.h"
#include "../include/Collisions.h"
#include <iostream>
#include <algorithm>
#include <list>


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

    void World::removeAll() {
        for(auto &obj: worldObjects){
            worldObjects.pop_back();
            delete obj;
        }
    }

    void World::step(double dt, float r_f = 1) {
        if(!isPaused) {
            for (Object* obj: worldObjects){
                if (obj->mobility == FREE){
                    obj->Force += (this->gravity * obj->Mass);
                    obj->Velocity += (obj->Force / obj->Mass) * dt;
                    obj->Position += (obj->Velocity * dt);

                    checkConstraintsCollision(obj);
                    detectCollisions(obj, r_f);

                    obj->Force = {0.f, 0.f}; // Reinitializing the force applied to the Object
                    obj->applyChange();
                }
            }
        }
    }

    void World::detectCollisions(Object* obj, float r_c) {
        //std::list<Object*> intersections;
        for (auto &other: worldObjects) {
            if (obj != other) {
                pheng::Collisions::objToObj(obj, other, r_c);
            }
        }
    }

    void World::setGravity(vector2 value) {
        this->gravity = value;
    }

    void World::setDt(float dt) {
        this->dt = dt;
    }

    std::vector<Object*> World::getWorldObjects() const {
        return this->worldObjects;
    }

    void World::setPaused() {
        this->isPaused = !isPaused;
    }

    void World::setConstraints(float x, float y) {
        this->window_constraints[0] = x;
        this->window_constraints[1] = y;
    }

    bool World::checkConstraintsCollision(Object* obj) {
        obj->constraintsCollision(window_constraints);
    }

    void World::spawnCircle(int x, int y) {
        double r = rand() % (50 - 10 + 1) + 10;

        auto* c = new pheng::Circle(r, {static_cast<double>(x),
                                         static_cast<double>(y)}, r);
        //c->setVelocity({static_cast<float>(rand() % 100), static_cast<float>(rand() % 100)});

        //For Verlet's method
        c->Old_Position = c->Position;

        addObject(c);
    }


    void World::addSpawner(ObjectSpawner *spawner) {
        spawners.push_back(spawner);
    }

    void World::removeSpawner(ObjectSpawner* spawner) {
        auto itr = std::find(spawners.begin(), spawners.end(), spawner);
        if (itr == spawners.end()) return;
        spawners.erase(itr);
    }

    void World::spawnObjectsSpawner() {
        for (auto &spawner: spawners) {
            if (spawner->isSpawning && !isPaused) {
                Object* obj = spawner->spawnObject();
                if (obj != nullptr)
                    addObject(obj);
            }
        }
    }

    void World::toggleSpawners() {
        for (auto &spawner: spawners) {
            spawner->toggleSpawning();
        }
    }
} // pheng



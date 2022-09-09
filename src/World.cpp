#include "../include/World.h"
#include "../include/Collisions.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>


namespace pheng {

    pheng::World::World(const sf::Font& font) {
        dt = 0;

        totalEnergy.setFont(font);
        totalEnergy.setCharacterSize(24);
        totalEnergy.setFillColor(sf::Color::White);
        totalEnergy.setPosition({50, 50});
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
        total_energy = 0;
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

                    updateEnergy(obj);
                }
            }
        }
    }

    void World::updateEnergy(Object* obj) {
        total_energy += obj->calculateEnergy(window_constraints[1], gravity.getY() / 100.f);
        std::stringstream s;
        s << "Energy: " << std::setprecision(3) << total_energy;
        totalEnergy.setString(s.str());
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



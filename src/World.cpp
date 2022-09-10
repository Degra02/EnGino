#include "../include/World.h"
#include "../include/Collisions.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>


namespace pheng {

    pheng::World::World(const sf::Font& font) {
        dt = 0;

        Legend.setFont(font);
        Legend.setCharacterSize(24);
        Legend.setFillColor(sf::Color::White);
        Legend.setPosition({50, 50});
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
            n--;
        } else {
            printf("\n No objects in the World");
        }
    }

    void World::removeAll() {
        for(uint32_t i(0); i < n; ++i){
            Object* obj = worldObjects[i];
            worldObjects.pop_back();
            delete obj;
        }
        n = 0; total_energy = 0;
        updateLegend();
    }

    void World::step(double dt, float r_f = 1) {
        if (!isPaused && n > 0) {
            total_energy = 0;
            for (uint32_t i(0); i < n; ++i) {
                if (worldObjects[i]->mobility == FREE){
                    worldObjects[i]->Force += (this->gravity * worldObjects[i]->Mass);
                    worldObjects[i]->Velocity += (worldObjects[i]->Force / worldObjects[i]->Mass) * dt;
                    worldObjects[i]->Position += (worldObjects[i]->Velocity * dt);

                    checkConstraintsCollision(worldObjects[i]);
                    //detectCollisionsBruteForce(i, worldObjects[i], r_f);

                    worldObjects[i]->Force = {0.f, 0.f}; // Reinitializing the force applied to the Object
                    worldObjects[i]->applyChange();

                    updateEnergy(worldObjects[i]);
                }
            }
            detectCollisionsSweetAndPrune();
            updateLegend();
        }
    }

    void World::updateEnergy(Object* obj) {
        total_energy += obj->calculateEnergy(window_constraints[1], gravity.getY() / 100.f);
    }

    void World::updateLegend() {
        std::stringstream s;
        s << "Energy: " << std::setprecision(3) << total_energy << std::endl \
            << "No: " << n;
        Legend.setString(s.str());
    }

    void World::detectCollisionsBruteForce(uint32_t i, Object* obj, float r_c) {
        for (uint32_t k(i+1); k < n; ++k){
            pheng::Collisions::objToObj(obj, worldObjects[k], r_c);
        }
    }

    void World::detectCollisionsSweetAndPrune() {
        std::vector<Object*> possibleCollision = SweepAndPrune::getPossibleCollisions(worldObjects);

        for (uint32_t i(0); i < possibleCollision.size(); ++i) {
            for (uint32_t j(i); j < possibleCollision.size(); ++j){
                pheng::Collisions::objToObj(worldObjects[i], worldObjects[j], r_c);
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
        if (!isPaused) {
            for (auto &spawner: spawners) {
                if (spawner->isSpawning) {
                    Object* obj = spawner->spawnObject();
                    if (obj != nullptr)
                        addObject(obj);
                }
            }
        }
    }


    void World::toggleSpawners() {
        for (auto &spawner: spawners) {
            spawner->toggleSpawning();
        }
    }

    //Drawing objects
    void World::drawObjects(sf::RenderWindow *window) {
        for (auto &obj: worldObjects) {
            window->draw(obj->getDrawable());
        }
        window->draw(Legend);
    }
} // pheng



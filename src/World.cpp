#include "../include/World.h"
#include "../include/Collisions.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>


namespace pheng {

    pheng::World::World(const sf::Font& font, int w, int h) {
        dt = 0;

        setConstraints(w, h);

        Legend.setFont(font);
        Legend.setCharacterSize(24);
        Legend.setFillColor(sf::Color::White);
        Legend.setPosition({50, 50});

        objLegend.setFont(font);
        objLegend.setCharacterSize(24);
        objLegend.setFillColor(sf::Color::White);

        sf::RectangleShape border({static_cast<float>(w), static_cast<float>(h)});
        border.setFillColor(sf::Color::Transparent);
        border.setOutlineColor(sf::Color::White);
        border.setOutlineThickness(4);
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
        int i;
        if(n > 0){
            for(auto it(worldObjects.begin()); it != worldObjects.end(); ++it, ++i) {
                if (worldObjects[i] == obj) {
                    auto o = worldObjects[i];
                    worldObjects.erase(it);
                    delete o;
                    n--;
                }
            }
            /**auto itr = std::find(worldObjects.begin(), worldObjects.end(), obj);
            if (itr == worldObjects.end()) return; // This means there's no such object in the world
            n--;**/
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

    void World::step(float dt, float r_c = 1) {
        if (!isPaused && n > 0) {
            total_energy = 0;
            for (auto &obj: worldObjects){
                if (obj->mobility == FREE){
                    obj->Force += (this->gravity * obj->Mass);
                    obj->Velocity += (obj->Force / obj->Mass) * dt;
                    if (obj->Velocity.norm() > 0.01) {
                        obj->Position += (obj->Velocity * dt);
                    }
                    checkConstraintsCollision(obj, r_c);

                    if (obj->Position.getX() < 0 || obj->Position.getX() > window_constraints[0] ||
                            obj->Position.getY() < 0 || obj->Position.getY() > window_constraints[1]) {
                        n_outside++;
                        removeObject(obj);
                    } else {
                        obj->Force = {0.f, 0.f}; // Reinitializing the force applied to the Object
                        obj->applyChange();

                        updateEnergy(obj);
                        obj->changeColorVelocity();
                    }
                }
            }
            SweepAndPrune::calculateCollisions(worldObjects, r_c);
            updateLegend();
        }
    }

    void World::updateEnergy(Object* obj) {
        total_energy += obj->calculateEnergy(window_constraints[1], gravity.getY() / 100.f);
    }

    void World::updateLegend() {
        std::stringstream s;
        s << "Energy: " << std::setprecision(3) << total_energy << std::endl \
            << "No: " << n << std::endl \
            << "No outside: " << n_outside << std::endl;
        Legend.setString(s.str());
    }

    void World::updateObjLegend(Object *obj, vector2 offsetCenter) {
        std::stringstream s;
        s << "Velocity: " << std::setprecision(3) << obj->Velocity.norm() / 100 << "m/s" << std::endl;
        objLegend.setPosition(offsetCenter.getX() + 50, offsetCenter.getY());
        objLegend.setString(s.str());
    }

    [[deprecated("Replaced by Sweep & Prune")]]
    void World::detectCollisionsBruteForce(uint32_t i, Object* obj, float r_c) {
        for (uint32_t k(i+1); k < n; ++k){
            pheng::Collisions::objToObj(obj, worldObjects[k], r_c);
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

    bool World::checkConstraintsCollision(Object* obj, float r_f) {
        obj->constraintsCollision(window_constraints, r_f);
    }

    void World::spawnCircle(int x, int y) {
        float r = rand() % (50 - 10 + 1) + 10;

        auto* c = new pheng::Circle(r, {static_cast<float>(x), static_cast<float>(y)}, r);
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

    void World::addCannon(Cannon* cannon) {
        cannons.push_back(cannon);
    }

    void World::removeCannon(Cannon* cannon) {
        auto itr = std::find(cannons.begin(), cannons.end(), cannon);
        if (itr == cannons.end()) return;
        cannons.erase(itr);
    }

    void World::toggleCannons() {
        if (!isPaused) {
            for (auto &cannon: cannons){
                addObject(cannon->shootObject());
            }
        }
    }

    //Drawing objects
    void World::drawObjects(sf::RenderWindow *window) {
        window->draw(border);
        for (auto &obj: worldObjects) {
            window->draw(obj->getDrawable());
        }
        window->draw(Legend);
        window->draw(objLegend);
    }
} // pheng



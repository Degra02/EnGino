#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include <vector>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "ObjectSpawner.h"
#include "SweepAndPrune.h"
#include "../src/Objects/Cannon.h"

namespace pheng {

    class World {
    public:
        uint32_t n = 0; // number of objects currently in the simulation
        uint32_t n_outside = 0;
        float dt; // time intervals between a "system frame" and the next one
        vector2 gravity = vector2(0.0, 981); //negative y-values mean "upward"
        float window_constraints[2];
        float r_c = 1;

        bool isPaused = false;

        std::vector<Object*> worldObjects;
        std::vector<ObjectSpawner*> spawners;
        std::vector<Cannon*> cannons;

        float total_energy = 0;
        sf::Text Legend;
        sf::Text objLegend;

        explicit World(const sf::Font& font);
        explicit World(float dt);

        ~World();
        void addObject(Object* obj);
        void addObjects(std::vector<Object*> obj);
        void removeObject(Object* obj);
        void removeAll();

        void step(float dt, float r_c);
        void setGravity(vector2 value);
        void setDt(float dt);

        void setPaused();

        void updateEnergy(Object* obj);
        void updateLegend();
        void updateObjLegend(Object *obj, vector2 offsetCenter);

        void setConstraints(float x, float y);
        bool checkConstraintsCollision(Object*, float);

        void detectCollisionsBruteForce(uint32_t i, Object* obj, float r_c);

        std::vector<Object*> getWorldObjects() const;

        //Drawing
        void drawObjects(sf::RenderWindow *window);

        // Object Spawning
        void addSpawner(ObjectSpawner *spawner);
        void removeSpawner(ObjectSpawner *spawner);
        void spawnObjectsSpawner();
        void toggleSpawners();

        void addCannon(Cannon* cannon);
        void removeCannon(Cannon* cannon);
        void toggleCannons();

        void spawnCircle(int x, int y);
    };
}


#endif //PHYSICSENGINE_WORLD_H

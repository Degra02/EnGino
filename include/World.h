#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "ObjectSpawner.h"

namespace pheng {
    class World {
    public:
        int n = 0; // number of objects currently in the simulation

        double dt; // time intervals between a "system frame" and the next one

        bool isPaused = false;

        vector2 gravity = vector2(0.0, -9.81);
        std::vector<Object*> worldObjects;
        std::vector<ObjectSpawner*> spawners;

        double window_constraints[2];

        World();
        explicit World(float dt);

        ~World();
        void addObject(Object* obj);
        void addObjects(std::vector<Object*> obj);
        void removeObject(Object* obj);
        void removeAll();

        void addSpawner(ObjectSpawner *spawner);
        void removeSpawner(ObjectSpawner *spawner);
        void spawnObjectsSpawner();
        void toggleSpawners();

        void step(double dt, float r_f);
        void setGravity(vector2 value);
        void setDt(float dt);

        void setPaused();
        void setConstraints(float x, float y);
        bool checkConstraintsCollision(Object*);

        void detectCollisions(Object* obj, float r_c);

        std::vector<Object*> getWorldObjects() const;


        void spawnCircle(int x, int y);
    };
}


#endif //PHYSICSENGINE_WORLD_H

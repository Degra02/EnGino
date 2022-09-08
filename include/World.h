#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"

namespace pheng {
    class World {
    public:
        int n = 0; // number of objects currently in the simulation

        double dt; // time intervals between a "system frame" and the next one

        bool isPaused = false;

        vector2 gravity = vector2(0.0, -9.81);
        std::vector<Object*> worldObjects;
        double constraints[2];

        World();
        explicit World(float dt);

        ~World();
        void addObject(Object* obj);
        void addObjects(std::vector<Object*> obj);
        void removeObject(Object* obj);

        void removeAll();

        void step(double dt);
        void setGravity(vector2 value);
        void setDt(float dt);

        void setPaused();
        void setConstraints(float x, float y);
        bool checkConstraintsCollision(Object*);

        void detectCollisions(float r_f);

        std::vector<Object*> getWorldObjects() const;


        void spawnCircle(int x, int y);
    };
}


#endif //PHYSICSENGINE_WORLD_H

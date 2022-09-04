#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"

namespace pheng {
    class World {
    private:
        vector2 gravity = vector2(0.0, -9.81f);
        int n = 0; // number of objects currently in the simulation

        float dt; // time intervals between a "system frame" and the next one
        int constraints[2];

        bool isPaused = false;

    public:
        std::vector<Object*> worldObjects;

        World();
        explicit World(float dt);
        ~World();

        void addObject(Object &obj);
        void addObjects(std::vector<Object*> obj);
        void removeObject(Object* obj);
        void step();



        void setGravity(vector2 value);
        void setDt(float dt);
        void setPaused();
        void setConstraints(int x, int y);

        std::vector<Object*> getWorldObjects();
    };
}


#endif //PHYSICSENGINE_WORLD_H

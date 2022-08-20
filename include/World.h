#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include <vector>
#include "Object.h"

namespace phy_eng {
    class World {
    private:
        std::vector<Object*> worldObjects;
        vector2 gravity = vector2(0.0, -9.81f);

        int n = 0; // number of objects currently in the simulation
        float dt; // time intervals between a "system frame" and the next one

    public:
        World();
        explicit World(float dt);
        ~World();

        void addObject(Object *obj);
        void removeObject(Object* obj);
        void step();
    };
}


#endif //PHYSICSENGINE_WORLD_H

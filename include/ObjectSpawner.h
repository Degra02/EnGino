#ifndef PHYSICSENGINE_OBJECTSPAWNER_H
#define PHYSICSENGINE_OBJECTSPAWNER_H

#include "vector2.h"
#include "World.h"

namespace pheng {
    class ObjectSpawner {
    public:
        vector2 spawnPosition;
        uint32_t red = 0, green = 0, blue = 0;

        explicit ObjectSpawner(vector2);
        void spawnObject(World *world);
    };
}



#endif //PHYSICSENGINE_OBJECTSPAWNER_H

#ifndef PHYSICSENGINE_OBJECTSPAWNER_H
#define PHYSICSENGINE_OBJECTSPAWNER_H

#include "vector2.h"
#include "Object.h"

namespace pheng {
    class ObjectSpawner {
    public:
        vector2 spawnPosition;
        uint32_t red = 0, green = 0, blue = 0;
        uint32_t spawnRate;
        uint32_t spawnCounter = 0;
        uint8_t iter = 0;

        int* circleRadiusSpan;

        bool isSpawning = false;
        inline void toggleSpawning() { isSpawning = !isSpawning;}

        explicit ObjectSpawner(vector2, uint32_t spawnRate, int* circleRadiusSpan);
        Object* spawnObject();
    };
}



#endif //PHYSICSENGINE_OBJECTSPAWNER_H

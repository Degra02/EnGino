#ifndef ENGINO_CANNON_H
#define ENGINO_CANNON_H
#include <iostream>
#include "../../include/vector2.h"
#include "../../include/Object.h"
#include "../../include/Circle.h"

namespace pheng {
    class Cannon {
    public:
        vector2 spawnPosition;
        vector2 speed;
        uint32_t red = 0, green = 0, blue = 0;
        uint32_t spawnCounter = 0;
        uint8_t iter = 0;

        int* circleRadiusSpan;

        bool isSpawning = false;

        explicit Cannon(vector2 spawPos, int* circleRadiusSpan, vector2 speed);
        Object* shootObject();
    };
}

#endif //ENGINO_CANNON_H

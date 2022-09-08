#ifndef PHYSICSENGINE_VERLETSOLVER_H
#define PHYSICSENGINE_VERLETSOLVER_H

#include <iostream>
#include "World.h"

class VerletSolver {
public:

    pheng::World* world;

    VerletSolver(pheng::World *world);
    void update(float dt);
    void updatePositions(float dt);
    void applyGravity();
    void applyConstraints();
    void solveCollisions();
};


#endif //PHYSICSENGINE_VERLETSOLVER_H

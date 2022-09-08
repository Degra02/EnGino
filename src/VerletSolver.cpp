
#include "../include/VerletSolver.h"
#include "../include/Circle.h"

VerletSolver::VerletSolver(pheng::World *world) {
    this->world = world;
}

void VerletSolver::update(float dt) {
    applyGravity();
    applyConstraints();
    solveCollisions();
    updatePositions(dt);
}

void VerletSolver::updatePositions(float dt){
    for(auto &obj: world->worldObjects){
        obj->updatePositionVerlet(dt);
        obj->applyChange();
    }
}

void VerletSolver::applyGravity() {
    for(auto &obj: world->worldObjects){
        obj->accelerate(world->gravity);
    }
}

void VerletSolver::applyConstraints() { // Circular constraints
    pheng::vector2 position{world->constraints[0]/2, world->constraints[1]/2};
    float radius = 400.f;
    for (auto &obj: world->worldObjects) {
        pheng::vector2 to_obj = obj->Position - position;
        double dist = pheng::vector2::norm(to_obj);
        if (dist > (radius - dynamic_cast<pheng::Circle*>(obj)->getRadius())) {
            pheng::vector2 n = to_obj / dist;
            obj->Position = position + n * (radius - dynamic_cast<pheng::Circle*>(obj)->getRadius());
        }
    }
}

void VerletSolver::solveCollisions() {
    const uint32_t obj_count = world->worldObjects.size();
    for (uint32_t i(0); i < obj_count; ++i){
        pheng::Object* obj_1 = world->worldObjects.at(i);
        for(uint32_t k(i+1); k < obj_count; ++k){
            pheng::Object* obj_2 = world->worldObjects.at(k);
            pheng::vector2 coll_axis = obj_1->Position - obj_2->Position;
            float dist = pheng::vector2::norm(coll_axis);
            if (dist < dynamic_cast<pheng::Circle*>(obj_1)->getRadius() + dynamic_cast<pheng::Circle*>(obj_2)->getRadius()) {
                pheng::vector2 n = coll_axis / dist; //Normalized vector
                float delta =  dynamic_cast<pheng::Circle*>(obj_1)->getRadius() + dynamic_cast<pheng::Circle*>(obj_2)->getRadius()
                               - dist;
                obj_1->Position += n*delta*0.5f;
                obj_2->Position -= n*delta*0.5f;
            }
        }
    }
}

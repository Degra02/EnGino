#include "../../include/SweepAndPrune.h"
#include "../../include/Collisions.h"

namespace pheng {

    std::vector<Object *> SweepAndPrune::getPossibleCollisions(std::vector<Object*> worldObjects) {

        std::sort(worldObjects.begin(), worldObjects.end(), sortByXLeft);
        std::vector<Object*> activeList;

        for(uint32_t i(0); i < worldObjects.size(); ++i){
            activeList.push_back(worldObjects[i]);
            for (uint32_t j(0); j < activeList.size(); ++j) {
                if (worldObjects[i]->Position.getX() + worldObjects[i]->getSize() >
                        activeList[j]->Position.getX() - activeList[j]->getSize()) {
                   activeList.push_back(worldObjects[i]);
                } else {
                    activeList.erase(activeList.begin() + j);
                }
            }
        }

        return activeList;
    }

    bool SweepAndPrune::sortByXLeft(Object* o1, Object* o2) {
        return (o1->Position.getX() < o2->Position.getX());
    }

    void SweepAndPrune::checkEffectiveCollisions(Object* o1, Object* o2, std::vector<Object*> activeList) {
        if (pheng::Collisions::areColliding(o1, o2))
            activeList.push_back(o2);
    }


} //pheng
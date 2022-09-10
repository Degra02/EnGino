#include "../../include/SweepAndPrune.h"
#include "../../include/Collisions.h"
#include "../../include/PairsList.h"

namespace pheng {

    void SweepAndPrune::getPossibleCollisions(std::vector<Object*> worldObjects) {

        std::sort(worldObjects.begin(), worldObjects.end(), sortByXLeft);
        std::vector<Object*> activeList;
        activeList.push_back(worldObjects[0]);

        pheng::PairsList<Object*> pairsList;

        for(uint32_t i(1); i < worldObjects.size(); ++i){
            for (uint32_t j(0); j < activeList.size(); ++j) {
                if (worldObjects[i]->Position.getX() - worldObjects[i]->getSize() <
                        activeList[j]->Position.getX() + activeList[j]->getSize()) {
                    pairsList.addPair(worldObjects[i], activeList[j]);
                } else {
                    activeList.erase(activeList.begin() + j);
                }
            }
            activeList.push_back(worldObjects[i]);
        }

        for (auto &pair: pairsList.pairs) {
            pheng::Collisions::objToObj(pair.o1, pair.o2, 1);
        }
    }

    bool SweepAndPrune::sortByXLeft(Object* o1, Object* o2) {
        return (o1->Position.getX() < o2->Position.getX());
    }


} //pheng
#ifndef PHYSICSENGINE_PAIRSLIST_H
#define PHYSICSENGINE_PAIRSLIST_H

#include <vector>
#include "Object.h"

namespace pheng {

    template<typename T>
    struct Pair{
        T o1;
        T o2;

        Pair(T _o1, T _o2) {o1 = _o1; o2 = _o2;}
    };

    template<typename T>
    class PairsList {
    public:
        std::vector<Pair<T>> pairs;

        PairsList() = default;
        ~PairsList() = default;

        void addPair(T o1, T o2);
    };

} // pheng

#endif //PHYSICSENGINE_PAIRSLIST_H

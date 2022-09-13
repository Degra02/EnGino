#ifndef PHYSICSENGINE_PAIRSLIST_H
#define PHYSICSENGINE_PAIRSLIST_H

#include <iostream>
#include <vector>
#include "Object.h"

namespace pheng {

    template<typename T>
    struct Pair{
        T o1;
        T o2;

    public:
        Pair<T>(T _o1, T _o2) {o1 = _o1; o2 = _o2;}
        //~Pair();
    };

    template<typename T>
    class PairsList {
    public:
        std::vector<Pair<T>> pairs;

        PairsList() = default;
        ~PairsList() = default;

        void addPair(T o1, T o2);
    };

    template<typename T>
    void PairsList<T>::addPair(T o1, T o2) {
        Pair<T> p(o1, o2);
        pairs.push_back(p);
    }

} // pheng

#endif //PHYSICSENGINE_PAIRSLIST_H

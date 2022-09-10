#include "../../include/PairsList.h"

namespace pheng {

    template<typename T>
    void PairsList<T>::addPair(T o1, T o2) {
        pairs.push_back(Pair<T>(o1, o2));
    }

} // pheng
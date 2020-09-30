#ifndef SORTVALUES
#include <iostream>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    for (int i = 0; i < std::distance(begin, end); i++) {
        for (int j = 0; j < std::distance(begin, end) - 1; j++) {
            if (*(begin + j) > *(begin + j + 1))
                std::swap(begin[j], begin[j + 1]);
        }
    }
    return begin;
}

#endif

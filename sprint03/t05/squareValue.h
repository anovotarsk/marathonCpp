#ifndef SQUARE

#include <iterator>

template<class Container>
void squareValue(Container& container) {
    auto i = container.begin();

    while (i != container.end()) {
        *i *= *i;
        i++;
    }
}

#endif

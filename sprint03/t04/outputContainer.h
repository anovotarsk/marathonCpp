#ifndef OUT

#include <iostream>
#include <iterator>
#include <algorithm>

template<typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<decltype(*(container.begin()))> out(std::cout, "\n");
    std::copy(container.begin(), container.end(), out);
}

#endif

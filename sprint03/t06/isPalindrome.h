#ifndef isPalindrome
#include <iostream>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    auto a1 = *begin;
    auto a2 = *end;

    end--;
    for (; begin != end && std::distance(begin, end) > 0; begin++, end--) {
        a1 = *begin;
        a2 = *end;
        if (a1 != a2)
            return false;
    }
    return true;
}

#endif

#ifndef LS
//#pragma once
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>

template<class T>
T sumFileData(const std::string& fileName) {
    T sum = 0;
    std::ifstream fd(fileName);
    std::istream_iterator<T> iter(fd), eof;

    while (iter != eof) {
        sum = sum + *iter;
        iter++;
    }
    fd.close();
    return sum;
}

#endif

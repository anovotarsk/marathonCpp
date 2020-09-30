#pragma once

#include <mutex>

class MultithreadedClass {
public:
    MultithreadedClass() = default;
    ~MultithreadedClass() = default;
    MultithreadedClass(MultithreadedClass& obj) {
        m_int = obj.m_int;
    }
    
    int getInt() const;
    
    void add(int addValue);
    
    void subtract(int subtractValue);
    
private:
    int m_int{0};
    std::mutex m_mutex;
};

#include "MultithreadedClassHelp.h"

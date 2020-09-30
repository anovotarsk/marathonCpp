#pragma once

#include "MultithreadedClass.h"

int MultithreadedClass::getInt() const {
    return m_int;
}

void MultithreadedClass::add(int addValue) {
    m_mutex.lock();
    if (addValue > 0)
        for (int i = 0; i < addValue; i++)
            m_int--;
    else
        for (int i = 0; i < addValue * -1; i++)
            m_int++;
    m_mutex.unlock();
}

void MultithreadedClass::subtract(int subtractValue) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (subtractValue > 0)
        for (int i = 0; i < subtractValue; i++)
            m_int--;
    else
        for (int i = 0; i < subtractValue * -1; i++)
            m_int++;
}

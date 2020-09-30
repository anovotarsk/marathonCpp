#pragma once
#include "Vector.h"
#include <iterator>

namespace CBL {

template <class T>
T* Vector<T>::begin() const {
    return m_buffer;
}

template <class T>
T* Vector<T>::end() const {
    return &m_buffer[m_size];
}

}

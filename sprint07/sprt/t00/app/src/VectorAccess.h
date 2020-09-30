#pragma once
#include "Vector.h"

namespace CBL {

template <class T>
T& Vector<T>::operator[](size_t index) const {
    return m_buffer[index];
}

template <class T>
T& Vector<T>::at(size_t index) const {
    if (index >= m_size)
        throw std::out_of_range("Vector");
    return m_buffer[index];
}

template <class T>
T* Vector<T>::data() const {
    return m_buffer;
}

}

#pragma once
#include "Vector.h"

namespace CBL {

template <class T>
size_t Vector<T>::size() const {
    return m_size;
}

template <class T>
size_t Vector<T>::capacity() const {
    return m_capacity;
}

template <class T>
bool Vector<T>::isEmpty() const {
    return (m_size == 0);
}

template <class T>
void Vector<T>::resize(size_t size, const T& value) {
    if (m_size < size) {
        if (size <= m_capacity)
            for (int i = m_size; i < size; i++)
                m_buffer[i] = value;
        else {
            T* buffer = new T[(size <= m_capacity) ? m_capacity * 2 : size];

            for (int i = 0; i < m_size; i++)
                buffer[i] = m_buffer[i];
            for (int i = m_size; i < size; i++)
                buffer[i] = value;
            delete [] m_buffer;
            m_buffer = buffer;
            m_capacity = (size <= m_capacity) ? m_capacity * 2 : size;
        }
    }
    if (m_size > size) {
        for (int i = m_size - 1; i >= size; i--)
            delete m_buffer[i];
    }
    m_size = size;
}

template <class T>
void Vector<T>::reserve(size_t size) {
    if (m_capacity < size) {
        T* buffer = new T[size];

        for (int i = 0; i < m_size; i++)
            buffer[i] = m_buffer[i];
        delete [] m_buffer;
        m_buffer = buffer;
        m_capacity = size;
    }
}

}

#pragma once
#include "Vector.h"

namespace CBL {

template <class T>
void Vector<T>::push_back(const T& value) {
    if (m_capacity < m_size + 1) {
        T* buffer = new T[m_size * 2];
    
        for (int i = 0; i < m_size; i++)
            buffer[i] = m_buffer[i];
        buffer[m_size] = value;
        delete [] m_buffer;
        m_buffer = buffer;
    }
    else
        m_buffer[m_size] = value;
    m_size++;
}
template <class T>
void Vector<T>::pop_back() {
    if (m_size != 0) {
        m_size--;
        //delete m_buffer[m_size];
    }
}

template <class T>
T* Vector<T>::insert(iterator pos, const T& value) {
    if (m_size + 1 > m_capacity) {
        for (iterator i = end(); i != pos; i--)
            *i = *(i - 1);
        *pos = value;
        m_size++;
        return pos;
    }
    else {
        T* buffer = new T[m_capacity * 2];
        iterator iter;
        iterator i;
        int j = 0;

        for (i = begin(); i != pos; i++, j++)
            buffer[j] = *i;
        buffer[j] = value;
        iter = &buffer[j];
        for (; i != end(); i++, j++)
            buffer[j] = *i;
        delete m_buffer;
        m_buffer = buffer;
        return iter;
    }
}

template <class T>
T* Vector<T>::erase(iterator pos) {
    for (iterator i = pos; i != end() - 1; i++)
        *i = *(i + 1);
    m_size--;
    // m_buffer[m_size] = T();
    return pos; 
}

template <class T>
T* Vector<T>::erase(iterator first, iterator last) {
    int dist = std::distance(first, last);
    iterator iter = first;

    for (iterator i = last; i != end(); i++) {
        *(i - dist) = *i;
    }
    //m_size -= dist;
    if (first == begin() && last == end()) {
        m_size = 0;
        return nullptr;
    }
    m_size -= dist;
    return iter;
}

template <class T>
void Vector<T>::clear() {
    m_size = 0;
}

}

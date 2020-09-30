#pragma once
#include "Vector.h"

namespace CBL {

template <class T>
Vector<T>::Vector() {}

template <class T>
Vector<T>::Vector (size_t size) {
    m_capacity = size;
    m_size = size;
    m_buffer = new T [size];
    for (int i = 0; i < size; i++)
        m_buffer[i] = T();
}

template <class T>
Vector<T>::Vector(size_t size, const T& value) {
    m_capacity = size;
    m_size = size;
    m_buffer = new T [size];
    for (int i = 0; i < size; i++)
        m_buffer[i] = value;
}

template <class T>
Vector<T>::Vector(iterator first, iterator last) {
    m_size = std::distance(first, last);
    m_capacity = m_size;
    m_buffer = new T [m_size];
    for (int i = 0; i < m_size; i++)
        m_buffer[i] = first[i];
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T>& lst) {
    m_size = lst.size();
    m_capacity = m_size;
    m_buffer = new T [m_size];
    for (int i = 0; i < m_size; i++)
        m_buffer[i] = *(lst.begin() + i);
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_buffer = new T[m_size];
    for (int i = 0; i < m_size; i++)
        m_buffer[i] = other.m_buffer[i];
}

template <class T>
Vector<T>::~Vector() {
    //delete m_buffer;
}

}

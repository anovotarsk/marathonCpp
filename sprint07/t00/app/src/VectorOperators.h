#pragma once
#include "Vector.h"

namespace CBL {

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    return Vector(other);
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& other) const {
    if (m_size == other.m_size) {
        for (int i = 0; i < m_size; i++)
            if (m_buffer[i] != other.m_buffer[i])
                return false;
        return true;
    }
    return false;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& other) const {
    return !operator==(other);
}

template <class T>
bool Vector<T>::operator<(const Vector<T>& other) const {
    bool flag = true;

    for (int i = 0; i < m_size && i < other.m_size; i++) {
        if (m_buffer[i] > other.m_buffer[i])
            return false;
        if (m_buffer[i] != other.m_buffer[i])
            flag = false;
    }
    if (m_size >= other.m_size || flag == false)
        return false;
    return true;
}

template <class T>
bool Vector<T>::operator>(const Vector<T>& other) const {
    bool flag = true;

    for (int i = 0; i < m_size && i < other.m_size; i++) {
        if (m_buffer[i] > other.m_buffer[i] == false)
            return false;
        if (m_buffer[i] != other.m_buffer[i])
            flag = false;
    }
    if (m_size <= other.m_size || flag == false)
        return false;
    return true;
}

template <class T>
bool Vector<T>::operator<=(const Vector<T>& other) const {
    for (int i = 0; i < m_size && i < other.m_size; i++) {
        if (m_buffer[i] <= other.m_buffer[i] == false)
            return false;
    }
    return true;
}

template <class T>
bool Vector<T>::operator>=(const Vector<T>& other) const {
    // for (int i = 0; i < m_size && i < other.m_size; i++) {
    //     if (m_buffer[i] < other.m_buffer[i])
    //         return false;
    // }
    // return true;
    if (operator==(other) || operator>(other))
        return true;
    return false;
}

}

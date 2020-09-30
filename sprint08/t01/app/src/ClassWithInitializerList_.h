#include "ClassWithInitializerList.h"

#include <iostream>

template <typename T>
template <typename...Args>
ClassWithInitializerList<T>::ClassWithInitializerList(Args&&... args) : m_vecOfArs({args...}) {}

template <typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::initializer_list<T> lst) {
    for (int i = 0; i < lst.size(); i++)
        m_vecOfArs.push_back(*(lst.begin() + i));
}

template <typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::vector<T>& vec) {
    m_vecOfArs(vec);
}

template <typename T>
void ClassWithInitializerList<T>::outputVector() const {
    for (int i = 0; i < m_vecOfArs.size(); i++)
        std::cout << m_vecOfArs[i] << std::endl;
}

#pragma once

#include <vector>

template <typename T>
class ClassWithInitializerList final {
public:
    template <typename...Args>
    ClassWithInitializerList(Args&&...args);
    ClassWithInitializerList(const std::initializer_list<T> lst);
    ClassWithInitializerList(const std::vector<T>& vec);
    
    void outputVector() const;
    
private:
    std::vector<T> m_vecOfArs;
};

#include "ClassWithInitializerList_.h"

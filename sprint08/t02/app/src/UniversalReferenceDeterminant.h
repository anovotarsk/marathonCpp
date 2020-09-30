#pragma once

#include <iostream>
#include <typeinfo>
#include <string>

namespace UniversalReferenceDeterminant {

template <typename T>
void determineReference(T&& obj) {
    std::cout << (static_cast<std::string>(typeid(obj).name()) == static_cast<std::string>("i") ? "int is " : "char is ");
    std::cout << (typeid(&obj).name()[1] == 'K' ? "l-value reference\n" : "r-value reference\n");
}

} // end namespace UniversalReferenceDeterminant

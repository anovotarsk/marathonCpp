#ifndef INVENTORY

#include <iostream>
#include <ostream>
#include <string>
#include <array>

void commandLoop();
std::string* strsplit(std::string str, char del, int *len);
void remove(std::string* mas, int len, std::array<std::string, 12>* items);
void insert(std::string* mas, int len, std::array<std::string, 12>* items);

#endif
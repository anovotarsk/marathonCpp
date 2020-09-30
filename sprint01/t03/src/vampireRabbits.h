#ifndef VAMPIRERABBITS

#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <list>
#include <random>
#include <unistd.h>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

void vampireRabbits();
void createRebiits(int count, std::list<Rabbit> &rabbits);
void ageControl(std::list<Rabbit> &rabbits);

#endif

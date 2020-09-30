#pragma once
#include <iostream>

class Creature {
public:
    Creature();
    ~Creature();
};

class Wolf : virtual public Creature {
public:
};

class Human : virtual public Creature {
public:
};

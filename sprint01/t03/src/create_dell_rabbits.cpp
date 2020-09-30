#include "vampireRabbits.h"

int randNum(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Rabbit createRabbit() {
    Rabbit rabbit;

    rabbit.age = 0;
    rabbit.gender = (randNum(0, 1)) ? Gender::Female : Gender::Male;
    rabbit.isVampire = (randNum(1, 100) == 50) ? true : false;
    if (rabbit.isVampire)
        rabbit.gender = Gender::Male;
    return rabbit;
}

void createRebiits(int count, std::list<Rabbit> &rabbits) {
    for (int i = 0; i < count; i++)
        rabbits.push_back(createRabbit()); 
}

void ageControl(std::list<Rabbit> &rabbits) {
    for (auto iter = rabbits.begin(); iter != rabbits.end(); iter++) {
        iter->age++;
        if (iter->isVampire == false && iter->age == 4) {
            rabbits.erase(iter);
        }
        else
            if (iter->isVampire == true && iter->age == 8) {
                rabbits.erase(iter);
            }
    }
}

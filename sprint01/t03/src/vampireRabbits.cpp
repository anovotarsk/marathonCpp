#include "vampireRabbits.h"

void output(std::list<Rabbit> rabbits) {
    int male = 0;
    int female = 0;
    int vampires = 0;

    for (Rabbit i : rabbits) {
        if (i.gender == Gender::Male && i.isVampire == false)
            male++;
        if (i.gender == Gender::Female && i.isVampire == false)
            female++;
        if (i.isVampire)
            vampires++;
    }
    std::cout << "Males: " << male << std::endl;
    std::cout << "Females: " << female << std::endl;
    std::cout << "Vampires: " << vampires << std::endl;
    if (male + female + vampires > 1000 || male + female + vampires == 0)
        exit(0);
    std::cout << std::endl;
}

void reproduction(std::list<Rabbit> &rabbits) {
    int male = 0;
    int female = 0;
    int need;

    for (auto i = rabbits.begin(); i != rabbits.end(); i++) {
        if (i->gender == Gender::Male)
            male++;
        else
            female++;
    }
    need = (male > female) ? female : male;
    createRebiits(need, rabbits);
}

void vampirism(std::list<Rabbit> &rabbits) {
    int vampires = 0;

    for (auto i = rabbits.begin(); i != rabbits.end(); i++) {
        if (i->isVampire && (i->gender == Gender::Male))
            vampires++;
    }
    for (auto i = rabbits.begin(); i != rabbits.end(); i++) {
        if (vampires < 1)
            break;
        if (i->isVampire == false) {
            i->isVampire = true;
            i->gender = Gender::Female;
            vampires--;
        }
    }
}

void vampireRabbits() {
    std::list<Rabbit> rabbits;
    int nonBornVampires = 0;

    createRebiits(10, rabbits);
    output(rabbits);
    sleep(1);
    while (true) {
        vampirism(rabbits);
        reproduction(rabbits);
        ageControl(rabbits);
        output(rabbits);
        sleep(1);
    }
}

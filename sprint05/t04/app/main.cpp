#include <iostream>
#include <string>
#include "Soldier.h"
#include "Weapon.h"

void argumentError(std::string str) {
    std::cout << "Argument " << str << " is not valid\n";
    exit(0);
}

int toInt(std::string str) {
    int damage;

    for (int i = 0; i < str.size(); i++) {
        if(!(std::isdigit(str[i])))
            argumentError(str);
    }
    damage = std::stoi(str);
    if (damage > 20 || damage < 10) {
        std::cerr << "Damage has to be in a range of 10-20 points.\n";
        exit(0);
    }
    return damage;
}

void fight(Imperial &imperial, Stormcloak &stormcloak) {
    std::cout << "\n***The battle has begun!***\n\n";
    while (imperial.getHealth() > 0 && stormcloak.getHealth() > 0) {
        stormcloak.attack(imperial);
        imperial.attack(stormcloak);
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    }
    std::cout << ((stormcloak.getHealth() >= imperial.getHealth()) ? "Stormcloak" : "Imperial");
    std::cout << " has won!\n\n";
}

int main(int argc, char *argv[]) {
    std::string str;
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
        return 0;
    }

    int sword = toInt(argv[1]);
    int axe = toInt(argv[2]);

    Imperial Martin("Martin", 100);
    Stormcloak Flynn("Flynn", 100);
    Martin.setWeapon(new Sword(sword));
    Flynn.setWeapon(new Axe(axe));

    fight(Martin, Flynn);
}

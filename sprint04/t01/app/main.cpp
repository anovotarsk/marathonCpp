#include <iostream>
#include <string>
#include "src/Axe.h"
#include "src/Sword.h"
#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"

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

void fight(Imperial &imperial, Stormcloak &stormcloak, char *args[]) {
    while (imperial.getHealth() > 0 && stormcloak.getHealth() > 0) {
        std::cout << "Imperial soldier attacks and deals " << args[1] << " damage\n";
        std::cout << "Stormcloak soldier consumes " << args[1] << " damage\n";
        std::cout << "Stormcloak soldier attacks and deals " << args[2] << " damage\n";
        std::cout << "Imperial soldier consumes " << args[2] << " damage\n";
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>\n";

        imperial.attack(stormcloak);
        stormcloak.attack(imperial);
    }
    std::cout << ((imperial.getHealth() >= stormcloak.getHealth()) ? "Imperial" : "Stormcloak");
    std::cout << " has won!\n";
}

int main(int argc, char *argv[]) {
    std::string str;
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
        return 0;
    }

    Imperial imperial;
    Stormcloak stormcloak;

    str = argv[1];
    imperial.setWeapon(new Sword(toInt(str)));
    str = argv[2];
    stormcloak.setWeapon(new Axe(toInt(str)));
    fight(imperial, stormcloak, argv);
}

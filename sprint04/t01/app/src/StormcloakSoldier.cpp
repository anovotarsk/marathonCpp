#include "StormcloakSoldier.h"
#include "ImperialSoldier.h"

Stormcloak::Stormcloak() {
    m_health = 100;
}

Stormcloak::~Stormcloak() {
    // try {
    // delete m_weapon;
    // }
    // catch(int a) {
    //     a = 0;
    // }
}

void Stormcloak::setWeapon(Axe* sword) {
    m_weapon = sword;
}

void Stormcloak::attack(Imperial& enemy) {
    enemy.consumeDamage(m_weapon->getDamage());
}

void Stormcloak::consumeDamage(int amount) {
    m_health -= amount;
}

int Stormcloak::getHealth() const {
    return m_health;
}

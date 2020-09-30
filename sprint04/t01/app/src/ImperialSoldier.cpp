#include "ImperialSoldier.h"
#include "StormcloakSoldier.h"

Imperial::Imperial() {
    m_health = 100;
}

Imperial::~Imperial() {
    delete m_weapon;
}

void Imperial::setWeapon(Sword* sword) {
    m_weapon = sword;
}

void Imperial::attack(Stormcloak& enemy) {
    enemy.consumeDamage(m_weapon->getDamage());
}

void Imperial::consumeDamage(int amount) {
    m_health -= amount;
}

int Imperial::getHealth() const {
    return m_health;
}

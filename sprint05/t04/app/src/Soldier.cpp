#include "Soldier.h"
#include "Weapon.h"

Soldier::Soldier(std::string&& name, int health) {
    m_health = health;
    m_name = name;
    std::cout << "Soldier " << m_name << " was created\n";
}

Soldier::~Soldier() {
    delete m_weapon;
    std::cout << "Soldier " << m_name << " was deleted\n";
}

void Soldier::setWeapon(Weapon* sword) {
    m_weapon = sword;
}

void Soldier::attack(Soldier& enemy) {
    enemy.m_health -= m_weapon->getDamage();
    std::cout << m_name << " attacks " << enemy.m_name << " and deals ";
    std::cout << m_weapon->getDamage() << " damage\n";
}

int Soldier::getHealth() const {
    return m_health;
}

Stormcloak::Stormcloak(std::string&& name, int health) : Soldier(std::move(name), health) {
    std::cout << "Stormcloak soldier was created\n";
}

Stormcloak::~Stormcloak() {
    std::cout << "Stormcloak soldier was deleted\n";
}

void Stormcloak::consumeDamage(int amount) {
}

Imperial::Imperial(std::string&& name, int health) : Soldier(std::move(name), health) {
    std::cout << "Imperial soldier was created\n";
}

Imperial::~Imperial() {
    std::cout << "Imperial soldier was deleted\n";
}

void Imperial::consumeDamage(int amount) {
}

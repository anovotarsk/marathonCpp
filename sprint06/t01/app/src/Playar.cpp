#include "Playar.h"


Player::Player(const std::string& name) {
    m_name = name;
}

void Player::openContainer(Container* container) {
    if (container->tryToOpen(m_lockpickSkill)) {
        std::cout << m_name << " successfully opened ";
        std::cout << container->name() << std::endl;
    }
    else {
        std::cout << m_name << " skill is too low to open ";
        std::cout << container->name() << std::endl;
    }
}

void Player::setLockpickSkill(LockpickDifficulty skill) {
    m_lockpickSkill = skill;
}

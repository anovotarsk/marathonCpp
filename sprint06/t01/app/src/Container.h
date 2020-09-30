#pragma once

#include "Interfaces.h"
#include <string>

class Container : public ILockable, public IOpenable {
public:
    Container(bool isLocked, const LockpickDifficulty difficulty);

    LockpickDifficulty lockDifficulty() const;
    bool isLocked() const;
    bool tryToOpen(LockpickDifficulty skill);

    virtual std::string name() const = 0;

private:
    bool m_isLocked{false};
    LockpickDifficulty m_difficulty;
};

class Barrel : public Container {
public:
    Barrel();

    std::string name() const;

};

class Chest : public Container {
public:
    Chest(bool isLocked, const LockpickDifficulty difficulty);

    std::string name() const;
};

class Safe : public Container {
public:
    Safe(bool isLocked, const LockpickDifficulty difficulty);

    std::string name() const;
};


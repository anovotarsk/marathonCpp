#pragma once

#include "LockpickDifficulty.h"

class IOpenable {
public:
    virtual bool tryToOpen(LockpickDifficulty) = 0;

};

class ILockable {
public:
    virtual LockpickDifficulty lockDifficulty() const = 0;
    virtual bool isLocked() const = 0;
};

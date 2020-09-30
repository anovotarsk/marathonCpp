#ifndef STORM
#define STORM

#include "Axe.h"
class Imperial;

class Stormcloak final {
public:
    Stormcloak();
    ~Stormcloak();

    void setWeapon(Axe* sword);
    void attack(Imperial& enemy);
    void consumeDamage(int amount);
    int getHealth() const;

private:
    Axe* m_weapon;
    int m_health;
};

#endif

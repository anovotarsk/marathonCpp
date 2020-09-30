#ifndef IMPERIAL
#define IMPERIAL

#include "Sword.h"
class Stormcloak;

class Imperial final {
public:
    Imperial();
    ~Imperial();

    void setWeapon(Sword* sword);
    void attack(Stormcloak& enemy);
    void consumeDamage(int amount);
    int getHealth() const;
    
private:
    Sword* m_weapon;
    int m_health;
};

#endif

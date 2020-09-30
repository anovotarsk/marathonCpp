/* Soldier.h */
#include <string>
#include <iostream>

class Weapon;

class Soldier {
public:
    Soldier(std::string&& name, int health);
    virtual ~Soldier();

    void attack(Soldier& other);
    void setWeapon(Weapon* weapon);
    
    int getHealth() const;

private:
    Weapon* m_weapon;
    std::string m_name;
    int m_health;
};

class Imperial;

class Stormcloak final : public Soldier {
public:
    Stormcloak(std::string&& name, int health);
    ~Stormcloak();

    void consumeDamage(int amount);
};

class Imperial final : public Soldier {
public:
    Imperial(std::string&& name, int health);
    ~Imperial();

    void consumeDamage(int amount);
};

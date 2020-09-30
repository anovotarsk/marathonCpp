/* Weapon.h */

class Weapon{
public:
    explicit Weapon(int damage);
    virtual ~Weapon() = default;

    int getDamage() const;

private:
    const int m_damage;
};

class Sword final : public Weapon {
public:
    Sword(int damage);
};

class Axe final : public Weapon {
public:
    Axe(int damage);
};

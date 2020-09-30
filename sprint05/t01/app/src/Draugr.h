#ifndef DRAUGR
#define DRAUGR

#include <iostream>

class Draugr {
public:
    Draugr();
    Draugr(int frostResist);
    Draugr(double health, int frostResist);

    void shoutPhrase(int shoutNumber) const;

private:
    double m_health;
    const int m_frostResist;
};

#endif

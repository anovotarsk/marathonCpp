#ifndef DRAUGR
#define DRAUGR

#include <iostream>
#include <array>
#include <string>



class Draugr {
public:
    Draugr();
    Draugr(int frostResist);
    Draugr(double health, int frostResist);

    Draugr(Draugr& other) = delete;
    Draugr& operator = (const Draugr&) = delete;
    Draugr(Draugr&& other)  = delete;
    Draugr&& operator = (const Draugr&&) = delete;

    void shoutPhrase(int shoutNumber) const;
    void setName(const std::string&& name);

private:
    std::string m_name;
    double m_health;
    const int m_frostResist;
};

std::string* strsplit(std::string str, char del, int *len);

#endif

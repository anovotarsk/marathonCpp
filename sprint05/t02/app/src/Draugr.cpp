#include "Draugr.h"

Draugr::Draugr() : Draugr(100, 50) {}

Draugr::Draugr(int frostResist) : Draugr(frostResist, 50) {}

Draugr::Draugr(double health, int frostResist) : 
            m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with " << m_health << " health and ";
    std::cout << m_frostResist << "% frost resist was born!\n";
}

Draugr::Draugr(Draugr& other) : Draugr(other.m_health, other.m_frostResist) {
    std::cout << "Copy constructor was called\n";
}

Draugr::Draugr(Draugr&& other) : Draugr(other.m_health, other.m_frostResist) {
    std::cout << "Move constructor was called\n";
}

void Draugr::shoutPhrase(int shoutNumber) const {
    if (shoutNumber < 0 || shoutNumber > 8) {
        std::cerr << "Invalid shoutNumber\n";
        return;
    }

    std::cout << "Draugr " << m_name << " (" << m_health << " health, ";
    std::cout << m_frostResist << "% frost resist) shouts:\n";
    std::array<std::string, 9> arr = {
        "Qiilaan Us Dilon!",
        "Bolog Aaz, Mal Lir!",
        "Kren Sosaal!",
        "Dir Volaan!",
        "Aar Vin Ok!",
        "Unslaad Krosis!",
        "Faaz! Paak! Dinok!",
        "Aav Dilon!",
        "Sovngarde Saraan!"
    };
    std::cout << arr[shoutNumber] << std::endl;
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

#include "Draugr.h"
#include <array>
#include <string>

Draugr::Draugr() : Draugr(100, 50) {}

Draugr::Draugr(int frostResist) : Draugr(100, frostResist) {}

Draugr::Draugr(double health, int frostResist) : 
            m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with " << m_health << " health and ";
    std::cout << m_frostResist << "% frost resist was born!\n";
}

void Draugr::shoutPhrase(int shoutNumber) const {
    if (shoutNumber < 0 || shoutNumber > 8) {
        std::cerr << "Invalid shoutNumber\n";
        return;
    }

    std::cout << "Draugr (" << m_health << " health, ";
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

#include "Draugr.h"
#include <array>
#include <string>

Draugr::Draugr() : m_frostResist(50), m_health(100) {}

void Draugr::shoutPhrase(int shoutNumber) const {
    if (shoutNumber < 0 || shoutNumber > 8) {
        std::cerr << "shoutNumber\n";
        return;
    }

    std::cout << "Draugr (100 health, 50% frost resist) shouts:\n";
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

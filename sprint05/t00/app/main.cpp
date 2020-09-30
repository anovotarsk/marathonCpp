#include "src/Draugr.h"

void argumentError(std::string str) {
    std::cout << "Invalid shoutNumber\n";
    exit(0);
}

int toInt(std::string str) {
    int damage;

    for (int i = 0; i < str.size(); i++) {
        if(!(std::isdigit(str[i])))
            argumentError(str);
    }
    damage = std::stoi(str);
    if (damage < 0 || damage > 8) {
        std::cerr << "Invalid shoutNumber\n";
        exit(0);
    }
    return damage;
}

int main(int argc, char *argv[]) {
    std::string str;
    int number;

    if (argc != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
        return 0;
    }
    str = argv[1];
    number = toInt(str);
    Draugr dr;
    dr.shoutPhrase(number);
}

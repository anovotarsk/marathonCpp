#include "src/Draugr.h"

void argumentError() {
    std::cerr << "Error\n";
    exit(0);
}

int toInt(std::string str) {
    int damage;

    for (int i = 0; i < str.size(); i++) {
        if(!(std::isdigit(str[i])))
            argumentError();
    }
    damage = std::stoi(str);
    return damage;
}

double toDouble(std::string str) {
    int i;
    int komas = 0;

    if (str[0] == '+' || str[0] == '-')
        i = 1;
    else
        i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            komas++;
            continue;
        }
        if (str[i] < 48 || str[i]> 57)
            argumentError();
    }
    if (komas > 1)
        argumentError();
    return std::stod(str);
}

int main(int argc, char *argv[]) {
    std::string shoutNumber;
    std::string health;
    std::string frostResist;
    int number;

    if (argc < 2 || argc > 4) {
        std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]\n";
        return 0;
    }

    shoutNumber = argv[1];
    number = toInt(shoutNumber);
    if (number < 0 || number > 8) {
        std::cerr << "Invalid shoutNumber\n";
        return 0;
    }
    if (argc == 2) {
        Draugr dr;
        dr.shoutPhrase(number);
    }
    else {
        health = argv[2];
        if (argc == 3) {
            if (toDouble(health) < 0 || toDouble(health) > 100)
                argumentError();
            Draugr dr(toDouble(health));
            dr.shoutPhrase(number);
        }
        else {
            frostResist = argv[3];
            if (toDouble(health) < 0 || toDouble(health) > 100)
                argumentError();
            if (toInt(frostResist) < 0 || toInt(frostResist) > 100)
                argumentError();
            Draugr dr(toDouble(health), toInt(frostResist));
            dr.shoutPhrase(number);
        }
    }
}

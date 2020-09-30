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
    std::string* names;
    int number;
    int len;

    if (argc < 4 || argc > 5) {
        std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]\n";
        return 0;
    }

    number = toInt(argv[1]);
    if (number < 0 || number > 8) {
        std::cerr << "Invalid shoutNumber\n";
        return 0;
    }

    names = strsplit(argv[2], ',', &len);
    if (len != 2) {
        std::cerr << "Invalid names\n";
        return 0;
    }
    if (argc == 4) {
        if (toDouble(argv[3]) < 0 || toDouble(argv[3]) > 100)
                argumentError();
        Draugr dr1(toDouble(argv[3]));
        dr1.setName(std::move(names[0]));
        dr1.shoutPhrase(number);
        Draugr dr2(dr1);
        dr2.setName(std::move(names[1]));
        dr2.shoutPhrase(number);
    }
    else {
        if (argc == 5) {
            if (toDouble(argv[3]) < 0 || toDouble(argv[3]) > 100
                || toInt(argv[4]) < 0 || toInt(argv[4]) > 100)
                argumentError();
            Draugr dr1(toDouble(argv[3]), toInt(argv[4]));
            dr1.setName(std::move(names[0]));
            dr1.shoutPhrase(number);
            Draugr dr2(std::move(dr1));
            dr2.setName(std::move(names[1]));
            dr2.shoutPhrase(number);
        }
    }
}

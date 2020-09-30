#include <iostream>
#include <ostream>
#include <typeinfo>
#include <string>

int level(char *str) {
    int i;

    if (str[0] == '+' || str[0] == '-')
        i = 1;
    else
        i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i]> 57) {
            std::cerr << "Invalid argument: " << str << std::endl;
            exit(0);
        }
    }
    return std::stoi(str);
}

float health(char *str) {
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
        if (str[i] < 48 || str[i]> 57) {
            std::cerr << "Invalid argument: " << str << std::endl;
            exit(0);
        }
    }
    if (komas > 1) {
        std::cerr << "Invalid argument: " << str << std::endl;
        exit(0);
    }
    return std::stof(str);
}

double stamina(char *str) {
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
        if (str[i] < 48 || str[i]> 57) {
            std::cerr << "Invalid argument: " << str << std::endl;
            exit(0);
        }
    }
    if (komas > 1) {
        std::cerr << "Invalid argument: " << str << std::endl;
        exit(0);
    }
    return std::stod(str);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]\n";
        return 0; 
    }

    auto name = static_cast<std::string>(argv[1]);
    auto lvl = level(argv[2]);
    auto hlth = health(argv[3]);
    auto stm = stamina(argv[4]);
    std::cout << "Name = " << name << std::endl;
    std::cout << "Level = " << lvl << std::endl;
    std::cout << "Health = " << hlth << std::endl;
    std::cout << "Stamina = " << stm << std::endl;
}

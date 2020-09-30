#include "src/MoveManager.h"
#include <iostream>

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

int main(int argc, char *argv[]) {
    int width;
    int heigth;
    std::string str;

    srand(time(NULL));
    if (argc != 3) {
        std::cerr << "usage: ./smartPointers [width] [height]\n";
        return 0;
    }
    width = toInt(argv[1]);
    heigth = toInt(argv[2]);    
    if (width < 5 || width > 20 || heigth < 5 || heigth > 20) {
        std::cerr << "Invalid map size\n";
        return 0;
    }

    std::shared_ptr<Player> p(new Player());
    std::shared_ptr<Map> m (new Map(width, heigth, p));
    MoveManager manager(p, m); 

    m->outputMap();

    while (true) {
        std::cout << ":> ";
        std::getline(std::cin, str);
        if (str == "e")
            return 0;
        manager.processInputAndMove(str);
    }
}


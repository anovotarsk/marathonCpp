#include "inventory.h"

void insert(std::string* mas, int len, std::array<std::string, 12>* items) {
    if (len != 2) {
        std::cout << "Invalid command.\n";
        return;
    }
    if (mas[1] != "w" && mas[1] != "f" && mas[1] != "a" && mas[1] != "p") {
        std::cout << "Invalid item.\n";
        return;
    }
    for (int i = 0; i < 12; i++) {
        if ((*items)[i] == "-") {
            (*items)[i] = mas[1];
            std::cout << mas[1] << " was insered.\n";
            return;
        }
    }
    std::cout << "Inventory is full.\n";
}

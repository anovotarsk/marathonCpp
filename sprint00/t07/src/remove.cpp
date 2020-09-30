#include "inventory.h"

void remove(std::string* mas, int len, std::array<std::string, 12>* items) {
    std::string tmp;

    if (len != 2) {
        std::cout << "Invalid command.\n";
        return;
    }
    if (mas[1] != "w" && mas[1] != "f" && mas[1] != "a" && mas[1] != "p") {
        std::cout << "Invalid item.\n";
        return;
    }
    for (int i = 0; i < 12; i++) {
        if ((*items)[i] == mas[1]) {
            (*items)[i] = "-";
            for (int j = i; j < 11; j++) {
                tmp = (*items)[j];
                (*items)[j] = (*items)[j + 1];
                (*items)[j + 1] = tmp;
            }
            std::cout << mas[1] << " was removed.\n";
            return;
        }
    }
    std::cout << "Invalid item.\n";
}

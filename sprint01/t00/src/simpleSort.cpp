#include "simpleSort.h"

void simpleSort(int argc, char *argv[]) {
    std::array<std::string, 5> mas;
    for (int i = 1; i < 6; i++)
        mas[i - 1] = argv[i];
    std::sort(mas.begin(), mas.end());
    for (int i = 0; i < 4; i++)
        std::cout << mas[i] << " ";
    std::cout << mas[4] << std::endl;
}

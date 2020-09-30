#include "src/simpleSort.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5\n";
        exit(0);
    }
    simpleSort(argc, argv);
}

#include "src/visitAll.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
        return 0;
    }
    visitAll(argc, argv);
    //system("leaks -q a.out");
}

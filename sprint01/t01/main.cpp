#include "src/moveAlong.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "usage: ./moveAlong [args]\n";
        return 0;
    }
    moveAlong(argc, argv);
}

#include "src/stdAlgoV1.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV1 [file_name]\n";
        return 0;
    }
    stdAlgoV1(argv[1]);
}

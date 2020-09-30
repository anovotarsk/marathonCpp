#include "src/stdAlgoV2.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./stdAlgoV2 [file_name]\n";
        return 0;
    }
    stdAlgoV2(argv[1]);
}

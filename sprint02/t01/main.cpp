#include "src/countUniqueWords.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./countUniqueWords [file_name]\n";
        return 0;
    }
    countUniqueWords(argv[1]);
}

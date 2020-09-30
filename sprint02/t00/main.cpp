#include "src/uniqueWords.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./uniqueWords [file_name]\n";
        return 0;
    }
    uniqueWords(argv[1]);
    fd.close();
}

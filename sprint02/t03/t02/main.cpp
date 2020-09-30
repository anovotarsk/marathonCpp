#include "src/bookSaver.h"

int main(int argc, char *argv[]) {
    if (argc != 1) {
        std::cerr << "usage: ./tesLibrary [file_name]\n";
        return 0;
    }
    bookSaver();
}

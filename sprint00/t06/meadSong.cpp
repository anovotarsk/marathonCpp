#include "meadSong.h"

void firstPart(int i) {
    std::cout << i << " bottles of mead on the wall, ";
    std::cout << i << " bottles of mead.\n";

    std::cout << "Take one down and pass it around, " << i - 1;
    std::cout << " bottles of mead on the wall.\n\n";
}

void secondPart() {
    std::cout << "2 bottles of mead on the wall, 2 bottles of mead.\n";
    std::cout << "Take one down and pass it around, ";
    std::cout << "1 bottle of mead on the wall.\n\n";
}

void thirdPart() {
    std::cout << "1 bottle of mead on the wall, 1 bottle of mead.\n";
    std::cout << "Take it down and pass it around, ";
    std::cout << "no more bottles of mead on the wall.\n\n";
}

void fourthPart() {
    std::cout << "No more bottles of mead on the wall, no more bottles of mead";
    std::cout << ".\nGo to the store and buy some more, ";
    std::cout << ", 99 bottles of mead on the wall.\n";
}

void meadSong() {
    for (int i = 99; i > 2; i--)
        firstPart(i);
    secondPart();
    thirdPart();
    fourthPart();
}

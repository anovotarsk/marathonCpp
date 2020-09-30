#include "moveAlong.h"

void toLower(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

void moveAlong(int argc, char *argv[]) {
    std::vector<char*> names;
    std::vector<char*> lower;

    for (int i = 1; i < argc; i++) {
        names.push_back(argv[i]);
        lower.push_back(strdup(argv[i]));
        toLower(lower[i - 1]);
    }
    for (int i = 0; i < lower.size(); i++) {
        if (strstr(lower[i], "mercer") != NULL) {
            std::cout << names[i] << ", move along!\n";
            continue;
        }
        if (strstr(lower[i], "emer") != NULL) {
            std::cout << names[i] << ", move along!\n";
            continue;
        }
        if (strstr(lower[i], "jim") != NULL) {
            std::cout << names[i] << ", move along!\n";
            continue;
        }
    }
    for (int i = 0; i < lower.size(); i++)
        delete lower[i];
}

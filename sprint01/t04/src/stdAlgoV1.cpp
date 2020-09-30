#include "stdAlgoV1.h"

bool validString(std::string str) {
    if (str.length() == 0)
        return false;
    for (int i = 0; i < str.length(); i++)
        if (isspace(str[i]) == false)
            return true;
    return false;
}

std::forward_list<std::string> fileToList(char *file) {
    std::forward_list<std::string> names;
    std::string tmp;
    std::ifstream fd(file);

    if (fd.is_open() == false) {
        std::cerr << "error\n";
        exit(0);
    }
    if (getline(fd, tmp) && validString(tmp))
        names.push_front(tmp);
    else {
        std::cerr << "error\n";
        exit(0);
    }
    while (getline(fd, tmp)) {
        if (validString(tmp))
            names.push_front(tmp);
        else {
            std::cerr << "error\n";
            exit(0);
        }
    }
    fd.close();
    return names;
}

int listSize(std::forward_list<std::string> names) {
    int len = 0;

    for (std::string i : names)
        len++;
    return len;
}

bool containsRich(std::forward_list<std::string> names) {
    for (std::string i : names)
        if (i.find("rich") != std::string_view::npos)
            return true;
    return false;
}

bool nonOfLength(int len, std::forward_list<std::string> names) {
    for (std::string i : names)
        if (i.length() == 15)
            return false;
    return true;
}

bool allEndWithVel(std::forward_list<std::string> names) {
    for (std::string i : names)
        if (i.find("vel", i.length() - 3) != i.length() - 3)
            return false;
    return true;
}

int notContainsMel(std::forward_list<std::string> names) {
    int count = 0;

    for (std::string i : names)
        if (i.find("mel") == std::string_view::npos)
            count++;
    return count;
}

void stdAlgoV1(char *file) {
    std::forward_list<std::string> names = fileToList(file);

    std::cout << "size: " << listSize(names) << std::endl;
    std::cout << "contains 'rich': " << (containsRich(names) ? "true" : "false")  << std::endl;
    std::cout << "none of lengths is 15: " << (nonOfLength(15, names) ? "true" : "false")  << std::endl;
    std::cout << "all end with 'vel': " << (allEndWithVel(names) ? "true" : "false")  << std::endl;
    std::cout << "not contains 'mel': " << notContainsMel(names) << std::endl;
}

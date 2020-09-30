#include "stdAlgoV2.h"

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

void eraseNode(int num, std::forward_list<std::string> &names) {
    if (num == 0) {
        names.pop_front();
        return;
    }
    int j = 1;
    auto i = names.begin();
    for (; i != names.end() && j < num; i++, j++);
    names.erase_after(i);
}

std::ofstream openToWrite(char *file) {
    int len;
    std::string *tmp = strsplit(file, '/', &len);
    std::string *parse = strsplit(tmp[len - 1], '.', &len);
    std::string str = parse[0] + "_mod";
    std::ofstream fd;

    delete [] tmp;
    for (int i = 1; i < len; i++)
        str = str + "." + parse[i];
    fd.open(str);
    if (fd.is_open() == false) {
        std::cerr << "error\n";
        exit(0);
    }
    return fd;
}

bool wasOutput(std::string str,std::forward_list<std::string> &dup) {
    for (std::string i : dup) {
        if (str == i)
            return true;
    }
    return false;
}

void writeToFile(std::string str, std::ofstream &fd) {
    if (str.length() > 10)
        fd << "Long one\n";
    else {
        if (str.length() < 4)
            fd << "Short one\n";
        else
            fd << str << std::endl;
    }   
}

void removeCBL(std::forward_list<std::string> &names, std::forward_list<std::string> &dup, std::ofstream &fd) {
    for (std::string i : names) {
        if (i.find("c") == std::string_view::npos
            && i.find("b") == std::string_view::npos
            && i.find("l") == std::string_view::npos) {
            if (wasOutput(i, dup) == false) {
                writeToFile(i, fd);
                dup.push_front(i);
            }
        }
        
    }
}

void replase(){}

void stdAlgoV2(char *file) {
    std::forward_list<std::string> names = fileToList(file);
    std::forward_list<std::string> dup;
    std::ofstream fd = openToWrite(file);

    removeCBL(names, dup, fd);
}

#include "bookSaver.h"

void addBook(std::string *mas, int len,
             std::map<std::string, std::string> &books) {
    std::string book;
    std::ifstream fd;

    if (len != 2) {
        std::cout << "invalid command\n";
        return;
    }
    fd.open("./library/" + mas[1]);
    if (fd.is_open() == false || !getline(fd, book, '\0')) {
        std::cout << "invalid book\n";
        return;
    }
    books.insert(std::pair<std::string, std::string>(mas[1], book));
    std::cout << mas[1] << " added\n";
}

void deleteBook(std::string *mas, int len,
             std::map<std::string, std::string> &books) {
    std::map<std::string, std::string>::iterator iter;

    if (len != 2) {
        std::cout << "invalid command\n";
        return;
    }
    iter = books.find(mas[1]);
    if (iter == books.end()) {
        std::cout << "invalid book\n";
        return;
    }
    books.erase(iter);
    std::cout << mas[1] << " deleted\n";
}

void list(std::string *mas, int len,
             std::map<std::string, std::string> &books) {
    if (len != 1) {
        std::cout << "invalid command\n";
        return;
    }
    for (auto i = books.begin(); i != books.end(); i++)
        std::cout << i->first << std::endl;
}

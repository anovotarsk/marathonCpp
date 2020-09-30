#include "bookSaver.h"

void addBook(char *str, std::multimap<std::string, std::string> &books) {
    std::string book;
    std::ifstream fd;
    std::regex r("[\\s]*\"[\\s\\S]+\"[\\s]*:[\\s]*\"[\\s\\S]+\"[\\s]*");
    std::smatch m;
    std::string str;


    fd.open(str);
    if (fd.is_open() == false) {
        std::cout << "error\n";
        return;
    }
    while (getline(fd, book)) {
        if (regex_match(book, r)) {
            regex_search(book, m, r);
            str = m[0];
        }
    }
    //books.insert(std::pair<std::string, std::string>(mas[1], book));
}

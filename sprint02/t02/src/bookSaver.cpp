#include "bookSaver.h"

void quit(std::string *mas, int len) {
    if (len != 1) {
        std::cout << "Invalid command.\n";
        return;
    }
    std::cout << "bye\n";
    exit(0);
}

void readBook(std::string *mas, int len,
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
    std::cout << iter->second << std::endl;
}

void whichCommand(std::string *mas, int len,
                  std::map<std::string, std::string> &books) {
    if (len != 0) {
        if (mas[0] == "add")
            addBook(mas, len, books);
        else
            if (mas[0] == "delete")
                deleteBook(mas, len, books);
            else
                if (mas[0] == "read")
                    readBook(mas, len, books);
                else
                    if (mas[0] == "list")
                        list(mas, len, books);
                    else
                        if (mas[0] == "quit")
                            quit(mas, len);
                        else
                            std::cout << "Invalid command.\n";
    }
}

void bookSaver() {
    std::string str;
    std::string* mas;
    std::map<std::string, std::string> books;    
    int len;

    while (true) {
        std::cout << "enter command:> ";
        getline(std::cin, str);
        mas = strsplit(str, ' ', &len);
        whichCommand(mas, len, books);
    }
}

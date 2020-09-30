#include "inventory.h"

void show(std::string* mas, int len, std::array<std::string, 12> items) {
    if (len != 1) {
        std::cout << "Invalid command.\n";
        return;
    }
    std::cout << "Inventory { ";
    for (int i = 0; i < 12; i++)
        std::cout << items[i] << " ";
    std::cout << "}\n";
}

void help(std::string* mas, int len) {
    if (len != 1) {
        std::cout << "Invalid command.\n";
        return;
    }
    std::cout << "Available command:\n";
    std::cout << "1. insert <itemType>\n";
    std::cout << "2. remove <itemType>\n";
    std::cout << "3. show inventory\n";
    std::cout << "4. help\n";
    std::cout << "5. exit\n";
}

void bye(std::string* mas, int len) {
    if (len != 1) {
        std::cout << "Invalid command.\n";
        return;
    }
    std::cout << "Bye.\n";
    exit(0);
}

void whichCommand(std::string* mas, int len, std::array<std::string, 12>* items) {
    if (len != 0) {
        if (mas[0] == "insert")
            insert(mas, len, items);
        else
            if (mas[0] == "remove")
                remove(mas, len, items);
            else
                if (mas[0] == "show")
                    show(mas, len, *items);
                else
                    if (mas[0] == "help")
                        help(mas, len);
                    else
                        if (mas[0] == "exit")
                            bye(mas, len);
                        else
                            std::cout << "Invalid command.\n";
    }
}

void commandLoop() {
    std::string str;
    std::string* mas;
    int len;
    std::array<std::string, 12> items;

    for (int i = 0; i < 12; i++)
        items[i] = "-";
    while (true) {
        std::cout << "Enter command:> ";
        getline(std::cin, str);
        mas = strsplit(str, ' ', &len);
        whichCommand(mas, len, &items);
    }
}

#include "uniqueWords.h"

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

std::set<std::string> fileToSet(char *file) {
    std::set<std::string> words;
    std::string tmp;
    std::ifstream fd(file);
    std::regex r("[a-zA-Z0-9'-]+");
    std::smatch m;

    if (fd.is_open() == false || !(fd >> tmp)) {
        std::cerr << "error\n";
        exit(0);
    }
    while (regex_search(tmp, m, r)) {
            words.insert(m[0]);
            tmp = m.suffix();
    }
    while (fd >> tmp) {
        while (regex_search(tmp, m, r)) {
            words.insert(m[0]);
            tmp = m.suffix();
        }
    }
    fd.close();
    return words;
}

void uniqueWords(char *file) {
    std::set<std::string> words = fileToSet(file);
    std::ofstream fd = openToWrite(file);

    for (auto i : words)
        fd << i << std::endl;
}

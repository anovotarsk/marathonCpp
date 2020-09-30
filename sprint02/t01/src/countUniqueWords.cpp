#include "countUniqueWords.h"

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

std::multiset<std::string> fileToSet(char *file) {
    std::multiset<std::string> words;
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

void countUniqueWords(char *file) {
    std::multiset<std::string> words = fileToSet(file);
    std::ofstream fd = openToWrite(file);

    int count;
    for (auto i = words.begin(); i != words.end(); i++) {
        count = words.count(*i);
        fd << *i << ": " << count << std::endl;
        for (int j = 0; j < count - 1; j++)
            i++;
    }
    fd.close();
}

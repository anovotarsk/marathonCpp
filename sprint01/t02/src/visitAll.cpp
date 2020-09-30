#include "visitAll.h"

void argumentError(char *str) {
    std::cout << "Argument " << str << " is not valid\n";
    exit(0);
}

int toInt(std::string num, char *arg) {
    int i;

    if (num[0] == '+' || num[0] == '-')
        i = 1;
    else
        i = 0;
    for (; i < num.length(); i++) {
        if (num[i] < 48 || num[i]> 57)
            argumentError(arg);
    }
    return std::stoi(num);
}

void parser(int argc, char *argv[], std::deque<std::string>* name,
            std::deque<int>* stamina, std::deque<int>* distance) {
    std::string *tmp;
    int len;

    for (int i = 1; i < argc; i++) {
        tmp = strsplit(argv[i], ',', &len);
        if (len != 3)
            argumentError(argv[i]);
        (*name).push_back(tmp[0]);
        (*stamina).push_back(toInt(tmp[1], argv[i]));
        (*distance).push_back(toInt(tmp[2], argv[i]));
        delete [] tmp;
        tmp = nullptr;
    }
    if ((*name).size() == 1) {
        std::cout << "0. " << (*name)[0] << std::endl;
        exit(0);
    }
}

void output(int best, std::deque<std::string> name) {
    int current;

    for (int i = best; i < name.size() + best; i++) {
        current = (i < name.size()) ? i : i - (name.size());
        std::cout << current << ". " << name[current] << std::endl;
    }
}

void visitAll(int argc, char *argv[]) {
    std::deque<std::string> name;
    std::deque<int> stamina;
    std::deque<int> distance;
    int done = -1;
    int best = -1;
    int power = 0;

    parser(argc, argv, &name, &stamina, &distance);
    for (int i = 0; i < argc - 1; i++) {
        for (int j = i; j < argc - 1 + i; j++) {
            int current = (j < argc - 1) ? j : j - (argc - 1);
            power = power + stamina[current] - distance[current];
            if (power < 0) break;
        }
        if (power > best) {
            best = power;
            done = i;
        }
        power = 0;
    }
    if (done == -1) {
        std::cout << "Mission: Impossible\n";
        return;
    }
    output(done, name);
}

#include "src/Worker.h"
#include "src/MultithreadedClass.h"
#include <iostream>
#include <string>

void argumentError() {
    std::cerr << "Incorrect values\n";
    exit(0);
}

int toInt(std::string str) {
    int damage;
    int i = (str[0] == '-' ? 1 : 0);

    for (; i < str.size(); i++) {
        if(!(std::isdigit(str[i])))
            argumentError();
    }
    damage = std::stoi(str);
    return damage;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]\n";
        return 0;
    }
    int count = toInt(argv[3]);
    int addValue = toInt(argv[1]);
    int subtractValue = toInt(argv[2]);
    if (count < 5 || count > 10 || addValue < -2000 || addValue > 2000
        || subtractValue < -2000 || subtractValue > 2000)
        argumentError();

    MultithreadedClass obj;
    
    Worker worker;
    
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }
    
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }
    
    worker.joinAllThreads();
    
    std::cout<< obj.getInt() << std::endl;
}

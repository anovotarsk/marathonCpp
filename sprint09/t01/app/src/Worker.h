#pragma once

#include <thread>
#include <vector>

class Worker {
public:
    Worker() = default;
    Worker(Worker& worker) = delete;
    Worker(Worker&& worker) = delete;
    ~Worker();
    
    template <typename Function, class... Args>
    void startNewThread(Function&& func, Args&&...args);
    
    void joinAllThreads();

private:
    std::vector<std::thread> m_workerThreads;
};

#include "WorkerHelp.h"

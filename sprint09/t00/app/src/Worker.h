#pragma once

#include <thread>

class Worker {
public:
    Worker() = default;
    Worker(Worker& worker) = delete;
    Worker(Worker&& worker) = delete;
    ~Worker();
    
    template <typename Function, class... Args>
    void startWorker(Function&& func, Args&&...args);
    
    void joinThread();

private:
    std::thread* m_thread{nullptr};
};

#include "WorkerHelp.h"

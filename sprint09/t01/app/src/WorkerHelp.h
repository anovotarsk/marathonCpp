#pragma once

#include "Worker.h"
#include "MultithreadedClass.h"
#include <iostream>

Worker::~Worker() {
    joinAllThreads();
}

template <typename Function, class... Args>
void Worker::startNewThread(Function&& func, Args&&...args) {
    m_workerThreads.push_back(std::thread(func, args...));
}

void Worker::joinAllThreads() {
    for (int i = 0; i < m_workerThreads.size(); i++)
    if (m_workerThreads[i].joinable())
        m_workerThreads[i].join();
}

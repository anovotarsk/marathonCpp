#pragma once

#include "Worker.h"

Worker::~Worker() {
    joinThread();
    if (m_thread != nullptr)
        delete m_thread;
}

template <typename Function, class... Args>
void Worker::startWorker(Function&& func, Args&&...args) {
    if (m_thread != nullptr && m_thread->joinable())
        joinThread();
    m_thread = new std::thread(func, args...);


}

void Worker::joinThread() {
    if (m_thread != nullptr && m_thread->joinable()) {
        m_thread->join();
        delete m_thread;
        m_thread = nullptr;
    }
}

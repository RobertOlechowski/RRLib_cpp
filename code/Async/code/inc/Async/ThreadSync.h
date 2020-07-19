#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>


namespace RRLibs::Async {

class ThreadSync {
public:
    using LockType = std::unique_lock<std::mutex>;

    ThreadSync();

    void wait(LockType& lck);

    void set_ready();

    LockType create_lock();

private:
    std::mutex& get_mutex();

    std::mutex m_mutex;
    std::condition_variable m_cv;
    bool ready;

};
}

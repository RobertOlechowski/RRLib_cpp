#include "Async/ThreadSync.h"

namespace RRLibs::Async {

ThreadSync::ThreadSync() {
    ready = false;
}

void ThreadSync::wait(ThreadSync::LockType& lck) {
    ready = false;
    while (!ready) m_cv.wait(lck);
}

void ThreadSync::set_ready() {
    ready = true;
    m_cv.notify_all();
}

std::mutex& ThreadSync::get_mutex() {
    return m_mutex;
}

ThreadSync::LockType ThreadSync::create_lock() {
    return ThreadSync::LockType(m_mutex);
}
}

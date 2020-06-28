#pragma once
#include "CircularBuffer.h"
#include <mutex>
#include <condition_variable>

namespace ContainersRR {

template<class T>
class CircularBufferTs {
public:
    explicit CircularBufferTs<T>(size_t max_size);

    void add(T item);
    void add_lock(T item);

    T pop();
    T pop_lock();

    bool is_empty() const noexcept;
    bool is_full() const noexcept;

private:
    CircularBuffer<T> m_guarded_container;
    std::mutex m_mutex;
    std::condition_variable m_cv;
};

template<class T>
CircularBufferTs<T>::CircularBufferTs(size_t max_size)
    : m_guarded_container(max_size) {
}

template<class T>
void CircularBufferTs<T>::add(T item) {
    m_guarded_container.add(item);
}

template<class T>
T CircularBufferTs<T>::pop() {
    return m_guarded_container.pop();
}

template<class T>
T CircularBufferTs<T>::pop_lock() {
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_guarded_container.is_empty()) {
        m_cv.wait(lock, [this] { return !m_guarded_container.is_empty(); });
    }
    T item = m_guarded_container.pop();

    lock.unlock();
    m_cv.notify_all();
    return item;
}

template<class T>
void CircularBufferTs<T>::add_lock(T item) {
    std::unique_lock<std::mutex> lock(m_mutex);

    if (m_guarded_container.is_full())
        m_cv.wait(lock, [this] { return !m_guarded_container.is_full(); });

    m_guarded_container.add(item);
    lock.unlock();
    m_cv.notify_all();
}

template<class T>
bool CircularBufferTs<T>::is_empty() const noexcept {
    return m_guarded_container.is_empty();
}

template<class T>
bool CircularBufferTs<T>::is_full() const noexcept {
    return m_guarded_container.is_full();
}

};
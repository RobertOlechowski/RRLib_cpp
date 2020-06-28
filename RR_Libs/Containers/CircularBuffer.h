#pragma once

#include "Common/NonCopyableNotMovable.h"

#include <memory>
#include <type_traits>
#include <iostream>

namespace ContainersRR {

template<class T>
class CircularBuffer {
public:
    explicit CircularBuffer<T>(size_t max_size);

    bool try_add(T item) noexcept;
    void add(T item);
    T pop();

    bool is_empty() const noexcept;
    bool is_full() const noexcept;
    size_t size() const noexcept;

private:
    std::unique_ptr<T[]> buffer;
    const size_t m_max_size;
    size_t m_index = 0;
    size_t m_size = 0;
};

template<class T>
CircularBuffer<T>::CircularBuffer(size_t max_size)
    : buffer(std::unique_ptr<T[]>(new T[max_size]))
    , m_max_size(max_size) {
        static_assert(std::is_pointer<T>::value || std::is_scalar<T>::value, "Wrong type");
};

template<class T>
bool CircularBuffer<T>::try_add(T item) noexcept {
    if (is_full())
        return false;
    const size_t index = (m_index + m_size++) % m_max_size;
    buffer[index] = item;
    return true;
}

template<class T>
void CircularBuffer<T>::add(T item) {
    if (!try_add(item))
        throw std::runtime_error("buffer is full");
}

template<class T>
T CircularBuffer<T>::pop() {
    if (is_empty())
        throw std::runtime_error("buffer is empty");

    T item;
    std::swap(item, buffer[m_index]);
    m_size--;
    m_index = (m_index + 1) % m_max_size;
    return item;
}

template<class T>
bool CircularBuffer<T>::is_empty() const noexcept { return m_size == 0; }

template<class T>
bool CircularBuffer<T>::is_full() const noexcept { return m_size == m_max_size; }

template<class T>
size_t CircularBuffer<T>::size() const noexcept { return m_size; }

}


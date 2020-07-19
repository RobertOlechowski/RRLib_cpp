#include "Async/AsyncTaskBase.h"

#include <functional>

namespace RRLibs::Async {

void AsyncTaskBase::start_async() {
    auto func = std::bind(&AsyncTaskBase::_start_impl, this);
    m_future = std::async(std::launch::async, func);
}

void AsyncTaskBase::join() {
    m_future.wait();
}

}
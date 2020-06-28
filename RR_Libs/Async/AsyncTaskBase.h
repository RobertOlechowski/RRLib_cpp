#pragma once

#include "Common/NonCopyableNotMovable.h"
#include "Common/Types.h"

#include <memory>
#include <future>

namespace RRAsyncNS {

class AsyncTaskBase : public RRUtils::NonCopyableNotMovable {
public:
    ~AsyncTaskBase() override = default;

    void start_async();

    void join();

protected:
    virtual void _start_impl() = 0;

    std::future<void> m_future;
};

}



#pragma once

#include "Common/NonCopyableNotMovable.h"
#include <vector>

namespace RRAsyncNS {

class AsyncTaskBase;

class AsyncTasksCollection : public RRUtils::NonCopyableNotMovable {
public:
    explicit AsyncTasksCollection(size_t size = 10);

    ~AsyncTasksCollection() override;

    void add_async(AsyncTaskBase* arg);

    template<typename T, typename... A>
    T* make_add(A&& ... args) {
        T* ptr = new T(std::forward<A>(args)...);
        add_async(ptr);
        return ptr;
    }

    void start_all() const;

    void join_all() const;

    void start_join_all() const;

private:
    std::vector<AsyncTaskBase*> m_tasks;
};

}


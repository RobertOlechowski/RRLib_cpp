#pragma once

#include <Common/NonCopyableNotMovable.h>

#include <vector>

namespace RRLibs::Async {

class AsyncTaskBase;

class TasksCollection : public Common::NonCopyableNotMovable {
public:
    explicit TasksCollection(size_t size = 10);

    ~TasksCollection() override;

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


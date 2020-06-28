#include "AsyncTasksCollection.h"

#include "AsyncTaskBase.h"

namespace RRAsyncNS {

AsyncTasksCollection::AsyncTasksCollection(size_t size) {
    m_tasks.reserve(size);
}

AsyncTasksCollection::~AsyncTasksCollection() {
    for (const AsyncTaskBase* item : m_tasks)
        delete item;
}


void AsyncTasksCollection::add_async(AsyncTaskBase* arg) {
    m_tasks.push_back(arg);
}

void AsyncTasksCollection::start_all() const {
    for (AsyncTaskBase* item : m_tasks)
        item->start_async();
}

void AsyncTasksCollection::join_all() const {
    for (AsyncTaskBase* item : m_tasks)
        item->join();
}

void AsyncTasksCollection::start_join_all() const {
    start_all();
    join_all();
}

}


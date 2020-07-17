#include "TasksCollection.h"

#include "AsyncTaskBase.h"

namespace RRLibs::Async {

TasksCollection::TasksCollection(size_t size) {
    m_tasks.reserve(size);
}

TasksCollection::~TasksCollection() {
    for (const AsyncTaskBase* item : m_tasks)
        delete item;
}


void TasksCollection::add_async(AsyncTaskBase* arg) {
    m_tasks.push_back(arg);
}

void TasksCollection::start_all() const {
    for (AsyncTaskBase* item : m_tasks)
        item->start_async();
}

void TasksCollection::join_all() const {
    for (AsyncTaskBase* item : m_tasks)
        item->join();
}

void TasksCollection::start_join_all() const {
    start_all();
    join_all();
}

}


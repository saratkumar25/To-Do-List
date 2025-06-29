#include "Task.h"

Task::Task(std::string t, int p) {
    title = t;
    priority = p;
    isCompleted = false;
    next = nullptr;
}
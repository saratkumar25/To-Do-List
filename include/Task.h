#ifndef TASK_H
#define TASK_H
#include <string>

struct Task {
    std::string title;
    int priority; // 1-High, 2-Medium, 3-Low
    bool isCompleted;
    Task* next;

    Task(std::string t, int p);
};

#endif
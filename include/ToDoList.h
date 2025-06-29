#ifndef TODOLIST_H
#define TODOLIST_H
#include "Task.h"
#include <string>

class ToDoList {
private:
    Task* head;
    Task* mergeSort(Task* head);
    Task* merge(Task* a, Task* b);

public:
    ToDoList();
    ~ToDoList();
    void addTask(std::string title, int priority);
    void deleteTask(std::string title);
    void markComplete(std::string title);
    void searchTask(std::string title);
    void displayTasks(bool sorted = false);
    void sortByPriority();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

#endif
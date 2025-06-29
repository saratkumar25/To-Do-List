#include "ToDoList.h"
#include <iostream>
#include <fstream>
using namespace std;

ToDoList::ToDoList() : head(nullptr) {}

ToDoList::~ToDoList() {
    while (head) {
        Task* temp = head;
        head = head->next;
        delete temp;
    }
}

void ToDoList::addTask(string title, int priority) {
    Task* newTask = new Task(title, priority);
    if (!head) {
        head = newTask;
        return;
    }
    Task* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newTask;
}

void ToDoList::deleteTask(string title) {
    Task* temp = head, *prev = nullptr;
    while (temp && temp->title != title) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Task not found.\n";
        return;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    delete temp;
}

void ToDoList::markComplete(string title) {
    Task* temp = head;
    while (temp) {
        if (temp->title == title) {
            temp->isCompleted = true;
            cout << "Marked as completed.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found.\n";
}

void ToDoList::searchTask(string title) {
    Task* temp = head;
    while (temp) {
        if (temp->title == title) {
            cout << "Found Task: " << temp->title << ", Priority: " << temp->priority
                 << ", Status: " << (temp->isCompleted ? "Done" : "Pending") << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found.\n";
}

Task* ToDoList::merge(Task* a, Task* b) {
    if (!a) return b;
    if (!b) return a;
    Task* result;
    if (a->priority < b->priority) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

Task* ToDoList::mergeSort(Task* head) {
    if (!head || !head->next) return head;
    Task* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Task* mid = slow->next;
    slow->next = nullptr;
    return merge(mergeSort(head), mergeSort(mid));
}

void ToDoList::sortByPriority() {
    head = mergeSort(head);
}

void ToDoList::displayTasks(bool sorted) {
    if (sorted) sortByPriority();
    Task* temp = head;
    while (temp) {
        cout << "Title: " << temp->title << " | Priority: " << temp->priority
             << " | Status: " << (temp->isCompleted ? "Done" : "Pending") << endl;
        temp = temp->next;
    }
}

void ToDoList::saveToFile(const string& filename) {
    ofstream file(filename);
    Task* temp = head;
    while (temp) {
        file << temp->title << "," << temp->priority << "," << temp->isCompleted << endl;
        temp = temp->next;
    }
    file.close();
}

void ToDoList::loadFromFile(const string& filename) {
    ifstream file(filename);
    string title;
    int priority;
    bool completed;
    while (getline(file, title, ',')) {
        file >> priority;
        file.ignore();
        file >> completed;
        file.ignore();
        Task* newTask = new Task(title, priority);
        newTask->isCompleted = completed;
        addTask(newTask->title, newTask->priority);
        if (newTask->isCompleted)
            markComplete(newTask->title);
    }
    file.close();
}
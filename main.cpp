#include "ToDoList.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n--- To-Do List Menu ---\n";
    cout << "1. Add Task\n";
    cout << "2. Delete Task\n";
    cout << "3. Mark Task Complete\n";
    cout << "4. Display All Tasks\n";
    cout << "5. Search Task\n";
    cout << "6. Display Sorted Tasks\n";
    cout << "7. Save and Exit\n";
    cout << "Enter choice: ";
}

int main() {
    ToDoList todo;
    todo.loadFromFile("tasks.txt");
    int choice, priority;
    string title;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter task title: ";
                getline(cin, title);
                cout << "Enter priority (1-High, 2-Medium, 3-Low): ";
                cin >> priority;
                todo.addTask(title, priority);
                break;
            case 2:
                cout << "Enter title to delete: ";
                getline(cin, title);
                todo.deleteTask(title);
                break;
            case 3:
                cout << "Enter title to mark complete: ";
                getline(cin, title);
                todo.markComplete(title);
                break;
            case 4:
                todo.displayTasks();
                break;
            case 5:
                cout << "Enter title to search: ";
                getline(cin, title);
                todo.searchTask(title);
                break;
            case 6:
                todo.displayTasks(true);
                break;
        }
    } while (choice != 7);

    todo.saveToFile("tasks.txt");
    cout << "Tasks saved. Goodbye!\n";
    return 0;
}
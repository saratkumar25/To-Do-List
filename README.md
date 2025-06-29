// README.md
#  To-Do List Application (C++)

A beginner-friendly C++ project to manage a personal to-do list using linked lists and basic file handling. This application features CRUD operations, sorting by priority, task searching, and persistent storage.

##  Features
- Add, delete, and complete tasks
- Sort tasks by priority (High > Medium > Low)
- Search for tasks by title
- Save and load tasks using a file (`tasks.txt`)
- Menu-driven user interface

##  Project Structure
```bash
ToDoListProject/
│
├──include
      ├── Task.h          # Task struct definition
      ├── Task.cpp        # Task constructor
├──src
      ├── ToDoList.h      # To-do list class declarations
      ├── ToDoList.cpp    # Function implementations
├── main.cpp        # Main menu interface
├── tasks.txt       # Saved task data (generated at runtime)
└── README.md       # Project documentation
```

##  How to Compile
Using g++:
```bash
g++ main.cpp Task.cpp ToDoList.cpp -o ToDoListApp
```

##  How to Run
```bash
./ToDoListApp     # On Unix
ToDoListApp.exe   # On Windows
```

##  File Persistence
- Tasks are automatically loaded from `tasks.txt` when the program starts.
- Tasks are saved to the same file when the user exits (choice 7).

##  Concepts Covered
- Linked List (Singly Linked List)
- Sorting using Merge Sort
- Linear Search
- File I/O (fstream)
- Basic time complexity awareness
- Clean class/module design

##  Sample Usage
```
--- To-Do List Menu ---
1. Add Task
2. Delete Task
3. Mark Task Complete
4. Display All Tasks
5. Search Task
6. Display Sorted Tasks
7. Save and Exit
```

##  Author
Built with ❤️ for DSA practice and beginner C++ learners.

---
Feel free to extend this project by adding:
- Due dates
- Priority queues
- GUI using Qt or SFML
- STL containers (e.g., `std::list` or `std::vector`)

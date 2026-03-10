// README.md
#  To-Do List Application (C++)


##  Project Structure
```bash
To_Do_List/
├── include/
│   ├── Task.h
│   └── ToDoList.h
├── src/
│   ├── Task.cpp
│   ├── ToDoList.cpp
├── main.cpp
├── tasks.txt       # Saved task data (generated at runtime)
└── README.md       # Project documentation
```

##  To Run

```bash
g++ main.cpp src/*.cpp -Iinclude -o ToDoListApp
.\ToDoListApp
```
# Multi-user Task Planner

A Qt/C++ desktop application for managing tasks with multiple users.\
Built to demonstrate **singly linked list operations** (insert, delete,
search, sort) in a real-world GUI project.

------------------------------------------------------------------------

## Features

-   🔐 User registration & login\
-   📝 Task creation, editing, deletion\
-   📌 Sorted tasks (by ID, priority, or due date)\
-   🔍 Search by ID or title\
-   💾 File-based save/load system\
-   🎨 Qt GUI with dashboard & task widgets

------------------------------------------------------------------------

## Data Structures

-   **User list**: singly linked list of users\
-   **Task list**: per-user singly linked list of tasks

``` cpp
class Task {
    int taskID;
    string title, description, dueDate, priority, status;
    Task* next;
};
```

------------------------------------------------------------------------

## Build & Run

### With Qt Creator

1.  Open project `.pro` (or `CMakeLists.txt`) in Qt Creator\
2.  Build → Run

### Command line (qmake)

``` bash
qmake Project.pro
make
./MultiUserTaskPlanner
```

------------------------------------------------------------------------

## File Format Example

    #USER
    1,masrafi,password123
    #TASKS
    101,Task Title,Task Description,2023-12-31,High,Completed
    #ENDTASKS

------------------------------------------------------------------------

## Contributors

-   Masrafi Siam --- 2411380042\
-   Sanjida Sultana --- 2232734642

CSE225 Project · North South University · Submitted 03/09/2025

------------------------------------------------------------------------

## License

MIT License © 2025 Group 08

# Multi-user Task Planner

A full-featured Qt/C++ desktop application designed as a **multi-user
task management system**, built to showcase practical applications of
**singly linked lists** for storing users and their tasks.\
This project was developed as part of the **CSE225 course** at North
South University.

------------------------------------------------------------------------

## 📖 Overview

The Task Planner allows multiple users to register, log in, and manage
their personal task lists.\
Each user has their own **linked list of tasks**, which supports
insertion, deletion, editing, sorting, and searching.\
The system persists all data to a structured text file for future
sessions.

The project highlights **data structure design** (linked lists),
**algorithm implementation** (sorting, searching, ID recycling), and
**GUI development** (Qt framework).

------------------------------------------------------------------------

## ✨ Key Features

-   **User Management**
    -   Register and login functionality
    -   Each user has an independent task list\
-   **Task Management**
    -   Create, edit, delete, update task status
    -   Automatic task ID assignment with ID recycling for deleted tasks
    -   Search by ID or title
-   **Sorting**
    -   Tasks sorted automatically by ID on insertion
    -   Additional sorting options by priority and due date
-   **Persistence**
    -   Save/load users and tasks in a custom structured file format
-   **GUI (Qt Framework)**
    -   Login & registration forms
    -   User dashboard with task display
    -   Task creation dialog
    -   Custom task widgets with status-aware colors/styles

------------------------------------------------------------------------

## 🛠️ Data Structures

### User Node

``` cpp
class User {
public:
    int userID;
    string username;
    string password;
    TaskList tasks;   // singly linked list of tasks
    User* next;
};
```

### Task Node

``` cpp
class Task {
public:
    int taskID;
    string title;
    string description;
    string dueDate;   // yyyy-mm-dd format
    string priority;  // High | Medium | Low
    string status;    // Pending | In Progress | Completed
    Task* next;
};
```

### Why Linked Lists?

-   Efficient insertion and deletion without shifting elements\
-   Simplifies implementing **sorted insertion**\
-   Demonstrates practical use of **singly linked list traversal**

------------------------------------------------------------------------

## ⚙️ Core Functionality

-   `addSorted(Task* newTask)` → Insert a task in ascending order of ID\
-   `deleteTaskByID(int id)` → Remove a task and recycle its ID\
-   `findTaskByID(int id)` → Linear search with early exit on sorted
    list\
-   `sortByPriority()` → Reorders tasks based on High \> Medium \> Low\
-   `sortByDueDate()` → Orders tasks chronologically\
-   `registerUser(...) / loginUser(...)` → Manage users\
-   `saveToFile() / loadFromFile()` → Persist and restore application
    state

------------------------------------------------------------------------

## 💾 File Format Example

    #USER
    1,masrafi,password123
    #TASKS
    101,Project Report,Finish documentation,2025-09-06,High,Completed
    102,Code Review,Fix sorting bug,2025-09-10,Medium,Pending
    #ENDTASKS
    #NEXTID
    2,103
    #AVAILABLE_IDS
    100,99,98

-   `#USER` --- user definition (id, username, password)\
-   `#TASKS ... #ENDTASKS` --- per-user tasks\
-   `#NEXTID` --- counters for next user ID and next task ID\
-   `#AVAILABLE_IDS` --- queue of recycled task IDs

------------------------------------------------------------------------

## 🖥️ GUI Components

-   **Login Form** → username/password entry\
-   **Registration Form** → new user creation\
-   **Dashboard** → shows task list with search & sort options\
-   **Task Widget** → displays task details with status-based coloring\
-   **Task Creation Dialog** → form to enter new task details

------------------------------------------------------------------------

## 🚀 Build & Run

### Requirements

-   Qt 5/6 (Qt Creator recommended)
-   C++17 or newer compiler

### With Qt Creator

1.  Open `.pro` or `CMakeLists.txt` in Qt Creator\
2.  Configure and build\
3.  Run the app

### Command Line (qmake)

``` bash
qmake Project.pro
make
./MultiUserTaskPlanner
```

### Command Line (CMake)

``` bash
mkdir build && cd build
cmake ..
cmake --build .
./MultiUserTaskPlanner
```

------------------------------------------------------------------------

## 🧪 Testing & Evaluation

-   **Unit Tests**
    -   Task insertion, deletion, search, and sorting
-   **Integration Tests**
    -   User registration/login → task management → file save/load cycle
-   **User Acceptance**
    -   Verified usability of the GUI workflow

### Known Limitations

-   **Binary search** is ineffective on linked lists due to lack of
    random access --- replaced with linear search with early
    termination.\
-   File parsing requires strict formatting (e.g., correct markers like
    `#USER`, `#TASKS`).

------------------------------------------------------------------------

## 🔮 Future Improvements

-   Replace text file storage with an SQL database\
-   Add collaboration features (shared tasks, groups)\
-   Implement reminders/notifications\
-   Mobile app support with Qt Quick/QML\
-   Advanced full-text search

------------------------------------------------------------------------

## 👩‍💻 Contributors

-   Masrafi Siam --- 2411380042
-   Sanjida Sultana --- 2232734642

**Course:** CSE225 --- Department of Electrical & Computer Engineering,
North South University\
**Submission Date:** 03/09/2025

------------------------------------------------------------------------

## 📜 License

    MIT License
    Copyright (c) 2025 Group 08

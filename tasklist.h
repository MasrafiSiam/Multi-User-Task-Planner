#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"


class TaskList {
private:
    Task* head;
    int count;

public:
    TaskList();
    ~TaskList();


    void addSorted(Task* newTask);
    bool deleteTaskByID(int id);
    bool editTaskByID(int id);
    bool updateTaskStatus(int id, const string& newStatus);


    Task* findTaskByID(int id);
    Task* searchByTitle(const string& title);


    void sortByDueDate();
    void sortByPriority();

    void displayTasks();
    Task* getHead();
};

#endif

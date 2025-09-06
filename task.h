#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;


class Task {
public:
    int taskID;
    string title;
    string description;
    string dueDate;
    string priority;
    string status;
    Task* next;

    Task(int id, const string& t, const string& d, const string& date, const string& p);
};

#endif

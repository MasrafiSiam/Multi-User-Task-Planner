#include "Task.h"

Task::Task(int id, const string& t, const string& d, const string& date, const string& p) {
    taskID = id;
    title = t;
    description = d;
    dueDate = date;
    priority = p;
    status = "Pending";
    next = nullptr;
}

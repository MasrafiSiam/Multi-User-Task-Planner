#include "TaskList.h"
#include <iostream>
using namespace std;

TaskList::TaskList() : head(nullptr), count(0) {}

TaskList::~TaskList() {
    Task* current = head;
    while (current) {
        Task* temp = current;
        current = current->next;
        delete temp;
    }
}

Task* TaskList::getHead() {
    return head;
}

Task* TaskList::findTaskByID(int id) {
    Task* current = head;
    while (current) {
        if (current->taskID == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void TaskList::addSorted(Task* newTask) {
    // Insert task in sorted order by ID (ascending)
    if (!head || newTask->taskID < head->taskID) {
        newTask->next = head;
        head = newTask;
    } else {
        Task* current = head;
        while (current->next && current->next->taskID < newTask->taskID) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
    count++;
}

bool TaskList::deleteTaskByID(int id) {
    if (!head) return false;
    if (head->taskID == id) {
        Task* toDelete = head;
        head = head->next;
        delete toDelete;
        count--;
        return true;
    }
    Task* prev = head;
    Task* curr = head->next;
    while (curr) {
        if (curr->taskID == id) {
            prev->next = curr->next;
            delete curr;
            count--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

bool TaskList::editTaskByID(int id) {
    Task* task = findTaskByID(id);
    if (!task) return false;

    cin.ignore();
    cout << "New Title: "; getline(cin, task->title);
    cout << "New Description: "; getline(cin, task->description);
    cout << "New Due Date: "; getline(cin, task->dueDate);
    cout << "New Priority: "; getline(cin, task->priority);
    return true;
}

bool TaskList::updateTaskStatus(int id, const string& newStatus) {
    Task* task = findTaskByID(id);
    if (!task) return false;

    // Validate the status
    if (newStatus == "Pending" || newStatus == "In Progress" || newStatus == "Completed") {
        task->status = newStatus;
        return true;
    }
    return false;
}

Task* TaskList::searchByTitle(const string& title) {
    Task* temp = head;
    while (temp) {
        if (temp->title == title) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void TaskList::displayTasks() {
    Task* temp = head;
    if (!temp) {
        cout << "No tasks found.\n";
        return;
    }
    while (temp) {
        cout << "ID: " << temp->taskID
             << " | Title: " << temp->title
             << " | Due: " << temp->dueDate
             << " | Priority: " << temp->priority
             << " | Status: " << temp->status << endl;
        temp = temp->next;
    }
}

int priorityValue(const string& p) {
    // Convert priority string to numerical value for sorting
    if (p == "High") return 1;
    if (p == "Medium") return 2;
    return 3; // Low priority
}

void TaskList::sortByDueDate() {
    if (!head || !head->next) return;
    Task* sorted = nullptr;

    while (head) {
        Task* current = head;
        head = head->next;
        if (!sorted || current->dueDate < sorted->dueDate) {
            current->next = sorted;
            sorted = current;
        } else {
            Task* temp = sorted;
            while (temp->next && temp->next->dueDate < current->dueDate)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}

void TaskList::sortByPriority() {
    if (!head || !head->next) return;
    Task* sorted = nullptr;

    while (head) {
        Task* current = head;
        head = head->next;
        // Compare priority values instead of strings
        if (!sorted || priorityValue(current->priority) < priorityValue(sorted->priority)) {
            current->next = sorted;
            sorted = current;
        } else {
            Task* temp = sorted;
            while (temp->next && priorityValue(temp->next->priority) < priorityValue(current->priority))
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}

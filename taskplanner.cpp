#include "TaskPlanner.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

TaskPlanner::TaskPlanner() {
    userHead = nullptr;
    nextUserID = 1;
    nextTaskID = 1;
    loadFromFile("data.txt");
}

TaskPlanner::~TaskPlanner() {
    saveToFile("data.txt");
    User* current = userHead;
    while (current) {
        User* temp = current;
        current = current->next;
        delete temp;
    }
}

int TaskPlanner::allocateTaskID() {
    // Recycle IDs first to prevent gaps in numbering
    if (!availableTaskIDs.empty()) {
        int recycledID = availableTaskIDs.front();
        availableTaskIDs.pop();
        return recycledID;
    }
    return nextTaskID++; // Auto-increment if no recycled IDs available
}

int TaskPlanner::getNextAvailableTaskID() const {
    // Return next available ID without actually allocating it
    if (!availableTaskIDs.empty()) {
        return availableTaskIDs.front(); // Next recycled ID
    }
    return nextTaskID; // Next auto-increment ID
}

void TaskPlanner::recycleTaskID(int id) {
    availableTaskIDs.push(id);
}

bool TaskPlanner::registerUser(string username, string password) {
    User* temp = userHead;
    while (temp) {
        if (temp->username == username) {
            return false; // Username already exists
        }
        temp = temp->next;
    }

    User* newUser = new User(nextUserID++, username, password);
    newUser->next = userHead;
    userHead = newUser;

    saveToFile("data.txt");
    return true;
}

User* TaskPlanner::loginUser(string username, string password) {
    User* temp = userHead;
    while (temp) {
        if (temp->username == username && temp->password == password) {
            return temp; // Successful login
        }
        temp = temp->next;
    }
    return nullptr; // Login failed
}

void TaskPlanner::saveToFile(const string& filename) {
    ofstream fout(filename);
    if (!fout) return;

    User* u = userHead;
    while (u) {
        fout << "#USER\n";
        fout << u->userID << "," << u->username << "," << u->password << "\n";

        fout << "#TASKS\n";
        Task* t = u->tasks.getHead();
        while (t) {
            // Save task data in CSV format
            fout << t->taskID << "," << t->title << "," << t->description << ","
                 << t->dueDate << "," << t->priority << "," << t->status << "\n";
            t = t->next;
        }
        fout << "#ENDTASKS\n";
        u = u->next;
    }

    fout << "#NEXTID\n";
    fout << nextUserID << "," << nextTaskID << "\n";

    fout << "#AVAILABLE_IDS\n";
    queue<int> temp = availableTaskIDs;
    while (!temp.empty()) {
        fout << temp.front() << ",";
        temp.pop();
    }
    fout << "\n";
    fout.close();
}

void TaskPlanner::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) return;

    string line;
    User* currentUser = nullptr;
    bool readingTasks = false;

    while (getline(fin, line)) {
        if (line == "#USER") {
            getline(fin, line);
            // Parse user data from CSV
            size_t p1 = line.find(','), p2 = line.find(',', p1 + 1);
            int id = stoi(line.substr(0, p1));
            string uname = line.substr(p1 + 1, p2 - p1 - 1);
            string pass = line.substr(p2 + 1);

            User* newUser = new User(id, uname, pass);
            newUser->next = userHead;
            userHead = newUser;
            currentUser = newUser;
            if (id >= nextUserID) nextUserID = id + 1;

        } else if (line == "#TASKS") {
            readingTasks = true;
        } else if (line == "#ENDTASKS") {
            readingTasks = false;
        } else if (line == "#NEXTID") {
            getline(fin, line);
            // Load next available IDs
            size_t p1 = line.find(',');
            nextUserID = stoi(line.substr(0, p1));
            nextTaskID = stoi(line.substr(p1 + 1));
        } else if (line == "#AVAILABLE_IDS") {
            getline(fin, line);
            // Load recycled task IDs
            size_t pos = 0;
            string token;
            while ((pos = line.find(',')) != string::npos) {
                token = line.substr(0, pos);
                if (!token.empty()) {
                    availableTaskIDs.push(stoi(token));
                }
                line.erase(0, pos + 1);
            }
        } else if (readingTasks && currentUser && !line.empty()) {
            // Parse task data from CSV
            size_t p1 = line.find(','),
                p2 = line.find(',', p1 + 1),
                p3 = line.find(',', p2 + 1),
                p4 = line.find(',', p3 + 1),
                p5 = line.find(',', p4 + 1);

            int tid = stoi(line.substr(0, p1));
            string title = line.substr(p1 + 1, p2 - p1 - 1);
            string desc = line.substr(p2 + 1, p3 - p2 - 1);
            string date = line.substr(p3 + 1, p4 - p3 - 1);
            string prio = line.substr(p4 + 1, p5 - p4 - 1);
            string status = line.substr(p5 + 1);

            Task* newTask = new Task(tid, title, desc, date, prio);
            newTask->status = status;
            currentUser->tasks.addSorted(newTask);
            if (tid >= nextTaskID) nextTaskID = tid + 1;
        }
    }
    fin.close();
}

User* TaskPlanner::GetUserHead() {
    return userHead;
}

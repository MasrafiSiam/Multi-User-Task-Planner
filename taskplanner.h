#ifndef TASKPLANNER_H
#define TASKPLANNER_H

#include "User.h"
#include <string>
#include <queue>
using namespace std;


class TaskPlanner {
private:
    User* userHead;
    int nextUserID;
    int nextTaskID;
    queue<int> availableTaskIDs;

public:
    TaskPlanner();
    ~TaskPlanner();


    bool registerUser(string, string);
    User* loginUser(string, string);


    int allocateTaskID();
    void recycleTaskID(int id);


    int getNextAvailableTaskID() const;


    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);

    User* GetUserHead();
};

#endif

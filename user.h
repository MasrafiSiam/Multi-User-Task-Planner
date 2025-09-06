#ifndef USER_H
#define USER_H

#include <string>
#include "TaskList.h"
using namespace std;


class User {
public:
    int userID;
    string username;
    string password;
    TaskList tasks;
    User* next;

    User(int id, const string& uname, const string& pass);
    ~User();
};

#endif

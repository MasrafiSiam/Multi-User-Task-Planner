#include "User.h"

User::User(int id, const string& uname, const string& pass)
    : userID(id), username(uname), password(pass), next(nullptr) {}

User::~User() {

}

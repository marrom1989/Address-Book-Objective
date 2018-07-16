#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "User.h"

using namespace std;

class UsersFile {

string nameOfFileWithUsers;

public:
    UsersFile();
    virtual ~UsersFile();
    void loadUsersFromTextFile(vector<User>&users);
    void saveAllUsersIntoFile(vector<User>&users);
    void addUserToFile(User user);

};
#endif

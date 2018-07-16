#ifndef USER_H
#define USER_H

#include <iostream>
#include <windows.h>

using namespace std;

class User {

int idOfUser;
string nick;
string password;
friend class UsersFile;
friend class Recipent;

public:
    User();
    virtual ~User();

    int getIdOfUser();
    string getNick();
    string getPassword();

    void setIdOfUser(int idOfUser);
    void setNick(string nick);
    void setPassword(string password);

};
#endif

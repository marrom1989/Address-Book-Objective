#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "User.h"
#include "UsersFile.h"



using namespace std;

class Users {

    vector<User> users;
    int idLoggedUser;
    UsersFile usersFile;
    friend class AddressBook;
    friend class Recipent;


public:
    Users();
    virtual ~Users();

    void registration();
    void changePassword();
    void singIn();
    void logOut();
    int takeIdLoggedUser();


private:

    User enterTheDetailsOfTheNewUser();
    int takeIdNewUser();
    string checkThatUserExist(string nick, vector<User> users);
    bool doesUserExist(string nick);

};
#endif

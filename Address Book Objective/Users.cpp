#include <iostream>
#include <vector>
#include <windows.h>
#include "Users.h"
#include <fstream>

using namespace std;

Users::Users() {

    this->idLoggedUser = 0;
    usersFile.loadUsersFromTextFile(users);
}

Users::~Users() {


    users.clear();

}

void Users::registration() {

    User user = enterTheDetailsOfTheNewUser();
    users.push_back(user);
    usersFile.addUserToFile(user);

}

bool Users::doesUserExist(string nick) {
    vector <User>::iterator itr = users.begin();

    while (itr != users.end()) {
        if (itr->User::getNick() == nick) {
            cout << endl << "That user exist!!" << endl;
            return true;
        } else {
            itr++;
        }
    }

    return false;
}


void Users::singIn() {

    string nick, password;
    int attempt = 3;
    bool doesUserExist = false;

    cout << "Please, enter your username: ";
    cin >> nick;

    for(vector<User>::iterator itr = users.begin(), koniec = users.end(); itr != koniec; ++itr) {
        if(itr->User::getNick() == nick) {

            while(attempt > 0) {
                cout << "Left attempts: " << attempt << " Enter password: ";
                cin >> password;

                if(itr->User::getPassword() == password) {

                    cout << "You logged in !!" << endl;
                    Sleep(1000);
                    this->idLoggedUser = itr->User::getIdOfUser();
                    doesUserExist = true;
                    break;
                }
                attempt--;

                if(attempt == 0) {
                    cout << "Three times you wrote wrong password. Wait 3 seconds and try again !!" << endl;
                    Sleep(3000);
                    this->idLoggedUser = 0;
                    break;
                }
            }
        }
    }
    if(doesUserExist = false) {
        cout << "There is no user with that login !!" << endl;
        Sleep(1500);
    }
}

void Users::changePassword() {

    if(idLoggedUser > 0) {

        string password = "";
        cout << "Enter new password: ";
        cin >> password;

       for(vector<User>::iterator itr = users.begin(), koniec = users.end(); itr != koniec; ++itr) {

            if(itr->User::getIdOfUser() == idLoggedUser) {

                itr->User::setPassword(password);
                cout << "Password has been changed !!" << endl;
                Sleep(1500);
            }
            usersFile.saveAllUsersIntoFile(users);
        }
    } else {

        cout << "Wrond id number. Log in if you want to change password !!" <<endl;
    }
}

User Users::enterTheDetailsOfTheNewUser() {

    User user;
    string nick = "";
    string password = "";

    user.setIdOfUser(takeIdNewUser());

    do {

        cout << endl << "Enter username: ";
        cin >> nick;
        cin.ignore();
        user.setNick(nick);
    } while(doesUserExist(user.getNick()) == true);

    cout << endl << "Password minimum 3 sign !!" << endl << endl;
    do {

        cout << "Enter password: ";
        cin >> password;
        cin.ignore();

    } while(password.length() < 3);

    user.setPassword(password);

    return user;

}

int Users::takeIdNewUser() {

    if(users.size() == 0) {

        return 1;
    } else {

        return users.back().getIdOfUser() + 1;

    }

}

int Users::takeIdLoggedUser() {

    return idLoggedUser;
}

void Users::logOut() {
    this->idLoggedUser = 0;
}






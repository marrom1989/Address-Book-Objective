
#include "User.h"

using namespace std;

User::User() {

    idOfUser = 0;
    nick = "";
    password = "";
}
User::~User() {;}

int User::getIdOfUser() {

return idOfUser;
}

string User::getNick() {

return nick;
}

string User::getPassword() {

return password;
}

void User::setIdOfUser(int idOfUser) {

this->idOfUser = idOfUser;

}

void User::setNick(string nick) {

this->nick = nick;
}

void User::setPassword(string password) {

this->password = password;
}



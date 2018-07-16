#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <vector>
#include <conio.h>
#include "Recipent.h"
#include "Users.h"
#include "RecipentFile.h"
#include "Menu.h"

using namespace std;

class AddressBook {

    vector<Recipent> recipents;
    int loggedInUserId;
    FileRecipents recipentFile;
    char id;
    int personalId;
    Users users;
    Menu menu;
    friend class Users;

public:
    AddressBook(int loggedInUserId);
    virtual ~AddressBook();

    void addRecipent();
    void searchByName();
    void searchBySurname();
    void writeAllYourFriends();
    void deleteRecipent();
    void editRecipent();
    int getIdLoggedUser();




private:
    Recipent addTheDetailsOfTheNewUser();
    int takeIdOfNewFriend();
    char idUserWhichWantsToDeleteFriend();
    char takeIdOfRecipent(int personalId);

};
#endif

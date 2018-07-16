#ifndef RECIPENT_H
#define RECIPENT_H

#include <iostream>
#include "Users.h"

using namespace std;

class Recipent {

int individualNumberOfEachFriend;
int userId;
string name;
string surname;
string phoneNumber;
string email;
string address;

friend class FileRecipents;
friend class AddressBook;

public:
    Recipent();
   virtual ~Recipent();

   int getIndividualNumberOfEachFriend();
   int getUserId();
   string getName();
   string getSurname();
   string getPhoneNumber();
   string getEmail();
   string getAddress();

   void setIndividualNumberOfEachFriend(int individualNumberOfEachFriend);
   void setUserId(int userId);
   void setName(string name);
   void setSurname(string surname);
   void setPhoneNumber(string phoneNumber);
   void setEmail(string email);
   void setAddress(string address);

private:
    Users getTheIdLoggedUser();
};

#endif

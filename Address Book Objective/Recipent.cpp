#include "Recipent.h"

using namespace std;

Recipent::Recipent() {

    individualNumberOfEachFriend = 0;
    userId = 0;
    name = "";
    surname = "";
    phoneNumber = "";
    email = "";
    address = "";
}

Recipent::~Recipent() {;}

int Recipent::getIndividualNumberOfEachFriend() {

    return individualNumberOfEachFriend;
}

int Recipent::getUserId() {

    return userId;
}

string Recipent::getName() {

    return name;
}

string Recipent::getSurname() {

    return surname;
}

string Recipent::getPhoneNumber() {

    return phoneNumber;
}

string Recipent::getEmail() {

    return email;
}

string Recipent::getAddress() {

    return address;
}

void Recipent::setIndividualNumberOfEachFriend(int individualNumberOfEachFriend) {

    this->individualNumberOfEachFriend = individualNumberOfEachFriend;
}

void Recipent::setUserId(int userId) {

    this->userId = userId;
}

void Recipent::setName(string name) {

    this->name = name;
}

void Recipent::setSurname(string surname) {

    this->surname = surname;
}

void Recipent::setPhoneNumber(string phoneNumber) {

    this->phoneNumber = phoneNumber;
}

void Recipent::setEmail(string email) {

    this->email = email;
}

void Recipent::setAddress(string address) {

    this->address = address;
}

Users Recipent::getTheIdLoggedUser(){

Users users;

users.takeIdLoggedUser();

return users;

}

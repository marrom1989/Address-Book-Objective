#include "UsersFile.h"


using namespace std;

UsersFile::UsersFile() {

    this->nameOfFileWithUsers = "Users.txt";
}

UsersFile::~UsersFile(){;}

void UsersFile::addUserToFile(User user) {

    fstream file;
    file.open(nameOfFileWithUsers.c_str(), ios::out | ios::app);
    if(file.good()) {

        file << user.idOfUser << "|";
        file << user.nick << "|";
        file << user.password << "|" << endl;
        file.close();

        cout << "User has been added." << endl;
        Sleep(1000);
    } else {
        cout << "Unable to open Users.txt file !!" << endl;
    }

}

void UsersFile::saveAllUsersIntoFile(vector<User>&users) {

    fstream file;
    file.open(nameOfFileWithUsers.c_str(), ios::out);
    if(!file.good()) {
        cout << "Unable to open Users.txt file !!" << endl;
    } else {

        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            file<<itr -> idOfUser<<"|";
            file<<itr -> nick<<"|";
            file<<itr -> password<<"|"<<endl;
        }
        file.close();
    }
}

void UsersFile::loadUsersFromTextFile(vector<User>&users) {

    ifstream file;
    User valueOfStruct;
    string line;
    int numberOfLine = 1;
    int numberOfFriends = 0;

    file.open(nameOfFileWithUsers.c_str(), ios::in);

    if(!file.good()) {

        cout << "File doesn't exist!" << endl;
    }

    while(getline(file, line,'|')) {
        switch(numberOfLine) {
        case 1:
            valueOfStruct.idOfUser = atoi(line.c_str());
            break;
        case 2:
            valueOfStruct.nick = line;
            break;
        case 3:
            valueOfStruct.password = line;
            break;
        }
        if (numberOfLine == 3) {
            users.push_back(valueOfStruct);
            numberOfLine = 0;
            numberOfFriends++;
        }
        numberOfLine++;
    }
    file.close();
}

#include "RecipentFile.h"


using namespace std;

FileRecipents::FileRecipents() {

    this->nameOfFileWithRecipents = "AddressBook.txt";
    this->nameOfTemporaryFileWithRecipents = "TemporaryAddresBook.txt";
    char userId = '0';
}

FileRecipents::~FileRecipents() {;}

char FileRecipents::convertIntToChar(int loggedInUserId) {

    char sign;
    const int modulo = 10;
    const int numberOfZero = 48;

    sign = (loggedInUserId%modulo) + numberOfZero;

    return sign;

}

void FileRecipents::loadRecipentsFromTextFile(vector<Recipent>&recipents, int loggedInUserId) {

    ifstream file;
    Recipent valueOfStruct;
    string line = "";
    int numberOfLine = 1;
    string singleData = "";
    char sign;

    sign = convertIntToChar(loggedInUserId);


    file.open(nameOfFileWithRecipents.c_str());

    if(!file.good()) {
        cout << "File doesn't exist!" <<endl;
    }
    while(getline(file, line)) {

        if(line[2] == sign) {

            for(int i = 0; i < line.length(); i++) {
                if (line[i] != '|') {
                    singleData += line[i];
                } else {
                    switch(numberOfLine) {
                    case 1:
                        valueOfStruct.individualNumberOfEachFriend = atoi(singleData.c_str());
                        break;
                    case 2:
                        valueOfStruct.userId = atoi(singleData.c_str());;
                        break;
                    case 3:
                        valueOfStruct.name = singleData;
                        break;
                    case 4:
                        valueOfStruct.surname = singleData;
                        break;
                    case 5:
                        valueOfStruct.phoneNumber = singleData;
                        break;
                    case 6:
                        valueOfStruct.email = singleData;
                        break;
                    case 7:
                        valueOfStruct.address = singleData;
                        break;
                    }
                    singleData = "";
                    numberOfLine++;
                }
            }
            recipents.push_back(valueOfStruct);
            numberOfLine = 1;

        }
    }
}

void FileRecipents::addRecipentToFile(Recipent recipent) {

    fstream file;
    file.open(nameOfFileWithRecipents.c_str(), ios::out | ios::app);
    if(file.good()) {

        file << recipent.individualNumberOfEachFriend << "|";
        file << recipent.userId << "|";
        file << recipent.name << "|";
        file << recipent.surname << "|";
        file << recipent.phoneNumber << "|";
        file << recipent.email << "|";
        file << recipent.address << "|" << endl;
        file.close();

        cout << "User has been added." << endl;
        Sleep(1000);
    } else {
        cout << "Unable to open Users.txt file !!" << endl;
    }

}

void FileRecipents::overwriteRecentFile(char userId) {

    string line;
    ifstream file;
    ofstream temporary;
    file.open(nameOfFileWithRecipents.c_str(), ios::out | ios::app);
    temporary.open(nameOfTemporaryFileWithRecipents.c_str(), ios::out | ios::app);
    if(file.good() && temporary.good()) {

        while(getline(file, line)) {
            if(line[0] == userId) {
                continue;
            } else {

                temporary << line << endl;
            }
        }
    }
    file.close();
    temporary.close();
    remove(nameOfFileWithRecipents.c_str());
    rename(nameOfTemporaryFileWithRecipents.c_str(), nameOfFileWithRecipents.c_str());

}





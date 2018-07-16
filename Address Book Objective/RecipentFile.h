#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include "Recipent.h"
#include<windows.h>

#ifndef FILERECIPENTS_H
#define FILERECIPENTS_H


using namespace std;

class FileRecipents {

string nameOfFileWithRecipents;
string nameOfTemporaryFileWithRecipents;


public:
    FileRecipents();
    virtual ~FileRecipents();
    void addRecipentToFile(Recipent recipent);
    void loadRecipentsFromTextFile(vector<Recipent>&recipents, int loggedInUserId);
    void overwriteRecentFile(char userId);

private:
    char convertIntToChar(int loggedInUserId);
};
#endif

#include <iostream>
#include "Menu.h"
#include <windows.h>

using namespace std;

char Menu::selectOptionFromFirstMenu() {

    char choice;

    system("cls");
    cout << "1. Sing In" << endl;
    cout << "2. Registration" << endl;
    cout << "3. Change password" << endl;
    cout << "9. Exit" << endl;

    cin >> choice;
    return choice;
}

char Menu::selectOptionFromSecondMenu() {


    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add recipent" << endl;
    cout << "2. Search by name" << endl;
    cout << "3. Search by surname" << endl;
    cout << "4. Show all recipents" << endl;
    cout << "5. Delete recipent" << endl;
    cout << "6. Edit recipent" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    return choice;

}

char Menu::selectOptionFromThirdMenu() {


system("cls");
            cout << "1 - imie" <<endl;
            cout << "2 - nazwisko" <<endl;
            cout << "3 - numer telefonu" <<endl;
            cout << "4 - email" <<endl;
            cout << "5 - adres" <<endl;
            cout << "6 - Exit" <<endl;

            char number;

            cin >> number;
    return number;
}

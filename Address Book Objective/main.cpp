#include <iostream>
#include <vector>
#include <windows.h>
#include "Users.h"
#include "Menu.h"
#include "AddressBook.h"

using namespace std;

int main() {

    Users users;
    Menu basicMenu;
    char choice;

    while(1) {
        if (users.takeIdLoggedUser() == 0) {

            choice = basicMenu.selectOptionFromFirstMenu();

            switch(choice) {

            case '1': {
                users.singIn();
                break;
            }
            case '2': {
                users.registration();
                break;
            }
            case '3': {
                users.changePassword();
                break;
            }
            case '9': {
                exit(0);
                break;
            }
            default:
                cout << endl << "That option does't exist in menu" << endl;
                system("pause");
                break;

            }

        } else if (users.takeIdLoggedUser() > 0) {

do{
           AddressBook addressBook(users.takeIdLoggedUser());


                choice = basicMenu.selectOptionFromSecondMenu();

                switch (choice) {
                case '1':
                     addressBook.addRecipent();
                    break;
                case '2':
                    addressBook.searchByName();
                    break;
                case '3':
                    addressBook.searchBySurname();
                    break;
                case '4':
                    addressBook.writeAllYourFriends();
                    break;
                case '5':
                    addressBook.deleteRecipent();
                    break;
                case '6':
                    addressBook.editRecipent();
                    break;
                case '7':
                    users.changePassword();
                    break;
                case '8':
                    users.logOut();
                    break;
                }
            } while (choice != '8');

        }
    }

    return 0;
}

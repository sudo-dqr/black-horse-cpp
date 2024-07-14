#include <iostream>
#include <cstdlib>
#include "contact.h"

using namespace std;

int main() {
    int operation = 0;
    bool exit = false;
    struct AddressBook addressBook;
    addressBook.size = 0;
    while(true) {
        showMenu();
        cin >> operation;
        switch (operation) {
            case 0:
                cout << "Thank you for using the address book!" << endl;
                exit = true;
                break;
            case 1:
                addPerson(&addressBook);
                break;
            case 2:
                displayPerson(&addressBook);
                break;
            case 3:
                deletePerson(&addressBook);
                break;
            case 4:
                searchPerson(&addressBook);
                break;
            case 5:
                modifyPerson(&addressBook);
                break;
            case 6:
                clearPerson(&addressBook);
                break;                        
            default:
                cout << "Invalid operation! Please enter again: " << endl;
                break;
        }
        if (exit) {
            break;
        }
    }
    system("pause"); // 请按任意键继续
    system("cls"); // 清屏
    return 0;
}
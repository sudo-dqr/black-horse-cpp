#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 1000

struct Person {
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct AddressBook {
    Person personArray[MAX];
    int size; // 当前个数
};

void showMenu();
void addPerson(AddressBook *addressBook);
void displayPerson(AddressBook *addressBook);
void deletePerson(AddressBook *addressBook);
void searchPerson(AddressBook *addressBook);
void modifyPerson(AddressBook *addressBook);
void clearPerson(AddressBook *addressBook);

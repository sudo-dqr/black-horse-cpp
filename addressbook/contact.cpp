#include "contact.h"

void setName(Person *person) {
    string name;
    cout << "Please enter the name: " << endl;
    cin >> name;
    person->name = name;
}

void setSex(Person *person) {
    int sex;
    cout << "Please enter the sex: " << endl;
    cout << "1 -- male" << endl;
    cout << "2 -- female" << endl;
    while (true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            person->sex = sex;
            break;
        } else {
            cout << "Invalid input! Please enter again: " << endl;
        }
    }
}

void setAge(Person *person) {
    int age;
    cout << "Please enter the age: " << endl;
    cin >> age;
    person->age = age;
}

void setPhone(Person *person) {
    string phone;
    cout << "Please enter the phone number: " << endl;
    cin >> phone;
    person->phone = phone;
}

void setAddress(Person *person) {
    string address;
    cout << "Please enter the address: " << endl;
    cin >> address;
    person->address = address;
}

int isExist(AddressBook *addressBook, string name) {
    for (int i = 0; i < addressBook->size; i++) {
        if (addressBook->personArray[i].name == name) {
            return i;
        }
    }
    return -1;
}

void printPerson(Person *person) {
    cout << "Name: " << person->name << "\t";
    cout << "Sex: " << ((person->sex == 1) ? "male" : "female" ) << "\t";
    cout << "Age: " << person->age << "\t";
    cout << "Phone: " << person->phone << "\t";
    cout << "Address: " << person->address << endl;
}

void showMenu() {
    cout << "***** Welcome to the address book *****" << endl;
    cout << "***** 1. Add a new contact *****" << endl;
    cout << "***** 2. Display all contacts *****" << endl;
    cout << "***** 3. Delte a contact *****" << endl;
    cout << "***** 4. Search a contact *****" << endl;
    cout << "***** 5. Modify a contact *****" << endl;
    cout << "***** 6. Clear all contacts *****" << endl;
    cout << "***** 0. Exit *****" << endl;
    cout << "Please select the operation you want to perform: "<< endl;
}

void addPerson(AddressBook *addressBook) {
    if (addressBook->size == MAX) {
        cout << "The address book is full!" << endl;
        return;
    }
    Person *person = &(addressBook->personArray[addressBook->size]); // 这里出现了一个bug是要取地址
    setName(person);
    setSex(person);
    setAge(person);
    setPhone(person);
    setAddress(person);
    addressBook->size++;
    cout << "Contact added successfully!" << endl;
}    

void displayPerson(AddressBook *addressBook) {
    if (addressBook->size == 0) {
        cout << "The address book is empty!" << endl;
    } else {
        for (int i = 0; i < addressBook->size; i++) {
            printPerson(&addressBook->personArray[i]);
        }
    }
}

void deletePerson(AddressBook *addressBook) {
    string name;
    cout << "Please enter the name of the contact you want to delete: " << endl;
    cin >> name;
    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "The contact does not exist!" << endl;
    } else {
        for (int i = index; i < addressBook->size - 1; i++) {
            addressBook->personArray[i] = addressBook->personArray[i + 1];
        }
        addressBook->size--;
        cout << "Contact deleted successfully!" << endl;
    }
}

void searchPerson(AddressBook *addressBook) {
    string name;
    cout << "Please enter the name of the contact you want to search: " << endl;
    cin >> name;
    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "The contact does not exist!" << endl;
    } else {
        printPerson(&addressBook->personArray[index]);
    }
}

void modifyPerson(AddressBook *addressBook) {
    string name;
    cout << "Please enter the name of the contact you want to modify: " << endl;
    cin >> name;
    int index = isExist(addressBook, name);
    if (index == -1) {
        cout << "The contact does not exist!" << endl;
    } else {
        Person *person = &(addressBook->personArray[index]);
        setName(person);
        setSex(person);
        setAge(person);
        setPhone(person);
        setAddress(person);
        cout << "Contact modified successfully!" << endl;
    }
}

void clearPerson(AddressBook *addressBook) {
    cout << "Are you sure you want to clear all contacts? (Y/N)" << endl;
    char confirm;
    cin >> confirm;
    if (confirm != 'Y' && confirm != 'y') {
        cout << "Operation cancelled!" << endl;
        return;
    }
    addressBook->size = 0;
    cout << "All contacts cleared successfully!" << endl;
}

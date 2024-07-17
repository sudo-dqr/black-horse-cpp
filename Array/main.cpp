#include <iostream>
#include "Array.hpp"
using namespace std;

class Person {
    public :
        string name;
        int age;
        Person(string name = "", int age = 0) {
            this->name = name;
            this->age = age;
        }
};

void test01() {
    Array<int> array1(10);
    Array<int> array2(array1);
    Array<int> array3(100);
    array3 = array1;
}

void printArray(Array<int> & array) {
    for (int i = 0; i < array.getSize(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void test02() {
    Array<int> array(5);
    cout << "capacity: " << array.getCapacity() << endl;
    for (int i = 0; i < 5; i++) {
        array.insertTail(i);
    }
    cout << "array1: ";
    printArray(array);
    Array<int> array2(array);
    for (int i = 0; i < 5; i++) {
        array2.deleteTail();
    }
    cout << "array2: ";
    printArray(array2);
}

void test03() {
    Array<Person> array(5);
    array.insertTail(Person("Alice", 18));
    array.insertTail(Person("Bob", 19));
    array.insertTail(Person("Charlie", 20));
    array.insertTail(Person("David", 21));
    array.insertTail(Person("Eve", 22));
    cout << "array: " << endl;
    for (int i = 0; i < array.getSize(); i++) {
        cout << "name: " << array[i].name << " age: " << array[i].age << endl;
    }
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}
#pragma once
#include <iostream>
using namespace std;

template <class T>
class Array {
    private :
        T * pAddress;
        int capacity;
        int size;

    public :
        Array(int capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->pAddress = new T[this->capacity];
        }

        Array(const Array & arr) {
            this->capacity = arr.capacity;
            this->size = arr.size;
            this->pAddress = new T[this->capacity]; // deep clone
            for (int i = 0; i < this->size; i++) {
                this->pAddress[i] = arr.pAddress[i];
            }
        } 

        Array & operator=(const Array & arr) {
            if (this->pAddress != NULL) {
                delete[] this->pAddress;
                this->pAddress = NULL;
                this->capacity = 0;
                this->size = 0;
            }
            this->capacity = arr.capacity;
            this->size = arr.size;
            this->pAddress = new T[this->capacity]; // deep clone
            for (int i = 0; i < this->size; i++) {
                this->pAddress[i] = arr.pAddress[i];
            }
            return *this;
        }
        
        ~Array() {
            if (this->pAddress != NULL) {
                delete[] this->pAddress;
                this->pAddress = NULL;
            }
            delete [] this->pAddress;
            this->pAddress = NULL;
        }

        void insertTail(const T & t) {
            if (this->size == this->capacity) {
                return;
            }
            this->pAddress[this->size++] = t;
        }

        void deleteTail() {
            if (this->size == 0) {
                return;
            }
            this->size--;
        }

        // 下标访问 通过[]重载实现
        T & operator[](int index) {
            return this->pAddress[index];
        }

        int getSize() {
            return this->size;
        }

        int getCapacity() {
            return this->capacity;
        }
};

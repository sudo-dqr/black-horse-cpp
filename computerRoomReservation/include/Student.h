#pragma once
#include <iostream>
#include <vector>
#include "Identity.h"
#include "ComputerRoom.h"
#include "orderFile.h"
using namespace std;

class Student : public Identity {
    public :
        Student();
        Student(int id, string name, string pwd);
        void operate();
        void applyOrder();
        void showMyOrder();
        void showAllOrder();
        void cancelOrder();
        void initComputerRoom();
        int getId();
        string getName();
        string getPassword();

    private :
        int id;
        vector<ComputerRoom> computerRooms;
};
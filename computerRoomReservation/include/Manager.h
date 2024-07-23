#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "ComputerRoom.h"
using namespace std;

class Manager : public Identity {
    public :
        Manager();
        Manager(string name, string pwd);
        void operate();
        void addPerson();
        void showPerson();
        void showComputer();
        void cleanFile();
        string getName();
        void initVector();
        void initComputerRoom();
        bool checkRepeat(int id, int type);

    private :
        vector<Student> students;
        vector<Teacher> teachers; 
        vector<ComputerRoom> computerRooms;   
};
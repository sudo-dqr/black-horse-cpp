#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Employee : public Worker {
    public :
        Employee(int id, string name, int dId);
        void showInfo();
        string getDepartmentName();
};

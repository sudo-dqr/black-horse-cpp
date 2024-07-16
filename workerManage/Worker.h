#pragma once
#include <iostream>
using namespace std;

class Worker {
    public :
        int workerId;
        string workerName;
        int departmentId;

        virtual void showInfo() = 0;
        virtual string getDepartmentName() = 0;
};
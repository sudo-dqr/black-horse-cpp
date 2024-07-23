#pragma once
#include <iostream>
#include "Identity.h"
using namespace std;

class Teacher : public Identity {
    public :
        Teacher();
        Teacher(int id, string name, string pwd);
        void operate();
        void showAllOrder();
        void validOrder();
        int getId();
        string getName();
        string getPassword();

    private :
        int id;    
};

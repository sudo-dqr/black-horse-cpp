#pragma once
#include <iostream>
using namespace std;

class Identity {
    public :
        virtual void operate() = 0;

    protected :
        string name;
        string password;    
};

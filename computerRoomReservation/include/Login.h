#pragma once
#include <iostream>
#include <fstream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;

class Login {
    public :
        void static login(string fileName, int type);
};
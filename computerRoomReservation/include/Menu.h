#pragma once
#include <iostream>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h" 
using namespace std;

class Menu {
    public :
        void static showMainMenu();
        void static showStudentMenu(Student *student);
        void static showTeacherMenu(Teacher *teacher);
        void static showManagerMenu(Manager *manager);
};
#pragma once
#include <iostream>
using namespace std;

class Speaker {
    private :
        string name;
        double score[2];

    public :
        Speaker();
        Speaker(string name);
        ~Speaker();
        void setScore(int roundNum, double average);
        string getName();
        double getScore(int round);
};

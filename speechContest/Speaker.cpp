#include "Speaker.h"

Speaker::Speaker() {

}

Speaker::Speaker(string name) {
    this->name = name;
    this->score[0] = 0;
    this->score[1] = 0;
}

Speaker::~Speaker() {
    
}

void Speaker::setScore(int roundNum, double average) {
    this->score[roundNum - 1] = average;
}

string Speaker::getName() {
    return this->name;
}

double Speaker::getScore(int round) {
    return this->score[round - 1];
}

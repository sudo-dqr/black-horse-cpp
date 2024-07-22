#include <iostream>
#include <ctime>
#include "SpeechManager.h"
using namespace std;

int main() {
    srand((unsigned int)time(NULL));
    SpeechManager speechManager = SpeechManager();
    int operation;
    while (true) {
        speechManager.showMenu();
        cin >> operation;
        switch (operation)
        {
        case 1:
            speechManager.startSpeech();
            break;
        case 2:
            speechManager.showRecord();
            break;
        case 3:
            speechManager.clearRecord();
            break;
        case 0:
            speechManager.exitSystem();
            break;
        default:
            break;
        }
    }
}
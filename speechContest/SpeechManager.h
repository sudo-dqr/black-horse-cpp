#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include "Speaker.h"
using namespace std;

#define JUDGESNUM 10
#define FILENAME "speech.csv"

class SpeechManager {
    public :
        SpeechManager();
        ~SpeechManager();
        void showMenu();
        void exitSystem();
        void initSpeech();
        void createSpeaker();
        void startSpeech();
        void speechDraw();
        void speechContest();
        void showScore();
        void saveRecord();
        void loadRecord();
        void showRecord();
        void clearRecord();

    private :
        vector<int>  v1; // 12 比赛选手
        vector<int>  v2; // 6 第一轮晋级
        vector<int>  v3; // 3 第二轮晋级
        map<int, Speaker> speakers;
        int roundNumber;
        bool fileIsEmpty;
        map<int, vector<string>> record;
};
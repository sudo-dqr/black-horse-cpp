#include "SpeechManager.h"

SpeechManager::SpeechManager() {
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
}

SpeechManager::~SpeechManager() {

}

void SpeechManager::showMenu() {
    cout << "************************************" << endl;
    cout << "**********  欢迎参加演讲比赛 ********" << endl;
    cout << "**********  1. 开始演讲比赛 *********" << endl;
    cout << "**********  2. 查看往届记录 *********" << endl;
    cout << "**********  3. 清空比赛记录 *********" << endl;
    cout << "**********  0. 退出比赛程序 *********" << endl;
    cout << "************************************" << endl;
    cout << "请选择您的操作: " << endl;
}

void SpeechManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void SpeechManager::initSpeech() {
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->speakers.clear();
    this->roundNumber = 1;
    this->record.clear();
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "选手";
        name += nameSeed[i];
        Speaker speaker = Speaker(name);
        this->v1.push_back(i + 10001);
        this->speakers.insert(make_pair(i + 10001, speaker));
    }
}

void SpeechManager::startSpeech() {
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->roundNumber++;
    this->speechDraw();
    this->speechContest();
    this->showScore();
    this->saveRecord();
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
    cout << "本届比赛结束!" << endl;
}

void SpeechManager::speechDraw() {
    cout << "第 <<" << this->roundNumber << ">> 轮比赛选手正在抽签" << endl;
    cout << "----------------------" << endl;
    cout << "抽签后演讲顺序如下: " << endl;
    if (this->roundNumber == 1) {
        random_shuffle(this->v1.begin(), this->v1.end());
        for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++) {
            cout << *it << " ";
        }
    } else {
        random_shuffle(this->v2.begin(), this->v2.end());
        for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++) {
            cout << *it << " ";
        }
    }
    cout << endl;
    cout << "----------------------" << endl;
    //system("pause");
}

void SpeechManager::speechContest() {
    cout << "-----------第<<" << this->roundNumber << ">>轮比赛正式开始-----------" << endl;
    vector<int> competitors; 
    multimap<double, int, greater<double>> groupScore;
    int num = 0;
    if (this->roundNumber == 1) {
        competitors = this->v1;
    } else {
        competitors = this->v2;
    }
    for (vector<int>::iterator it = competitors.begin(); it != competitors.end(); it++) {
        num++;
        deque<double> scores;
        for (int i = 0; i < JUDGESNUM; i++) {
            double score = (rand() % 401 + 600) / 10.f;
            scores.push_back(score);
        }
        sort(scores.begin(), scores.end(), greater<double>());
        scores.pop_back(); 
        scores.pop_front();
        double sum = accumulate(scores.begin(), scores.end(), 0.f);
        double average = sum / (double)scores.size();
        this->speakers[*it].setScore(this->roundNumber, average);
        groupScore.insert(make_pair(average, *it));
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次: " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
                cout << "编号: " << it->second << " 姓名: " << this->speakers[it->second].getName() 
                << " 成绩: " << this->speakers[it->second].getScore(this->roundNumber) << endl;
            }
            int cnt = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && cnt < 3; it++) {
                if (this->roundNumber == 1) {
                    this->v2.push_back(it->second);
                } else {
                    this->v3.push_back(it->second);
                }
                cnt++;
            }
            groupScore.clear();
        }
    }
    cout << "-----------第<<" << this->roundNumber << ">>轮比赛结束-----------" << endl; 
    //system("pause");
}

void SpeechManager::showScore() {
    cout << "-----------第<<" << this->roundNumber << ">>轮晋级选手信息如下-----------" << endl;
    vector<int> competitors;
    if (this->roundNumber == 1) {
        competitors = this->v2;
    } else {
        competitors = this->v3;
    }
    for (vector<int>::iterator it = competitors.begin(); it != competitors.end(); it++) {
        cout << "选手编号: " << *it << " 姓名: " << this->speakers[*it].getName() 
        << " 得分: " << this->speakers[*it].getScore(this->roundNumber) << endl;
    }
    cout << endl;
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out|ios::app);
    for (vector<int>::iterator it = this->v3.begin(); it != v3.end(); it++) {
        ofs << *it << "," << this->speakers[*it].getScore(this->roundNumber) << ","; // .csv中用,分割数据
    }
    ofs << endl;
    ofs.close();
    cout << "记录已经保存" << endl;
    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false;
    ifs.putback(ch); //将读取的字符放回来
    string data;
    int cnt = 0;
    while (ifs >> data) { // 每次读一行
        vector<string> v;
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }
            string temp = data.substr(start, pos - start);
            v.push_back(temp);
            start = pos + 1;
        }
        this->record.insert(make_pair(cnt++, v));
    }
    ifs.close();
}

void SpeechManager::showRecord() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
        return;
    }
    for (int i = 0; i < this->record.size(); i++) {
        cout << "第" << i + 1 << "届比赛记录如下: " << endl;
        cout << "冠军编号: " << this->record[i][0] << " 得分: " << this->record[i][1] << endl;
        cout << "亚军编号: " << this->record[i][2] << " 得分: " << this->record[i][3] << endl;
        cout << "季军编号: " << this->record[i][4] << " 得分: " << this->record[i][5] << endl;
    }
}

void SpeechManager::clearRecord() {
    cout << "确认清空? (Y/N)" << endl;
    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'y') {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->loadRecord();
        cout << "清空成功" << endl;
    }
}
#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
using namespace std;

#define FILENAME "worker.txt"

class WorkerManager {
    public :
        int workerNum; 
        // 这里利用多态，使用父类指针指向子类对象，建立一个指针数组
        Worker **workerArray; 
        bool fileIsEmpty;
        WorkerManager();
        ~WorkerManager();
        void showMenu();
        void exitSystem();
        void addWorker();
        void save();
        int getWorkerNum();
        void initWorkers();
        void showWorkers();
        int isExist(int id);
        void deleteWorker();
        void modifyWorker();
        void findWorker();
        void sortWorker();
        void clearWorkers();
};


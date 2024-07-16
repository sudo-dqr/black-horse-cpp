#include <iostream>
#include "WorkerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

int main() {
    WorkerManager workerManager;
    int operation;
    while (true) {
        workerManager.showMenu();
        cin >> operation;
        switch (operation)
        {
        case 0:
            workerManager.exitSystem();
            break;
        case 1:
            workerManager.addWorker();
            break;
        case 2:
            workerManager.showWorkers();
            break;
        case 3:
            workerManager.deleteWorker();
            break;
        case 4:
            workerManager.modifyWorker();
            break;
        case 5:
            workerManager.findWorker();
            break;
        case 6:
            workerManager.sortWorker();
            break;
        case 7:
            workerManager.clearWorkers();
            break;                        
        default:
            break;
        }
    }
    return 0;
}
#include"WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

WorkerManager::WorkerManager() {
    // 1. 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        this->workerNum = 0;
        this->workerArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    // 2. 文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空" << endl;
        this->workerNum = 0;
        this->workerArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    // 3. 文件存在，数据不为空，先将文件中数据同步到程序中
    int num = this->getWorkerNum();
    cout << "职工人数为：" << num << endl;
    this->workerNum = num;
    this->workerArray = new Worker*[this->workerNum];
    this->initWorkers();
    this->fileIsEmpty = false;
}

int WorkerManager::getWorkerNum() {
    ifstream ifs(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }
    return num;
}

void WorkerManager::initWorkers() {
    ifstream ifs(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker = NULL;
        if (dId == 1) {
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {
            worker = new Manager(id, name, dId);
        } else {
            worker = new Boss(id, name, dId);
        }
        this->workerArray[index++] = worker;
    }
    ifs.close();
}

WorkerManager::~WorkerManager() {
    if (this->workerArray != NULL) {
        for (int i = 0; i < this->workerNum; i++) {
            if (this->workerArray[i] != NULL) {
                delete this->workerArray[i];
                this->workerArray[i] = NULL;
            }
        }
        delete[] this->workerArray;
    }
}

void WorkerManager::showMenu() {
    cout << "************************************" << endl;
    cout << "*****  欢迎使用职工管理系统！  ******" << endl;
    cout << "********  0.退出管理程序  **********" << endl;
    cout << "********  1.增加职工信息  **********" << endl;
    cout << "********  2.显示职工信息  **********" << endl;
    cout << "********  3.删除离职职工  **********" << endl;
    cout << "********  4.修改职工信息  **********" << endl;
    cout << "********  5.查找职工信息  **********" << endl;
    cout << "********  6.按照编号排序  **********" << endl;
    cout << "********  7.清空所有文档  **********" << endl;
    cout << "************************************" << endl;
    cout << "**********请输入您的选择：***********" << endl;
}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::addWorker() {
    cout << "请输入添加职工数量：" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        // 创建新数组
        int newSize = this->workerNum + addNum;
        Worker **newSpace = new Worker*[newSize];
        // 将原来空间下数据存放到新空间下
        if (this->workerArray != NULL) {
            for (int i = 0; i < this->workerNum; i++) {
                newSpace[i] = this->workerArray[i];
            }
        }
        // 添加新数据
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;
            while (true) {
                cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
                cin >> id;
                if (this->isExist(id) != -1) {
                    cout << "职工编号重复，请重新输入" << endl;
                } else {
                    break;
                }
            }
            cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
            cin >> name;
            cout << "请选择该职工岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            newSpace[this->workerNum + i] = worker;
        }
        delete[] this->workerArray;
        this->workerArray = newSpace;
        this->workerNum = newSize;
        cout << "成功添加" << addNum << "名新职工！" << endl;
        this->fileIsEmpty = false;
        this->save();
    } else {
        cout << "输入数据有误" << endl;
    }
    //system("pause");
    //system("cls");
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->workerNum; i++) {
        ofs << this->workerArray[i]->workerId << " "
            << this->workerArray[i]->workerName << " "
            << this->workerArray[i]->departmentId << endl;
    }
    ofs.close();
}

void WorkerManager::showWorkers() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        for (int i = 0; i < this->workerNum; i++) {
            this->workerArray[i]->showInfo();
        }
    }
}

int WorkerManager::isExist(int id) {
    int index = -1;
    for (int i = 0; i < this->workerNum; i++) {
        if (this->workerArray[i]->workerId == id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::deleteWorker() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        cout << "请输入想要删除的职工编号：" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->workerNum - 1; i++) {
                this->workerArray[i] = this->workerArray[i + 1];
            }
            this->workerNum--;
            this->save();
            cout << "删除成功" << endl;
        } else {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
}

void WorkerManager::modifyWorker() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        cout << "请输入想要修改的职工编号：" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            delete this->workerArray[index];
            int newId;
            string newName;
            int dSelect;
            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newId;
            cout << "请输入新姓名：" << endl;
            cin >> newName;
            cout << "请选择岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, 1);
                break;
            case 2:
                worker = new Manager(newId, newName, 2);
                break;
            case 3:
                worker = new Boss(newId, newName, 3);
                break;
            default:
                break;
            }
            this->workerArray[index] = worker;
            cout << "修改成功" << endl;
            this->save();
        } else {
            cout << "修改失败，未找到该职工" << endl;
        }
    }
}

void WorkerManager::findWorker() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按职工姓名查找" << endl;
        int select;
        cin >> select;
        if (select == 1) {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;
            int index = this->isExist(id);
            if (index != -1) {
                cout << "查找成功，职工信息如下：" << endl;
                this->workerArray[index]->showInfo();
            } else {
                cout << "未找到该职工" << endl;
            }
        } else if (select == 2) {
            string name;
            cout << "请输入查找的职工姓名：" << endl;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < this->workerNum; i++) {
                if (this->workerArray[i]->workerName == name) {
                    this->workerArray[i]->showInfo();
                    flag = true;
                }
            }
            if (!flag) {
                cout << "未找到该职工" << endl;
            }
        } else {
            cout << "输入有误" << endl;
        }
    }
}

void WorkerManager::sortWorker() {
    if (this->fileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
    } else {
        cout << "请选择排序方式：" << endl;
        cout << "1、按职工号升序" << endl;
        cout << "2、按职工号降序" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->workerNum; i++) {
            int minOrMax = i;
            for (int j = i + 1; j < this->workerNum; j++) {
                if (select == 1) {
                    if (this->workerArray[minOrMax]->workerId > this->workerArray[j]->workerId) {
                        minOrMax = j;
                    }
                } else {
                    if (this->workerArray[minOrMax]->workerId < this->workerArray[j]->workerId) {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax) {
                Worker *temp = this->workerArray[i];
                this->workerArray[i] = this->workerArray[minOrMax];
                this->workerArray[minOrMax] = temp;
            }
        }
        cout << "排序成功" << endl;
        this->save();
        this->showWorkers();
    }
}

void WorkerManager::clearWorkers() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->workerArray != NULL) {
            for (int i = 0; i < this->workerNum; i++) {
                if (this->workerArray[i] != NULL) {
                    delete this->workerArray[i];
                    this->workerArray[i] = NULL;
                }
            }
            this->workerNum = 0;
            delete[] this->workerArray;
            this->workerArray = NULL;
            this->fileIsEmpty = true;
        }
        cout << "清空成功" << endl;
    }
}

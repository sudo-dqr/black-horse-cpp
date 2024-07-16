#include "Manager.h"

Manager::Manager(int id, string name, int dId) {
    this->workerId = id;
    this->workerName = name;
    this->departmentId = dId;
}

void Manager::showInfo() {
    cout << "职工编号：" << this->workerId
         << "\t职工姓名: " << this->workerName
         << "\t岗位: " << this->getDepartmentName()
         << "\t岗位职责: 完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDepartmentName() {
    return string("经理");
}
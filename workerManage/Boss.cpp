#include "Boss.h"

Boss::Boss(int id, string name, int dId) {
    this->workerId = id;
    this->workerName = name;
    this->departmentId = dId;
}

void Boss::showInfo() {
    cout << "职工编号：" << this->workerId
         << "\t职工姓名: " << this->workerName
         << "\t岗位: " << this->getDepartmentName()
         << "\t岗位职责: 管理公司所有事务" << endl;
}

string Boss::getDepartmentName() {
    return string("老板");
}
#include "Employee.h"

Employee::Employee(int id, string name, int dId) {
    this->workerId = id;
    this->workerName = name;
    this->departmentId = dId;
}

void Employee::showInfo() {
    cout << "职工编号：" << this->workerId
         << "\t职工姓名: " << this->workerName
         << "\t岗位: " << this->getDepartmentName()
         << "\t岗位职责: 完成经理交给的任务" << endl;
}

string Employee::getDepartmentName() {
    return string("员工");
}

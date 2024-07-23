#include "../include/Teacher.h"
#include "../include/Menu.h"
#include "../include/OrderFile.h"
#include <vector>

Teacher::Teacher() {

}

Teacher::Teacher(int id, string name, string pwd) {
    this->id = id;
    this->name = name;
    this->password = pwd;
}

void Teacher::operate() {
    while (true) {
        Menu().showTeacherMenu(this);
        int select = 0;
        cin >> select;
        if (select == 1) {
            this->showAllOrder();
        } else if (select == 2) {
            this->validOrder();
        } else {
            cout << "注销成功" << endl;
            delete this;
            break;
        }
    }
}

void Teacher::showAllOrder() {
    OrderFile of;
    if (of.getSize() == 0) {
        cout << "无预约记录" << endl;
        return;
    }
    map<int, map<string, string>> orderData = of.getOrderData();
    for (int i = 0; i < of.getSize(); i++) {
        cout << i + 1 << ". ";
        cout << "预约日期: " << orderData[i]["date"];
        cout << " 时段: " << (orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号: " << orderData[i]["stuId"];
        cout << " 姓名: " << orderData[i]["stuName"];
        cout << " 机房: " << orderData[i]["roomId"];
        string status = " 状态: ";
        if (orderData[i]["status"] == "1") {
            status += "审核中";
        } else if (orderData[i]["status"] == "2") {
            status += "预约成功";
        } else if (orderData[i]["status"] == "-1") {
            status += "审核不通过";
        } else {
            status += "预约取消";
        }
        cout << status << endl;
    }
}

void Teacher::validOrder() {
    OrderFile of;
    if (of.getSize() == 0) {
        cout << "无预约记录" << endl;
        return;
    }
    cout << "待审核的预约记录如下" << endl;
    vector<int> v;
    int index = 1;
    for (int i = 0; i < of.getSize(); i++) {
        if (of.getOrderData()[i]["status"] == "1") {
            v.push_back(i);
            cout << index++ << ". ";
            cout << "预约日期: " << of.getOrderData()[i]["date"];
            cout << " 时段: " << (of.getOrderData()[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 学号: " << of.getOrderData()[i]["stuId"];
            cout << " 姓名: " << of.getOrderData()[i]["stuName"];
            cout << " 机房: " << of.getOrderData()[i]["roomId"];
            cout << endl;
        }
    }
    cout << "请输入审核的预约记录, 输入0返回" << endl;
    int select = 0;
    int ret = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select != 0) {
                cout << "1. 通过" << endl;
                cout << "2. 不通过" << endl;
                cin >> ret;
                if (ret == 1) {
                    of.getOrderData()[v[select - 1]]["status"] = "2";
                } else {
                    of.getOrderData()[v[select - 1]]["status"] = "-1";
                }
                of.updateOrder();
                cout << "审核成功" << endl;
            }
            break;
        } else {
            cout << "输入有误, 请重新输入" << endl;
        }
    }
}

int Teacher::getId() {
    return this->id;
}

string Teacher::getName() {
    return this->name;
}

string Teacher::getPassword() {
    return this->password;
}